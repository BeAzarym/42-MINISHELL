/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:34:10 by cchabeau          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/08/16 16:27:32 by angassin         ###   ########.fr       */
=======
/*   Updated: 2023/08/10 11:29:20 by cchabeau         ###   ########.fr       */
>>>>>>> phoenix
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_tkn_lst	*stack;
	t_tkn_lst	*lst;
<<<<<<< HEAD
	t_env_lst *env_lst;
	char *res;
	char		**tab;
	int			i;
	int			x;
	(void)envp;
=======
	t_env_lst	*env_lst;
	t_cmd_node	*cmd;
	char		*res;

>>>>>>> phoenix
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
