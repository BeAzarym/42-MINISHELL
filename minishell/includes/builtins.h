/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:51:31 by angassin          #+#    #+#             */
/*   Updated: 2023/09/25 17:12:00 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"

/*									[Src]									*/

// builtins.c
int		cd(char *cmd);
int		echo(char **cmd);
int		env_builtins(t_env_lst *env);
int		pwd_builtins(void);
int		unset_builtins(char **arg, t_env_lst *env);
t_env	*get_previous_key(char *arg, t_env_lst *env);
int		search_unset_key(char *value, t_env_lst *env);
int		export_builtins(char **arg, t_env_lst *env);
void	replace_value_env(char *key, char *value, t_env_lst *env);

#endif