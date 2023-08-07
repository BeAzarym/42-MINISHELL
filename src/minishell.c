/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:34:10 by cchabeau          #+#    #+#             */
/*   Updated: 2023/08/07 10:11:03 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_tkn_lst	*stack;
	t_tkn_lst	*lst;
	t_env_lst *env_lst;
	char *res;
	char		**tab;
	int			i;
	int			x;
	(void)envp;
	(void)argv;
	(void)argc;
	env_lst = init_envp(envp);
	stack = NULL;
	lst = NULL;
	while (1)
	{
		res = readline("[Minishell] > ");
		tab = arg_split(res, " \n\t\r\f\t\b");
		// ft_array_print(tab);
		stack = init_tkn_lst();
		if (!stack)
			return (7);
		i = 0;
		while (tab[i])
		{
			stack = add_lst_tkn(tab[i], stack);
			if (!stack)
				return (42);
			x = locate_token(tab[i], "|<>");
			if (x != -1)
				// printf("TOKEN |> '%c' INDEX |> %d TOKEN LENGTH |> %ld\n", tab[i][x], x, ft_strlen(tab[i]));
			i++;
		}
		// print_token(stack->head);
		lst = token_split(stack, lst);
		// print_token(lst->head);
		ft_array_clear(tab);
		clear_env_lst(env_lst->head);
	}
	return (0);
}
