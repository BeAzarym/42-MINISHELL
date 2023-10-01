/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 19:18:15 by angassin          #+#    #+#             */
/*   Updated: 2023/10/01 22:58:06 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execute.h"

int	processes_wait(const pid_t pid, int size)
{
	int	status;
	int	exit_status;
	int	i;

	waitpid(pid, &status, 0);
	exit_status = WEXITSTATUS(status);
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == 1)
			exit_status = 130;
		else if (WTERMSIG(status) == SIGQUIT)
			exit_status = 131;
		else
			exit_status = 128 + WTERMSIG(status);
	}
	i = 1;
	while (i < size)
	{
		waitpid(-1, &status, 0);
		++i;
	}
	return (exit_status);
}
