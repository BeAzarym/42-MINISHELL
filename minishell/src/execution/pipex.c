/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2023/08/30 13:41:17 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execute.h"

static void	read_stdin(const char *limiter, int fd);

/* Creates a child process to prompt the user */
void	heredoc(const char *limiter)
{
	int			fd[2];
	int			pid;

	if (pipe(fd) == -1)
		error_exit("could not create pipe");
	pid = fork();
	if (pid == -1)
		error_exit("could not create process");
	if (pid == CHILD)
	{
		close(fd[0]);
		read_stdin(limiter, fd[1]);
		close(fd[1]);
	}
	close(fd[1]);
	duplicate(fd[0], STDIN_FILENO, "could not read from the pipe");
	close(fd[0]);
	waitpid(pid, NULL, 0);
}

static void	read_stdin(const char *limiter, int fd)
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
	Parent process : reads the output of the child from the pipe.
	The child process has it's own copy of the parent's file's decriptors.
	printf("here\n");
*/
void	create_process(t_cmd *cmd, char **envp, int fd[2])
{
	int	pid;

	if (pipe(fd) == -1)
		error_exit("could not create pipe");
	pid = fork();
	if (pid == -1)
		error_exit("could not create process");
	if (pid == CHILD)
	{
		close(fd[0]);
		duplicate(fd[1], STDOUT_FILENO, "could not write to the pipe");
		close(fd[1]);
		// ft_putstr_fd("in pipe, command : ", 2);
		// ft_putstr_fd(cmd->cmd[0], 2);
		// ft_putstr_fd("\n", 2);
		execute(cmd, envp);
	}
	close(fd[1]);
	ft_putstr_fd("in parent (create process)\n", 2);
}

/*
	Executes the last command in a child process and wait for all
	the child processes to end in the parent.
	Returns the exit status of the last command.
*/
int	lastcmd_process(t_cmd *cmd, char **envp, int arg_counter, int fdout, int fd_pipe[2])
{
	printf("lastcmd : %s\n", cmd->cmd[0]);
	int	pid;
	int	status;
	int	exit_status;

	pid = fork();
	if (pid == -1)
		error_exit("could not create lastcmd process");
	if (pid == CHILD)
	{
		if (fdout != STDOUT_FILENO)
		{
			printf("fdout in lastcmd child: %d\n", fdout);
			duplicate(fdout, STDOUT_FILENO, "duplication of the outfile failed");
			close(fdout);
		}
		if (fd_pipe[0] != -1) 
		{
			duplicate(fd_pipe[0], STDIN_FILENO, "could not read from the pipe");
			close(fd_pipe[0]);
		}
		execute(cmd, envp);
	}
	if (fd_pipe[0] != -1)
		close(fd_pipe[0]);
	if (fdout != STDOUT_FILENO)
		close(fdout);
	waitpid(pid, &status, 0);
	arg_counter++;
	(void)arg_counter;
	exit_status = WEXITSTATUS(status);
	// while (arg_counter <= argc - 2)
	// {
		waitpid(-1, &status, 0);
	// 	arg_counter++;
	// }
	return (exit_status);
}

