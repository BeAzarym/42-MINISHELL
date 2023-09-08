/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 10:19:32 by angassin          #+#    #+#             */
/*   Updated: 2023/09/08 17:01:49 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/execute.h"

/*
	Displays the "error_msg" followed by a ’\n’ on the standard error
	and exits
*/
void	error_exit(char *error_msg)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	perror(error_msg);
	exit(EXIT_FAILURE);
}

// ft_putnbr_fd(fd_src, 2);
// ft_putstr_fd("\n", 2);
void	duplicate(int fd_src, int fd_dest, char *error)
{
	if (dup2(fd_src, fd_dest) == -1)
	{
		close(fd_src);
		error_exit(error);
	}
	close(fd_src);
}

void	pipe_init(int fd_pipes[2][2])
{
	fd_pipes[0][0] = -1;
	fd_pipes[0][1] = -1;
	fd_pipes[1][0] = -1;
	fd_pipes[1][1] = -1;
}

/*
	Plugs either the infile or the entry of previous pipe to the stdin 
	and the exit of the pipe to the stdout
	Close all the unused fds'
	// ft_putnbr_fd(fd_pipes[1][1], 2);
	// ft_putchar_fd('\n', 2);
*/
void	pipe_branching(t_cmd *cmd, int fd_pipes[2][2])
{
	if (cmd->fdin != STDIN_FILENO)
	{
		printf("fdin in pipe_execute : %d\n", cmd->fdin);
		close(fd_pipes[0][0]);
		close(fd_pipes[0][1]);
		duplicate(cmd->fdin, STDIN_FILENO, "could not read from infile");
		close(cmd->fdin);
	}
	else if (fd_pipes[0][0] != CLOSED)
	{
		printf("redirecting pipe[0] to stdin\n");
		close(fd_pipes[0][1]);
		duplicate(fd_pipes[0][0], STDIN_FILENO, "could not read from pipe[0]");
		close(fd_pipes[0][0]);
	}
	close(fd_pipes[1][0]);
	duplicate(fd_pipes[1][1], STDOUT_FILENO, "could not write to pipe[1]");
	close(fd_pipes[1][1]);
}

/*
	Close the fdin except standard in.
	Close the open pipes'fds and reinitialize them. 
*/
void	pipe_closing(t_cmd *cmd, int fd_pipes[2][2])
{
	if (cmd->fdin != STDIN_FILENO)
		close(cmd->fdin);
	if (fd_pipes[0][0] != CLOSED)
	{
		close(fd_pipes[0][0]);
		fd_pipes[0][0] = -1;
	}
	close(fd_pipes[1][1]);
	fd_pipes[1][1] = -1;
}
