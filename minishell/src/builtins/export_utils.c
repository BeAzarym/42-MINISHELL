/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:02:43 by cchabeau          #+#    #+#             */
/*   Updated: 2023/10/02 14:16:09 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtins.h"

void	replace_value_env(char *key, char *value, t_env_lst *env)
{
	t_env	*cpy;

	cpy = env->head;
	while (cpy)
	{
		if (ft_strcmp(cpy->key, key) == 0)
		{
			if (cpy->value)
				free(cpy->value);
			cpy->value = ft_strdup(value);
		}
		cpy = cpy->next;
	}
}

void	sort_env(t_env_lst *env)
{
	t_env	*cpy;
	t_env	*tmp;

	cpy = env->head;
	while (cpy)
	{
		cpy->sorted_pos = 0;
		tmp = env->head;
		while (tmp)
		{
			if (ft_strcmp(cpy->key, tmp->key) > 0)
			{
				cpy->sorted_pos++;
			}
			tmp = tmp->next;
		}
		cpy = cpy->next;
	}
	print_export(env);
}

void	print_export(t_env_lst *env)
{
	int i;
	t_env	*tmp;

	i = 0;
	while (i < env->size)
	{
		tmp = env->head;
		while (tmp)
		{
			if (tmp->sorted_pos == i)
			{
				if (tmp->value)
					printf("declare -x %s=%s\n", tmp->key, tmp->value);
				else
					printf("declare -x %s\n", tmp->key);
			}
			tmp = tmp->next;
		}
		i++;
	}
}