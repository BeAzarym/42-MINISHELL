/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 23:40:50 by angassin          #+#    #+#             */
/*   Updated: 2023/10/05 12:32:55 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/signals.h"


//ctrl-c in main
void	set_signals(int handler)
{
	struct sigaction	sa;

	if (handler == MAIN_H)
	{
		sa.sa_handler = &sigint_in_main_handler;
		sigaction(SIGINT, &sa, NULL);
		signal(SIGQUIT, SIG_IGN);
	}
	if (handler == CHILD_H)
	{
		sa.sa_handler = &child_process_handler;
		sigaction(SIGINT, &sa, NULL);
		sigaction(SIGQUIT, &sa, NULL);
	}
	if (handler == PARENT_H)
	{
		sa.sa_handler = &parent_process_handler;
		sigaction(SIGINT, &sa, NULL);
		sigaction(SIGQUIT, &sa, NULL);
	}
}

void	set_heredoc_signals(int handler)
{
	struct sigaction	sa;

	if (handler == CHILD_H)
	{
		sa.sa_handler = &heredoc_child_process_handler;
		sigaction(SIGINT, &sa, NULL);
		signal(SIGQUIT, SIG_IGN);
	}
}
/* 
	Ignore "Ctrl-c"
	Ignore "Ctrl-\"
*/
// void	ignore_shell_signal(void)
// {
// 	set_signal_handler(SIGINT, 0, SIG_IGN);
// 	set_signal_handler(SIGQUIT, 0, SIG_IGN);
// 	g_stat.signalset = true;
// }

// ctrl-c in child
// void	set_sigint_in_child(int signal)
// {
// 	if (signal == SIGINT)
// 		set_signal_handler(SIGINT, 0, NULL);
// }


