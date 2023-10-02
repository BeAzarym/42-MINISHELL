/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:41:37 by cchabeau          #+#    #+#             */
/*   Updated: 2023/10/02 14:13:14 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*handle_s_quote(char *str)
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

char	*process_substitution(char *str, t_env_lst *env)
{
	if (search_in_env(str, env))
		str = substitute_env(str, env);
	else
		str = ft_strdup("");
	return (str);
}

char	*handle_d_quote(char *str, t_env_lst *env)
{
	int		i;
	char	*tmp;
	char	*res;

	res = NULL;
	i = 0;
	while (str[i] && !is_sep(str[i], "\""))
	{
		if (str[i] == '$' && str[i] != '"')
		{
			tmp = extract_key(&str[i + 1]);
			i += ft_strlen(tmp) + 1;
			tmp = process_substitution(tmp, env);
			res = ft_strjoin_null(tmp, res);
		}
		else if (str[i] != '$' && str[i] != '"')
		{
			tmp = extract_word_sep(&str[i], "$\"");
			i += ft_strlen(tmp);
			res = ft_strjoin_null(tmp, res);
		}
	}
	if (!res)
		res = ft_strdup("");
	return (res);
}
