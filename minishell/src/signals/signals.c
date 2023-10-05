/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 23:40:50 by angassin          #+#    #+#             */
/*   Updated: 2023/10/05 14:55:16 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/signals.h"

/* 
	set ctrl-c and ctrl-\
*/
void	set_signals(int handler)
{
	struct sigaction	sa;
	struct termios		tm;

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
	tcgetattr(0, &tm);
	tm.c_lflag &= ~ECHOCTL;
	tcsetattr(0, TCSANOW, &tm);
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
	if (handler == PARENT_H)
	{
		sa.sa_handler = &heredoc_parent_process_handler;
		sigaction(SIGINT, &sa, NULL);
		signal(SIGQUIT, SIG_IGN);
	}
}
