/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:54:49 by cchabeau          #+#    #+#             */
/*   Updated: 2023/08/25 12:56:32 by cchabeau         ###   ########.fr       */
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

char **convert_env_to_exec(t_env_lst *env_lst)
{
	char **arr;
	int i;

	t_env_lst *cpy;

	cpy = env_lst;
	arr = malloc(sizeof(char *) * cpy->size + 1);
	if (!arr)
		return (NULL);
	i = 0;
	while (cpy->head)
	{
		arr[i] = ft_strjoin(cpy->head->key, "=");
		arr[i] = ft_strjoin_s1(arr[i], cpy->head->value);
		if (!arr[i])
			return (NULL);
		i++;
		cpy->head = cpy->head->next;
	}
	arr[i] = NULL;
	ft_array_print(arr);
	return (arr);
}
