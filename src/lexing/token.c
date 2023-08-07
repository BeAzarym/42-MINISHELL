/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:54:44 by cchabeau          #+#    #+#             */
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
/*   Updated: 2023/07/10 11:06:52 by cchabeau         ###   ########.fr       */
=======
/*   Updated: 2023/06/26 14:27:15 by cchabeau         ###   ########.fr       */
>>>>>>> lexing part one
=======
/*   Updated: 2023/07/02 19:29:26 by cchabeau         ###   ########.fr       */
>>>>>>> end token
=======
/*   Updated: 2023/07/10 11:06:52 by cchabeau         ###   ########.fr       */
>>>>>>> env update
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

<<<<<<< HEAD
<<<<<<< HEAD
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

t_tkn_lst	*token_split(t_tkn_lst *stack, t_tkn_lst *new)
<<<<<<< HEAD
{
	int	j;
	int	len;

	new = init_tkn_lst();
	while (stack->head)
	{
		len = ft_strlen(stack->head->value);
		j = locate_token(stack->head->value, "|<>");
		if (j == -1)
			new = add_lst_tkn(stack->head->value, new);
		else if (j == 0 && len == 1)
			new = add_lst_tkn(ft_substr(stack->head->value, j, 1), new);
		else if (j == (len - 1))
		{
			new = add_lst_tkn(ft_substr(stack->head->value, 0, j), new);
			new = add_lst_tkn(ft_substr(stack->head->value, j, 1), new);
		}
		else if (j > 0 && j < len)
		{
			new = add_lst_tkn(ft_substr(stack->head->value, 0, j), new);
			new = add_lst_tkn(ft_substr(stack->head->value, j, 1), new);
			new = add_lst_tkn(ft_substr(stack->head->value, (j + 1), len), new);
		}
		else if (j == 0 && len > 0)
		{
			new = add_lst_tkn(ft_substr(stack->head->value, j, 1), new);
			new = add_lst_tkn(ft_substr(stack->head->value, 1, len), new);
		}
		stack->head = stack->head->next;
	}
	clear_lst(stack->head);
	return (new);
}
=======
t_token *create_token(char *word, char type, t_token *lst)
{
	if (!word)
		return (NULL);
=======
int	locate_token(char *value, char *token)
{
	int	i;
>>>>>>> end token

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
=======
>>>>>>> env update
{
	int	j;
	int	len;

<<<<<<< HEAD
<<<<<<< HEAD
// void tokenize(char **arr)
// {
	
// }
>>>>>>> lexing part one
=======
	new = init_stack();
=======
	new = init_tkn_lst();
>>>>>>> env update
	while (stack->head)
	{
		len = ft_strlen(stack->head->value);
		j = locate_token(stack->head->value, "|<>");
		if (j == -1)
			new = add_lst_tkn(stack->head->value, new);
		else if (j == 0 && len == 1)
			new = add_lst_tkn(ft_substr(stack->head->value, j, 1), new);
		else if (j == (len - 1))
		{
			new = add_lst_tkn(ft_substr(stack->head->value, 0, j), new);
			new = add_lst_tkn(ft_substr(stack->head->value, j, 1), new);
		}
		else if (j > 0 && j < len)
		{
			new = add_lst_tkn(ft_substr(stack->head->value, 0, j), new);
			new = add_lst_tkn(ft_substr(stack->head->value, j, 1), new);
			new = add_lst_tkn(ft_substr(stack->head->value, (j + 1), len), new);
		}
		else if (j == 0 && len > 0)
		{
			new = add_lst_tkn(ft_substr(stack->head->value, j, 1), new);
			new = add_lst_tkn(ft_substr(stack->head->value, 1, len), new);
		}
		stack->head = stack->head->next;
	}
	clear_lst(stack->head);
	return (new);
}
>>>>>>> end token
