/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:01:01 by cchabeau          #+#    #+#             */
/*   Updated: 2023/09/27 11:46:14 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtins.h"

static int	unset_head(t_env *cpy, t_env_lst *env)
{
	free(env->head->key);
	free(env->head->value);
	env->size--;
	cpy = env->head->next;
	free(env->head);
	env->head = cpy;
	return (0);
}

static int	unset_tail(t_env *cpy, char *arg, t_env_lst *env)
{
	cpy = get_previous_key(arg, env);
	if (!cpy)
		return (1);
	free(env->tail->key);
	free(env->tail->value);
	env->size--;
	cpy->next = NULL;
	free(env->tail);
	env->tail = cpy;
	return (0);
}

static int	process_unset(t_env *cpy, char *arg, t_env_lst *env)
{
	t_env	*tmp;

	cpy = env->head;
	while (cpy)
	{
		if (ft_strcmp(cpy->key, arg) == OK)
		{
			tmp = get_previous_key(arg, env);
			if (!tmp)
				return (1);
			tmp->next = cpy->next;
			free(cpy->value);
			free(cpy->key);
			free(cpy);
			cpy = tmp;
			return (0);
		}
		cpy = cpy->next;
	}
	return (1);
}

int	unset_var(char *arg, t_env_lst *env)
{
	t_env	*cpy;

	cpy = NULL;
	if (ft_strcmp(env->head->key, arg) == OK)
		return (unset_head(cpy, env));
	else if (ft_strcmp(env->tail->key, arg) == OK)
		return (unset_tail(cpy, arg, env));
	else
		return (process_unset(cpy, arg, env));
	return (1);
}

int	unset_builtin(char **arg, t_env_lst *env)
{
	int	i;
	int	status;

	i = 1;
	while (arg[i])
	{
		if (search_unset_key(arg[i], env) == 1 && ft_strcmp(arg[i], "_") != 0)
			status = unset_var(arg[i], env);
		i++;
	}
	return (status);
}
