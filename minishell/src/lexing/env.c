/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:54:49 by cchabeau          #+#    #+#             */
/*   Updated: 2023/10/05 15:16:58 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_env_lst	*init_envp(char **envp)
{
	int			i;
	t_env_lst	*lst;
	char		**tmp;

	lst = init_env_lst();
	if (!lst)
		return (NULL);
	i = 0;
	while (envp[i])
	{
		tmp = envp_split(envp[i]);
		lst = add_lst_env(tmp[0], tmp[1], lst);
		ft_array_clear(tmp);
		i++;
	}
	return (lst);
}

char	**convert_env_to_exec(t_env_lst *env_lst)
{
	char	**arr;
	int		i;
	t_env	*cpy;

	cpy = env_lst->head;
	arr = malloc(sizeof(char *) * (env_lst->size + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (cpy)
	{
		if (cpy->value && cpy->key)
		{
			arr[i] = ft_strjoin(cpy->key, "=");
			arr[i] = ft_strjoin_s1(arr[i], cpy->value);
			if (!arr[i])
				return (NULL);
			i++;
		}
		cpy = cpy->next;
	}
	arr[i] = NULL;
	return (arr);
}

void	update_value_env(char *key, char *value, t_env_lst *env)
{
	t_env	*cpy;

	cpy = env->head;
	while (cpy)
	{
		if (ft_strcmp(cpy->key, key) == 0)
		{
			free(cpy->value);
			cpy->value = ft_strdup(value);
		}
		cpy = cpy->next;
	}
	free(value);
}
