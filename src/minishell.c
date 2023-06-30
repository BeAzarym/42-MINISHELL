/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:34:10 by cchabeau          #+#    #+#             */
/*   Updated: 2023/08/16 16:21:51 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_tkn_lst	*lst;
	t_env_lst	*env_lst;
	t_cmd_node	*cmd;
	char		*res;

	(void)argv;
	(void)argc;
	lst = NULL;
	env_lst = init_envp(envp);
	cmd = init_cmd_node();
	if (!cmd)
		return (1);
	while (1)
	{
		res = readline("[Minishell] > ");
		lst = lexing(res);
		print_token(lst->head);
		// cmd = parsing(lst);
		// print_cmd(cmd);
	}
	clear_env_lst(env_lst->head);
	return (0);
}

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