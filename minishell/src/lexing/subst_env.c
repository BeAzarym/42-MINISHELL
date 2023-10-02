/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subst_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:38:06 by cchabeau          #+#    #+#             */
/*   Updated: 2023/10/02 16:46:26 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*extract_key(char *str)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (ft_isalnum(str[i]) || str[i] == '_' || str[i] == '?')
			j++;
		if (!ft_isalnum(str[i]) && str[i] != '_' && str[i] != '?')
			break ;
		i++;
	}
	result = ft_substr(str, 0, j);
	if (!result)
		return (NULL);
	return (result);
}

char	*get_key_value(char *key, t_env_lst *env)
{
	t_env	*cpy;
	char	*value;

	value = NULL;
	if (ft_strncmp(key, "?", 1) == 0)
	{
		value = ft_itoa(g_signal.status);
		if (!value)
			return (NULL);
		return (value);
	}
	cpy = env->head;
	while (cpy)
	{
		if (ft_strncmp(key, cpy->key, ft_strlen(key)) == 0)
		{
			value = ft_strdup(cpy->value);
			if (!value)
				return (NULL);
			break ;
		}
		cpy = cpy->next;
	}
	return (value);
}

char	*substitute_env(char *key, t_env_lst *env)
{
	char	*value;

	value = get_key_value(key, env);
	if (!value)
		return (NULL);
	free(key);
	return (value);
}
