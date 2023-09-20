/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:02:59 by angassin          #+#    #+#             */
/*   Updated: 2023/09/20 09:48:41 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execute.h"

static	void	lastcmd_dup(t_cmd *cmd_node, int fd_pipes[2]);
static int	processes_wait(t_cmd_lst *cmd_table, const pid_t pid);

/*
	Creates a child process : send to the pipe the output of the execution
	of the command passed in argument.
	Close the pipes and used fds in parent process.
	printf("here\n");
	printf("previous: [%d; %d], next: [%d; %d]\n",
		fd_pipes[0][0], fd_pipes[0][1], fd_pipes[1][0], fd_pipes[1][1]);
	printf("fd_pipe[0] in lastcmd child: %d\n", fd_pipe[0]);
	ft_putstr_fd("in pipe, command : ", 2);
	ft_putstr_fd(cmd->cmd[0], 2);
	ft_putstr_fd("\n", 2);
*/
void	pipe_execute(t_cmd *cmd, char **envp, int fd_pipes[2][2])
{
	int	pid;

	if (pipe(fd_pipes[1]) == CLOSED)
		error_exit("could not create pipe");
	pid = fork();
	if (pid == -1)
		error_exit("could not create process");
	if (pid == CHILD)
	{
		pipe_branching(cmd, fd_pipes);
		execute(cmd, envp);
	}
	pipe_closing(cmd, fd_pipes);
	ft_putstr_fd("in parent (pipe execute)\n", 2);
}

/*
	Executes the last command in a child process and wait for all
	the child processes to end in the parent.
	Returns the exit status of the last command.
	printf("previous: [%d; %d]\n", fd_pipe[0], fd_pipe[1]);
	printf("fdout in lastcmd child: %d\n", cmd_table->head->fdout);
	printf("fdin in lastcmd : %d\n", cmd_table->head->fdin);
	printf("infile in lastcmd : %s\n", cmd_table->head->infile);
	printf("close fd_pipe[0] in lastcmd\n");
	printf("close fdout in lastcmd\n");
	// printf("lastcmd : %s\n", cmd_table->head->cmd[0]);
*/
int	lastcmd_process(t_cmd_lst *cmd_table, char **envp, int fd_pipe[2])
{
	pid_t	pid;
	int		exit_status;

	pid = fork();
	if (pid == -1)
		error_exit("could not create lastcmd process");
	if (pid == CHILD)
	{
		lastcmd_dup(cmd_table->head, fd_pipe);
		execute(cmd_table->head, envp);
	}
	if (fd_pipe[0] != CLOSED)
		close(fd_pipe[0]);
	if (cmd_table->head->fdout != STDOUT_FILENO)
		close(cmd_table->head->fdout);
	exit_status = processes_wait(cmd_table, pid);
	return (exit_status);
}

static	void	lastcmd_dup(t_cmd *cmd_node, int fd_pipe[2])
{
	if (cmd_node->fdout != STDOUT_FILENO)
	{
		duplicate(cmd_node->fdout, STDOUT_FILENO,
			"duplication of the outfile failed");
		close(cmd_node->fdout);
	}
	if (cmd_node->fdin != STDIN_FILENO)
	{
		if (fd_pipe[0] != CLOSED)
			close(fd_pipe[0]);
		duplicate(cmd_node->fdin, STDIN_FILENO,
			"could not read from infile");
		close(cmd_node->fdin);
	}
	else if (fd_pipe[0] != CLOSED)
	{
		duplicate(fd_pipe[0], STDIN_FILENO, "could not read from the pipe");
		close(fd_pipe[0]);
	}
}

static int	processes_wait(t_cmd_lst *cmd_table, const pid_t pid)
{
	int	status;
	int	exit_status;
	int	i;

	waitpid(pid, &status, 0);
	exit_status = WEXITSTATUS(status);
	i = 1;
	while (i < cmd_table->size)
	{
		waitpid(-1, &status, 0);
		++i;
	}
	return (exit_status);
}
