/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:54:44 by cchabeau          #+#    #+#             */
/*   Updated: 2023/07/02 19:29:26 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	locate_token(char *value, char *token)
{
	int	i;

	if (!value || !token)
		return (-1);
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

t_tkn_stack	*token_split(t_tkn_stack *stack, t_tkn_stack *new)
{
	int		j;
	int len;

	new = init_stack();
	while (stack->head)
	{
		len = ft_strlen(stack->head->value);
		j = locate_token(stack->head->value, "|<>");
		if (j == -1)
			new = add_stack(stack->head->value, new);
		else if (j == 0 && len == 1)
			new = add_stack(ft_substr(stack->head->value, j, 1), new);
		else if (j == (len - 1))
		{
			new = add_stack(ft_substr(stack->head->value, 0, j), new);
			new = add_stack(ft_substr(stack->head->value, j, 1), new);
		}
		else if (j > 0 && j < len)
		{
			new = add_stack(ft_substr(stack->head->value, 0, j), new);
			new = add_stack(ft_substr(stack->head->value, j, 1), new);
			new = add_stack(ft_substr(stack->head->value, (j + 1), len), new);
		}
		else if (j == 0 && len > 0)
		{
			new = add_stack(ft_substr(stack->head->value, j, 1), new);
			new = add_stack(ft_substr(stack->head->value, 1, len), new);
		}
		stack->head = stack->head->next;
	}
	clear_lst(stack->head);
	return (new);
}
