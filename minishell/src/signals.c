/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 23:40:50 by angassin          #+#    #+#             */
/*   Updated: 2023/08/22 05:29:29 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/* 
	Ignore "Ctrl-C"
	Ignore "Ctrl-\"
*/
void	ignore_shell_signal(void)
{
	struct sigaction	sa;

	sa.sa_handler = SIG_IGN;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
	g_signalset = true;
}

// ctrl-c
void	set_sigint_in_child(int signal)
{
	struct sigaction	sa;

	(void)signal;
	if (g_signalset == true)
		sigaction(SIGINT, &sa, NULL);

}
