/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:54:44 by cchabeau          #+#    #+#             */
/*   Updated: 2023/08/26 20:39:33 by cchabeau         ###   ########.fr       */
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

	t_tkn_lst *cpy;

	cpy = stack;
	new = init_tkn_lst();
	if (!new)
		return (NULL);
	while (cpy->head)
	{
		i = 0;
		while (cpy->head->value[i])
		{
			if (is_sep(cpy->head->value[i], "|<>"))
			{
				tkn = ft_substr(cpy->head->value, i, 1);
				if (!tkn)
					return (NULL);
				new = add_lst_tkn(tkn, new);
				if (!new)
					return (NULL);
				i++;
			}
			else if (!is_sep(cpy->head->value[i], "|<>"))
			{
				tkn = extract_word(&cpy->head->value[i]);
				if (!tkn)
					return (NULL);
				new = add_lst_tkn(tkn, new);
				if (!new)
					return (NULL);
				i += ft_strlen(tkn);
			}
		}
		cpy->head = cpy->head->next;
	}
	return (new);
}
