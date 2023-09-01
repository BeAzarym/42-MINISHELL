/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 10:19:32 by angassin          #+#    #+#             */
/*   Updated: 2023/09/01 18:36:41 by angassin         ###   ########.fr       */
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

void	pipe_branching(t_cmd *cmd, int fd_pipes[2][2])
{
	if (cmd->fdin != STDIN_FILENO)
	{
		printf("fdin in create_process : %d\n", cmd->fdin);
		close(fd_pipes[0][0]);
		close(fd_pipes[0][1]);
		duplicate(cmd->fdin, STDIN_FILENO,
			"could not read from infile");
		close(cmd->fdin);
	}
	if (fd_pipes[0][0] != CLOSED)
	{
		close(fd_pipes[0][1]);
		duplicate(fd_pipes[0][0], STDIN_FILENO,	"could not read from pipe");
		close(fd_pipes[0][0]);
	}
	close(fd_pipes[1][0]);
	ft_putnbr_fd(fd_pipes[1][1], 2);
	duplicate(fd_pipes[1][1], STDOUT_FILENO, "could not write to the pipe");
	close(fd_pipes[1][1]);
}
