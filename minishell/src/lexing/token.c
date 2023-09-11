/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:54:44 by cchabeau          #+#    #+#             */
/*   Updated: 2023/09/11 11:29:41 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*extract_word(char *word)
{
	char	*tkn;
	int		len;

	len = locate_token(word, "|<>");
	if (len == -2)
		return (NULL);
	else if (len == -1)
		tkn = ft_substr(word, 0, ft_strlen(word));
	else
		tkn = ft_substr(word, 0, len);
	if (!tkn)
		return (NULL);
	return (tkn);
}

int	locate_token(char *value, char *token)
{
	int	i;

	if (!value || !token)
		return (-2);
	i = 0;
	while (value[i])
	{
		if (value[i] == '\'' || value[i] == '"')
			i = escape_quotes(value, i);
		if (is_sep(value[i], token))
			return (i);
		i++;
	}
	return (-1);
}

t_tkn_lst	*token_split(t_tkn_lst *stack, t_tkn_lst *new)
{
	int		i;
	char	*tkn;
	t_token	*cpy;

	cpy = stack->head;
	new = init_tkn_lst();
	if (!new)
		return (NULL);
	while (cpy)
	{
		i = 0;
		while (cpy->value[i])
		{
			if (is_sep(cpy->value[i], "|<>"))
			{
				tkn = ft_substr(cpy->value, i, 1);
				if (!tkn)
					return (NULL);
				new = add_lst_tkn(tkn, new);
				if (!new)
					return (NULL);
				i++;
			}
			else if (!is_sep(cpy->value[i], "|<>"))
			{
				tkn = extract_word(&cpy->value[i]);
				if (!tkn)
					return (NULL);
				new = add_lst_tkn(tkn, new);
				if (!new)
					return (NULL);
				i += ft_strlen(tkn);
			}
		}
		cpy = cpy->next;
	}
	return (new);
}
