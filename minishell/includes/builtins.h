/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:51:31 by angassin          #+#    #+#             */
/*   Updated: 2023/10/05 15:08:57 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"

/*									[Src]									*/

// builtins.c

int		cd(char **cmd, t_env_lst *env);
void	update_pwd(char *pwd, t_env_lst *env);
int		echo(char **cmd);
int		exit_builtin(char **cmd);
int		env_builtin(t_env_lst *env);
int		pwd_builtin(void);
int		unset_builtin(char **arg, t_env_lst *env);
t_env	*get_previous_key(char *arg, t_env_lst *env);
int		search_unset_key(char *value, t_env_lst *env);
int		export_builtin(char **arg, t_env_lst *env);
void	replace_value_env(char *key, char *value, t_env_lst *env);
void	sort_env(t_env_lst *env);
void	print_export(t_env_lst *env);

#endif