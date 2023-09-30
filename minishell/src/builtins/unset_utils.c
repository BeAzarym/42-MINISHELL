/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:02:08 by cchabeau          #+#    #+#             */
/*   Updated: 2023/09/25 15:21:11 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtins.h"

t_env	*get_previous_key(char *arg, t_env_lst *env)
{
	t_env	*cpy;

	cpy = env->head;
	while (cpy)
	{
		if (cpy->next && ft_strcmp(arg, cpy->next->key) == OK)
			return (cpy);
		cpy = cpy->next;
	}
	return (NULL);
}

int	search_unset_key(char *value, t_env_lst *env)
{
	t_env	*cpy;

	cpy = env->head;
	while (cpy)
	{
		if (ft_strcmp(value, cpy->key) == OK)
			return (1);
		cpy = cpy->next;
	}
	return (0);
}
