/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 23:14:14 by cchabeau          #+#    #+#             */
/*   Updated: 2023/08/16 16:55:51 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_tkn_lst	*lexing(char *str)
{
	char **array;
	t_tkn_lst *stack;
	t_tkn_lst	*lst;
	int i;

	stack = NULL;
	lst = NULL;
	array = arg_split(str, " \n\t\r\f\t\b");
	stack = init_tkn_lst();
	if (!stack)
		return (NULL);
	i = 0;
	while (array[i])
	{
		stack = add_lst_tkn(array[i], stack);
		if (!stack)
			return (NULL);
		i++;
	}
	lst = token_split(stack, lst);
	if (!lst)
		return (NULL);
	ft_array_clear(array);
	clear_tkn_lst(stack->head);
	return (lst);
}
