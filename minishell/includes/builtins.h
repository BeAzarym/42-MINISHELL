/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:51:31 by angassin          #+#    #+#             */
/*   Updated: 2023/09/21 23:34:28 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"

/*									[Src]									*/

// builtins.c
int	cd(char **cmd, t_env_lst *env, int status);
int	echo(char **cmd);
int	env_builtins(t_env_lst *env);
int	pwd_builtins(void);

#endif