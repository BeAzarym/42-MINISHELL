/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 23:40:50 by angassin          #+#    #+#             */
/*   Updated: 2023/10/06 16:02:45 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/signals.h"

/* 
	set ctrl-c and ctrl-\
*/
void	set_signals(int handler)
{
	struct termios		tm;

	if (handler == MAIN_H)
	{
		signal(SIGINT, sigint_in_main);
		signal(SIGQUIT, SIG_IGN);
	}
	if (handler == CHILD_H)
	{
		signal(SIGINT, child_process_signal);
		signal(SIGQUIT, child_process_signal);
	}
	if (handler == PARENT_H)
	{
		signal(SIGINT, parent_process_signal);
		signal(SIGQUIT, parent_process_signal);
	}
	tcgetattr(0, &tm);
	tm.c_lflag &= ~ECHOCTL;
	tcsetattr(0, TCSANOW, &tm);
}

void	set_heredoc_signals(int handler)
{
	if (handler == CHILD_H)
	{
		signal(SIGINT, heredoc_child_process_signal);
		signal(SIGQUIT, SIG_IGN);
	}
	if (handler == PARENT_H)
	{
		signal(SIGINT, heredoc_parent_process_signal);
		signal(SIGQUIT, SIG_IGN);
	}
}
