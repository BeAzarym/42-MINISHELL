/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:54:49 by cchabeau          #+#    #+#             */
/*   Updated: 2023/08/16 16:55:43 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_env_lst	*init_envp(char **envp)
{
	int i;
	t_env_lst *lst;
	char **tmp;

	lst = init_env_lst();
	if (!lst)
		return (NULL);
	i = 0;
	
	while (envp[i])
	{
		tmp = envp_split(envp[i]);
		lst = add_lst_env(tmp[0], tmp[1], lst);
		// printf("[KEY] >> %s	[VALUE] >> %s\n", tmp[0], tmp[1]);
		ft_array_clear(tmp);
		i++;
	}
	return (lst);
}