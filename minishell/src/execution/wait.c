/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 19:18:15 by angassin          #+#    #+#             */
/*   Updated: 2023/10/05 16:54:48 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execute.h"

static void	wait_if_signaled(void);

int	processes_wait(const pid_t pid, int size)
{
	int	i;

	waitpid(pid, &g_status, 0);
	wait_if_signaled();
	i = 0;
	while (i < size - 1)
	{
		waitpid(-1, NULL, 0);
		++i;
	}
	return (g_status);
}

static void	wait_if_signaled(void)
{
	if (WIFSIGNALED(g_status))
	{
		if (WTERMSIG(g_status) == SIGINT)
			g_status = 130;
		else if (WTERMSIG(g_status) == SIGQUIT)
			g_status = 131;
		else
			g_status = 128 + WTERMSIG(g_status);
	}
	else
		g_status = WEXITSTATUS(g_status);
}
