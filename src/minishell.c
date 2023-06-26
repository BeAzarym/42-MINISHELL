/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:34:10 by cchabeau          #+#    #+#             */
/*   Updated: 2023/06/26 14:40:01 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	(void)argv;
	(void)argc;
	(void)envp;
	// t_token *lst = NULL;
	while (1)
	{
		char *res = readline("[Minishell] > ");
		char **tab = arg_split(res, " \n\t\r\f\t\b");
		ft_array_print(tab);
		// int i = 0;
		// while (tab[i])
		// {
		// 	printf("[TOKEN] %s\n", tab[i]);
		// 	lst = create_token(tab[i], 0, lst);
		// 	if (!lst)
		// 		return (42);
		// 	i++;
		// }
		// print_chained(lst);
		ft_array_clear(tab);
		// clear_lst(lst);
	}
	return (0);
}