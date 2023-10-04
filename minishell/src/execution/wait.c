/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 19:18:15 by angassin          #+#    #+#             */
/*   Updated: 2023/10/04 13:27:42 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execute.h"

static void	wait_if_signaled(void);

int	processes_wait(const pid_t pid, int size)
{
	int	i;

	waitpid(pid, &g_stat.status, 0);
	wait_if_signaled();
	i = 0;
	while (i < size - 1)
	{
		waitpid(-1, &g_stat.status, 0);
		wait_if_signaled();
		++i;
	}
	return (g_stat.status);
}

static void	wait_if_signaled(void)
{
	if (WIFSIGNALED(g_stat.status))
	{
		if (WTERMSIG(g_stat.status) == SIGINT)
			g_stat.status = 130;
		else if (WTERMSIG(g_stat.status) == SIGQUIT)
			g_stat.status = 131;
		else
			g_stat.status = 128 + WTERMSIG(g_stat.status);
	}
	else
		g_stat.status = WEXITSTATUS(g_stat.status);
}
