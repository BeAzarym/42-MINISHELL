/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 23:40:50 by angassin          #+#    #+#             */
/*   Updated: 2023/10/02 17:20:08 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execute.h"

static void	set_signal_handler(int signal, int flags, void (*handler)(int))
{
	struct sigaction	sa;

	sa.sa_handler = handler;
	sa.sa_flags = flags;
	sigemptyset(&sa.sa_mask);
	sigaction(signal, &sa, NULL);
}

// printf("g_signalset : %d\n", g_signal.status);
static void	handle_sigint_in_main(int signal)
{
	if (g_signal.signalset && signal == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	g_signal.status = 1;
}

/* 
	Ignore "Ctrl-c"
	Ignore "Ctrl-\"
*/
void	ignore_shell_signal(void)
{
	set_signal_handler(SIGINT, 0, SIG_IGN);
	set_signal_handler(SIGQUIT, 0, SIG_IGN);
	g_signal.signalset = true;
}

// ctrl-c in child
void	set_sigint_in_child(int signal)
{
	if (g_signal.signalset && signal == SIGINT)
		set_signal_handler(SIGINT, 0, NULL);
}

//ctrl-c in main
void	set_sigint_in_main(int signal)
{
	struct sigaction	sa;

	sa.sa_handler = &handle_sigint_in_main;
	sigaction(signal, &sa, NULL);
}
