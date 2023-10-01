/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 19:18:15 by angassin          #+#    #+#             */
/*   Updated: 2023/10/02 11:49:32 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execute.h"

static int	wait_if_signaled(int status, int exit_status);

int	processes_wait(const pid_t pid, int size)
{
	int	status;
	int	exit_status;
	int	i;

	exit_status = 0;
	i = 0;
	while (i < size - 1)
	{
		waitpid(-1, &status, 0);
		exit_status = wait_if_signaled(status, exit_status);
		++i;
	}
	waitpid(pid, &status, 0);
	exit_status = wait_if_signaled(status, exit_status);
	return (exit_status);
}

static int	wait_if_signaled(int status, int exit_status)
{
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == SIGINT)
			exit_status = 130;
		else if (WTERMSIG(status) == SIGQUIT)
			exit_status = 131;
		else
			exit_status = 128 + WTERMSIG(status);
	}
	else
		exit_status = WEXITSTATUS(status);
	return (exit_status);
}
