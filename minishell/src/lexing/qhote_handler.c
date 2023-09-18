/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qhote_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:41:37 by cchabeau          #+#    #+#             */
/*   Updated: 2023/09/18 13:37:11 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*handle_s_qhote(char *str)
{
	int		i;
	int		status;
	char	*res;

	i = 0;
	status = 0;
	while (str[i])
	{
		if (str[i] == '\'' && !status)
		{
			status = 1;
			i++;
		}
		if (str[i] == '\'' && status)
			break ;
		i++;
	}
	res = malloc(sizeof(char) * i + 1);
	if (!res)
		return (NULL);
	ft_strlcpy(res, &str[1], i);
	return (res);
}

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

char	*get_key_value(char *key, t_env_lst *env, int status)
{
	t_env	*cpy;
	char	*value;

	value = NULL;
	if (ft_strncmp(key, "?", 1) == 0)
	{
		value = ft_itoa(status);
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

char	*substitute_env(char *key, t_env_lst *env, int status)
{
	char	*value;

	value = get_key_value(key, env, status);
	if (!value)
		return (NULL);
	free(key);
	return (value);
}

char	*handle_d_qhote(char *str, t_env_lst *env, int status)
{
	int		i;
	char	*tmp;
	char	*res;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '$' && str[i] != '"')
		{
			tmp = extract_key(&str[i + 1]);
			i += ft_strlen(tmp) + 1;
			if (search_in_env(tmp, env))
				tmp = substitute_env(tmp, env, status);
			else
				tmp = ft_strdup("");
			res = ft_strjoin_null(tmp, res);
		}
		else if (str[i] != '$' && str[i] != '"')
		{
			tmp = extract_word_sep(&str[i], "$\"");
			i += ft_strlen(tmp);
			res = ft_strjoin_null(tmp, res);
		}
	}
	return (res);
}
