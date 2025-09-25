/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:02:32 by angassin          #+#    #+#             */
/*   Updated: 2023/10/07 19:18:35 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/signals.h"

// static void	set_signal(int signal, int flags, void (*handler)(int))
// {
// 	struct sigaction	sa;

// 	sa.sa = handler;
// 	sa.sa_flags = flags;
// 	sigemptyset(&sa.sa_mask);
// 	sigaction(signal, &sa, NULL);
// }

// printf("g_statset : %d\n", g_status);
void	sigint_in_main(int signal)
{
	if (signal == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_status = 1;
	}
}

void	child_process_signal(int signal)
{
	if (signal == SIGINT)
		g_status = 130;
	else if (signal == SIGQUIT)
		g_status = 131;
	exit(g_status);
}

// ft_putstr_fd("Quit: 3\n", 2);
void	parent_process_signal(int signal)
{
	if (signal == SIGINT)
		g_status = 130;
	else if (signal == SIGQUIT)
		g_status = 131;
}

void	heredoc_child_process_signal(int signal)
{
	if (signal == SIGINT)
	{
		g_status = 1;
		printf("\n");
		exit (g_status);
	}
}

void	heredoc_parent_process_signal(int signal)
{
	if (signal == SIGINT)
		g_status = 1;
}
