/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:13:03 by cchabeau          #+#    #+#             */
/*   Updated: 2023/09/19 20:59:21 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	compute_len(char *str, char *sep)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!is_sep(str[i], sep))
			i++;
		else
			break ;
	}
	return (i);
}

char	*extract_word_sep(char *str, char *sep)
{
	char	*res;

	if (!str)
		return (NULL);
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
