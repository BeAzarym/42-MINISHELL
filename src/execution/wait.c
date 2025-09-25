/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 19:18:15 by angassin          #+#    #+#             */
/*   Updated: 2023/10/09 15:29:38 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execute.h"

static void	wait_if_signaled(void);

/*
	Waits for the parent process to finish and returns its status
	Loops over all the child processes and waits for them to finish
	It's important that the pointer on int of the waitpid function, waiting 
	the child processes, is NULL so only the parent process status is returned
*/
void	processes_wait(const pid_t pid, int size)
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
