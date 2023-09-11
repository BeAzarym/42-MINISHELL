/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 23:40:50 by angassin          #+#    #+#             */
/*   Updated: 2023/09/11 15:48:41 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execute.h"

void	set_signal_handler(int signal, int flags, void (*handler)(int))
{
	struct sigaction	sa;

	sa.sa_handler = handler;
	sa.sa_flags = flags;
	sigemptyset(&sa.sa_mask);
	sigaction(signal, &sa, NULL);
}

/* 
	Ignore "Ctrl-c"
	Ignore "Ctrl-\"
*/
void	ignore_shell_signal(void)
{
	set_signal_handler(SIGINT, 0, SIG_IGN);
	set_signal_handler(SIGQUIT, 0, SIG_IGN);
	g_signalset = true;
}

// ctrl-c
void	set_sigint_in_child(int signal)
{
	if (g_signalset && signal == SIGINT)
		set_signal_handler(SIGINT, 0, SIG_DFL);
}
