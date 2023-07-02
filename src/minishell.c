/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:34:10 by cchabeau          #+#    #+#             */
/*   Updated: 2023/07/01 17:40:55 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	(void)argv;
	(void)argc;
	(void)envp;
	t_tkn_stack *stack = NULL;
	t_tkn_stack *lst = NULL;
	while (1)
	{
		char *res = readline("[Minishell] > ");
		char **tab = arg_split(res, " \n\t\r\f\t\b");
		// ft_array_print(tab);
		stack = init_stack();
		if (!stack)
			return (7);
		int i = 0;
		while (tab[i])
		{
			stack = add_stack(tab[i], stack);
			if (!stack)
				return (42);
			int x = locate_token(tab[i], "|<>");
			if (x != -1)
				printf("TOKEN |> '%c' INDEX |> %d TOKEN LENGTH |> %ld\n", tab[i][x], x, ft_strlen(tab[i]));
			i++;
		}
		print_chained(stack->head);
		lst = token_split(stack, lst);
		print_chained(lst->head);
		ft_array_clear(tab);
	}
	return (0);
}
