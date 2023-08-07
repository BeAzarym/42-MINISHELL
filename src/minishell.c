/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:34:10 by cchabeau          #+#    #+#             */
/*   Updated: 2023/08/16 16:27:32 by angassin         ###   ########.fr       */
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
	lst = NULL;
	env_lst = init_envp(envp);
	while (1)
	{
		res = readline("[Minishell] > ");
		lst = lexing(res);
		print_token(lst->head);
	}
		clear_env_lst(env_lst->head);
	return (0);
}
