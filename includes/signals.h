/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:57:19 by angassin          #+#    #+#             */
/*   Updated: 2023/10/07 09:52:30 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

// sigaction
# include <signal.h>
// tcsetattr, tcgetattr
# include <termios.h>
// other includes
# include "minishell.h"

/*									[Macros]								*/

enum	e_signal_functions
{
	MAIN_H,
	CHILD_H,
	PARENT_H
};

/*									[Src]									*/

// signal.c
void	set_signals(int handler);
void	set_heredoc_signals(int handler);

// signal_functions.c
void	sigint_in_main(int signal);
void	child_process_signal(int signal);
void	parent_process_signal(int signal);
void	heredoc_child_process_signal(int signal);
void	heredoc_parent_process_signal(int signal);

#endif
