/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 23:14:14 by cchabeau          #+#    #+#             */
<<<<<<< HEAD
<<<<<<< HEAD
/*   Updated: 2023/08/07 11:32:57 by cchabeau         ###   ########.fr       */
=======
/*   Updated: 2023/06/21 15:29:10 by cchabeau         ###   ########.fr       */
>>>>>>> lexing part one
=======
/*   Updated: 2023/08/07 11:32:57 by cchabeau         ###   ########.fr       */
>>>>>>> cleaning main
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> cleaning main
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
<<<<<<< HEAD
=======
>>>>>>> lexing part one
=======
>>>>>>> cleaning main
