/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:57:19 by angassin          #+#    #+#             */
/*   Updated: 2023/10/05 12:05:57 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

// other includes
# include "minishell.h"

/*									[Macros]								*/

enum	e_handlers
{
	MAIN_H,
	CHILD_H,
	PARENT_H
};

/*									[Src]									*/

// signal.c
void		ignore_shell_signal(void);
// void		set_sigint_in_child(int signal);
// void		set_sigint_in_main(int signal);
void		set_signals(int handler);

// handlers.c
void	sigint_in_main_handler(int signal);
void	child_process_handler(int signal);
void	parent_process_handler(int signal);

#endif