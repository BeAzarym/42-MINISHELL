/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:02:43 by cchabeau          #+#    #+#             */
/*   Updated: 2023/09/25 18:17:20 by cchabeau         ###   ########.fr       */
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

// void sort_env(t_env_lst *env)
// {
// 	t_env *cpy;
// 	t_env *tmp;
// 	int i;

// 	cpy = env->head;
// 	i = 0;
// 	while (i < env->size-1)
// 	{
// 		if (ft_strcmp(cpy->key, cpy->next->key))
// 		{
// 			tmp = cpy;

// 		}
// 		}
// }