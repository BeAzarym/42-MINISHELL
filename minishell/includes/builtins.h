/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:51:31 by angassin          #+#    #+#             */
/*   Updated: 2023/10/02 14:08:35 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"

/*									[Src]									*/

// builtins.c

int		cd(char **cmd, t_env_lst *env);
int		echo(char **cmd);
int		exit_builtin(char **cmd);
int		env_builtin(t_env_lst *env);
int		pwd_builtin(void);
int		unset_builtin(char **arg, t_env_lst *env);
t_env	*get_previous_key(char *arg, t_env_lst *env);
int		search_unset_key(char *value, t_env_lst *env);
int		export_builtin(char **arg, t_env_lst *env);
void	replace_value_env(char *key, char *value, t_env_lst *env);

#endif