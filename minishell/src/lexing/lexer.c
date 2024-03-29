/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 23:14:14 by cchabeau          #+#    #+#             */
/*   Updated: 2023/10/05 15:31:40 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_tkn_lst	*put_tkn_in_lst(char **array, t_tkn_lst *stack)
{
	int	i;

	i = 0;
	while (array[i])
	{
		stack = add_lst_tkn(array[i], stack);
		if (!stack)
			return (NULL);
		i++;
	}
	return (stack);
}

t_tkn_lst	*lexing(char *str)
{
	char		**array;
	t_tkn_lst	*stack;
	t_tkn_lst	*lst;

	stack = NULL;
	lst = NULL;
	array = arg_split(str, " \n\t\r\f\t\b");
	stack = init_tkn_lst();
	if (!stack)
		return (NULL);
	stack = put_tkn_in_lst(array, stack);
	if (!stack)
		return (NULL);
	lst = token_split(stack, lst);
	if (!lst)
		return (NULL);
	ft_array_clear(array);
	clear_tkn_lst(stack);
	if (!is_valid_cmd_line(lst))
	{
		printf("Error: Syntax not valid\n");
		clear_tkn_lst(lst);
		return (NULL);
	}
	return (lst);
}
