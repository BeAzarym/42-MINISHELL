/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 19:18:15 by angassin          #+#    #+#             */
/*   Updated: 2023/10/02 17:38:56 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execute.h"

static void	wait_if_signaled(void);

int	processes_wait(const pid_t pid, int size)
{
	int	i;

	waitpid(pid, &g_signal.status, 0);
	wait_if_signaled();
	i = 0;
	while (i < size - 1)
	{
		waitpid(-1, &g_signal.status, 0);
		wait_if_signaled();
		++i;
	}
	return (g_signal.status);
}

static void	wait_if_signaled(void)
{
	if (WIFSIGNALED(g_signal.status))
	{
		if (WTERMSIG(g_signal.status) == SIGINT)
			g_signal.status = 130;
		else if (WTERMSIG(g_signal.status) == SIGQUIT)
			g_signal.status = 131;
		else
			g_signal.status = 128 + WTERMSIG(g_signal.status);
	}
	else
		g_signal.status = WEXITSTATUS(g_signal.status);
}
