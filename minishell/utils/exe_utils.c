/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 10:19:32 by angassin          #+#    #+#             */
/*   Updated: 2023/08/31 17:13:15 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/execute.h"

/*
	Displays "error_msg" followed by a ’\n’ on the standard error
	and exits
*/
void	error_exit(char *error_msg)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	perror(error_msg);
	exit(EXIT_FAILURE);
}

void	duplicate(int fd_src, int fd_dest, char *error)
{
	if (dup2(fd_src, fd_dest) == -1)
	{
		close(fd_src);
		error_exit(error);
	}
	close(fd_src);
}
