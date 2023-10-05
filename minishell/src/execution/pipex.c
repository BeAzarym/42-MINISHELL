/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:02:59 by angassin          #+#    #+#             */
/*   Updated: 2023/10/05 18:44:17 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execute.h"

static void	lastcmd_builtin_dup(t_cmd *cmd_table, int fd_cpy[2],
				int fd_pipe[2]);
static int	lastcmd_process_exe(t_cmd *cmd_table, int fd_pipe[2],
				int cmd_lst_size, char **envp);

/*
	Creates a child process : send to the pipe the output of the execution
	of the command passed in argument.
	Closes the pipes and used fds in parent process.
	printf("here\n");
	printf("previous: [%d; %d], next: [%d; %d]\n",
		fd_pipes[0][0], fd_pipes[0][1], fd_pipes[1][0], fd_pipes[1][1]);
	ft_putstr_fd("in pipe, command : ", 2);
	ft_putstr_fd(cmd->cmd[0], 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("in parent (pipe execute)\n", 2);
*/
void	pipe_execute(t_cmd *cmd, t_env_lst *env_lst, int fd_pipes[2][2])
{
	int		pid;
	char	**envp;

	envp = convert_env_to_exec(env_lst);
	if (pipe(fd_pipes[1]) == CLOSED)
		error_exit("could not create pipe");
	pid = fork();
	if (pid == -1)
		error_exit("could not create process");
	if (pid == CHILD)
	{
		pipe_plug(cmd, fd_pipes);
		if (is_builtin(cmd->cmd[0]))
		{
			builtin_execute(env_lst, cmd);
			exit(EXIT_SUCCESS);
		}
		else
			execute(cmd, envp);
	}
	ft_array_clear(envp);
	pipe_closing(cmd, fd_pipes);
}

/*
	Executes the last command in a child process and wait for all
	the child processes to end in the parent.
	Returns the exit status of the last command.
	printf("previous: [%d; %d]\n", fd_pipe[0], fd_pipe[1]);
	printf("fdout in lastcmd child: %d\n", cmd_table->fdout);
	printf("fdin in lastcmd : %d\n", cmd_table->fdin);
	printf("infile in lastcmd : %s\n", cmd_table->infile);
	printf("close fd_pipe[0] in lastcmd\n");
	printf("close fdout in lastcmd\n");
	printf("lastcmd : %s\n", cmd_table->cmd[0]);
	printf("exit_status : %d", exit_status);
	printf("fd_pipe[0] in lastcmd child: %d\n", fd_pipe[0]);
*/
int	lastcmd_process(t_cmd *cmd_table, t_env_lst *env_lst, int fd_pipe[2],
		int cmd_lst_size)
{
	char	**envp;
	int		fd_cpy[2];

	envp = convert_env_to_exec(env_lst);
	fd_cpy[0] = -1;
	fd_cpy[1] = -1;
	if (is_builtin(cmd_table->cmd[0]))
	{
		lastcmd_builtin_dup(cmd_table, fd_cpy, fd_pipe);
		g_status = (builtin_execute(env_lst, cmd_table));
	}
	else
		g_status = lastcmd_process_exe(cmd_table, fd_pipe, cmd_lst_size,
				envp);
	if (fd_pipe[0] != CLOSED)
		close(fd_pipe[0]);
	if (cmd_table->fdout != STDOUT_FILENO)
		close(cmd_table->fdout);
	ft_array_clear(envp);
	if (fd_cpy[1] != CLOSED)
		duplicate(fd_cpy[1], STDOUT_FILENO, "could not read from fdout_cpy");
	if (fd_cpy[0] != CLOSED)
		duplicate(fd_cpy[0], STDIN_FILENO, "could not read from fdin_cpy");
	return (g_status); 
}

static void	lastcmd_builtin_dup(t_cmd *cmd_table, int fd_cpy[2], int fd_pipe[2])
{
	if (cmd_table->fdout != STDOUT_FILENO)
		fd_cpy[1] = dup(STDOUT_FILENO);
	if (cmd_table->fdout != STDIN_FILENO)
		fd_cpy[0] = dup(STDIN_FILENO);
	lastcmd_dup(cmd_table, fd_pipe);
}

static int	lastcmd_process_exe(t_cmd *cmd_table, int fd_pipe[2],
		int cmd_lst_size, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		error_exit("could not create lastcmd process");
	if (pid == CHILD)
	{
		lastcmd_dup(cmd_table, fd_pipe);
		execute(cmd_table, envp);
	}
	if (fd_pipe[0] != CLOSED)
	{
		close(fd_pipe[0]);
		fd_pipe[0] = CLOSED;
	}
	return (g_status = processes_wait(pid, cmd_lst_size));
}

void	lastcmd_dup(t_cmd *cmd_node, int fd_pipe[2])
{
	if (cmd_node->fdout != STDOUT_FILENO)
	{
		duplicate(cmd_node->fdout, STDOUT_FILENO,
			"duplication of the outfile failed");
		close(cmd_node->fdout);
		cmd_node->fdout = STDOUT_FILENO;
	}
	if (cmd_node->fdin != STDIN_FILENO)
	{
		if (fd_pipe[0] != CLOSED)
			close(fd_pipe[0]);
		duplicate(cmd_node->fdin, STDIN_FILENO, "could not read from infile");
		close(cmd_node->fdin);
	}
	else if (fd_pipe[0] != CLOSED)
	{
		duplicate(fd_pipe[0], STDIN_FILENO, "could not read from the pipe");
		close(fd_pipe[0]);
	}
}
