/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:13:03 by cchabeau          #+#    #+#             */
/*   Updated: 2023/10/04 12:50:18 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	compute_len(char *str, char *sep)
{
	int	i;

	i = 0;
	if (str[i] == '~')
		return (1);
	while (str[i])
	{
		if (!is_sep(str[i], sep))
			i++;
		else
			break ;
	}
	return (i);
}

char	*extract_word_sep(char *str, char *sep, t_env_lst *env)
{
	char	*res;

	if (!str)
		return (NULL);
	if (ft_strcmp(str, "~") == 0)
	{
		res = ft_strdup("$HOME");
		if (!res)
			return (NULL);
		res = expand(res, env);
		return (res);
	}
	res = ft_substr(str, 0, compute_len(str, sep));
	if (!res)
		return (NULL);
	return (res);
}

int	have_quotes(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '"')
			return (1);
		i++;
	}
	return (0);
}

int	need_substitute(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$' && (ft_isalnum(str[i + 1]) || str[i + 1] == '_'
				|| str[i + 1] == '?'))
			return (1);
		i++;
	}
	return (0);
}

char	*handle_without_q(char *str, t_env_lst *env)
{
	int		i;
	char	*tmp;
	char	*res;

	res = NULL;
	i = 0;
	while (str[i] && !is_sep(str[i], "\"'"))
	{
		if (str[i] == '$')
		{
			tmp = extract_key(&str[i + 1]);
			i += ft_strlen(tmp) + 1;
			tmp = process_substitution(tmp, env);
			res = ft_strjoin_null(tmp, res);
		}
		else if (str[i] != '$')
		{
			tmp = extract_word_sep(&str[i], "$\"'", env);
			i += compute_len(&str[i], "$'\"");
			res = ft_strjoin_null(tmp, res);
		}
	}
	return (res);
}
