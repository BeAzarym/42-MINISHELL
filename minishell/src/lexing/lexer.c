/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 23:14:14 by cchabeau          #+#    #+#             */
/*   Updated: 2023/10/03 18:17:26 by cchabeau         ###   ########.fr       */
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

static int	is_valid_cmd_line(t_tkn_lst *lst)
{
	t_token	*cpy;

	cpy = lst->head;
	while (cpy)
	{
		if (cpy->next && cpy->type == 'P' && cpy->next->type == 'P')
			return (0);
		if (cpy->type == 'I' || cpy->type == 'O')
		{
			if (cpy->next && cpy->next->type == 'W')
				cpy = cpy->next;
			if (cpy->next && cpy->next->next && (cpy->next->type == 'I'
					|| cpy->next->type == 'O'))
			{
				if (cpy->next->next->next->type == 'W')
					cpy = cpy->next->next->next;
				else
					return (0);
			}
		}
		cpy = cpy->next;
	}
	return (1);
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
		return (NULL);
	}
	return (lst);
}
