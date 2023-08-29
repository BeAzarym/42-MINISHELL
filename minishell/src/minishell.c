/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:34:10 by cchabeau          #+#    #+#             */
/*   Updated: 2023/08/29 16:11:23 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_tkn_lst	*lst;
	t_env_lst	*env_lst;
	t_cmd_dllst	*cmd_table;
	char		*cmd_line;
	int			status;

	// t_cmd	cmd;
	// (void)argc;
	// cmd.type_in = STDIN_OUT;
	// cmd.type_out = STDIN_OUT;
	// cmd.infile = "infile.txt";
	// cmd.outfile = "out";
	// cmd.cmd = &argv[1];
	// cmd.next= NULL;
	// status = execution(&cmd, envp);
	(void)argv;
	(void)argc;
	lst = NULL;
	env_lst = init_envp(envp);
	// print_env(env_lst);
	while (true)
	{
		cmd_table = init_cmd_dllst();
		if (!cmd_table)
			return (1);
		status = 0;
		cmd_line = readline("[Minishell] > ");
		if (ft_strlen(cmd_line) > 0)
			add_history(cmd_line);
		lst = lexing(cmd_line);
		print_token(lst->head);
		cmd_table = parsing(lst, cmd_table);
		print_cmd(cmd_table);
		// if (ft_strncmp(cmd_line, "cd", 2) == OK)
		// 	status = cd(cmd_line + 3);
		clear_cmd_ddlst(cmd_table);
	}
	clear_env_lst(env_lst);
	return (status);
}
