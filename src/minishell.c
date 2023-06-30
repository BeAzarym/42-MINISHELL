/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:34:10 by cchabeau          #+#    #+#             */
/*   Updated: 2023/06/30 16:20:55 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	(void)argv;
	(void)argc;
	(void)envp;
	t_tkn_stack *stack = NULL;
	while (1)
	{
		char *res = readline("[Minishell] > ");
		char **tab = arg_split(res, " \n\t\r\f\t\b");
		ft_array_print(tab);
		stack = init_stack();
		if (!stack)
			return (7);
		int i = 0;
		while (tab[i])
		{
			stack = add_stack(tab[i], stack);
			if (!stack)
				return (42);
			i++;
		}
		print_chained(stack->head);
		ft_array_clear(tab);
		clear_lst(stack->head);
	}
	return (0);
}