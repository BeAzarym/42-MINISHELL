/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2023/09/04 15:38:06 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execute.h"

/*
	Creates a child process to prompt the user
	printf("in heredoc child\n"); 
*/
// todo : recuperer content input user
int	heredoc(t_cmd_lst *cmd_lst, int fd_pipes[2][2])
{
	int	pid;
	int	status;
	int	exit_status;

	cmd_lst->head->limiter = cmd_lst->head->redir_in->head->file;
	if (pipe(fd_pipes[1]) == CLOSED)
		error_exit("could not create pipe");
	pid = fork();
	if (pid == -1)
		error_exit("could not create process");
	if (pid == CHILD)
		pipe_branching(cmd_lst->head, fd_pipes);
	pipe_closing(cmd_lst->head, fd_pipes);
	waitpid(pid, &status, 0);
	exit_status = WEXITSTATUS(status);
	return (exit_status);
}

//printf("\nline : %s in read_stdin\n", line);
//printf("exit read_stdin\n");
void	read_stdin(const char *limiter, int fd)
{
	char	*line;

	while (1)
	{
		ft_putstr_fd("> ", STDOUT_FILENO);
		line = get_next_line(STDIN_FILENO);

		if (line == NULL)
			exit(127);
		if (ft_strncmp(limiter, line, ft_strlen(limiter)) == OK
			&& ft_strlen(limiter) == (ft_strlen(line) - 1))
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		ft_putstr_fd(line, fd);
		free(line);
	}
	free(line);
}

/*
	Creates a child process : send to the pipe the output of the execution
	of the command passed in argument.
	printf("here\n");
*/
void	create_process(t_cmd *cmd, char **envp, int fd_pipes[2][2])
{
	int	pid;

	if (pipe(fd_pipes[1]) == CLOSED)
		error_exit("could not create pipe");
	printf("previous: [%d; %d], next: [%d; %d]\n",
		fd_pipes[0][0], fd_pipes[0][1], fd_pipes[1][0], fd_pipes[1][1]);
	pid = fork();
	if (pid == -1)
		error_exit("could not create process");
	if (pid == CHILD)
	{
		pipe_branching(cmd, fd_pipes);
		ft_putstr_fd("in pipe, command : ", 2);
		ft_putstr_fd(cmd->cmd[0], 2);
		ft_putstr_fd("\n", 2);
		execute(cmd, envp);
	}
	pipe_closing(cmd, fd_pipes);
	ft_putstr_fd("in parent (create process)\n", 2);
}

/*
	Executes the last command in a child process and wait for all
	the child processes to end in the parent.
	Returns the exit status of the last command.
*/
int	lastcmd_process(t_cmd_lst *cmd_table, char **envp, int fd_pipe[2])
{
	int	pid;
	int	status;
	int	exit_status;
	int	i;

	printf("lastcmd : %s\n", cmd_table->head->cmd[0]);
	printf("previous: [%d; %d]\n", fd_pipe[0], fd_pipe[1]);
	pid = fork();
	if (pid == -1)
		error_exit("could not create lastcmd process");
	if (pid == CHILD)
	{
		if (cmd_table->head->fdout != STDOUT_FILENO)
		{
			printf("fdout in lastcmd child: %d\n", cmd_table->head->fdout);
			duplicate(cmd_table->head->fdout, STDOUT_FILENO,
				"duplication of the outfile failed");
			close(cmd_table->head->fdout);
		}
		if (cmd_table->head->fdin != STDIN_FILENO)
		{
			if (fd_pipe[0] != CLOSED)
				close(fd_pipe[0]);
			duplicate(cmd_table->head->fdin, STDIN_FILENO,
				"could not read from infile");
			close(cmd_table->head->fdin);
		}
		else if (fd_pipe[0] != CLOSED)
		{
			// printf("fd_pipe[0] in lastcmd child: %d\n", fd_pipe[0]);
			duplicate(fd_pipe[0], STDIN_FILENO, "could not read from the pipe");
			close(fd_pipe[0]);
		}
		execute(cmd_table->head, envp);
	}
	if (fd_pipe[0] != CLOSED)
	{
		close(fd_pipe[0]);
		// printf("close fd_pipe[0] in parent (lastcmd)\n");
	}
	if (cmd_table->head->fdout != STDOUT_FILENO)
	{
		close(cmd_table->head->fdout);
		// printf("close fdout in parent\n");
	}
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

