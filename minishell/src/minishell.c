/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:34:10 by cchabeau          #+#    #+#             */
/*   Updated: 2023/08/22 09:23:05 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	// t_tkn_lst	*lst;
	// t_env_lst	*env_lst;
	// t_cmd_dllst	*cmd_table;
	// char	*cmd_line;
	int		status;
	t_cmd	cmd;
	// t_cmd	cmd2;
	g_signalset = false;
	ignore_shell_signal();

	// cmd_table = init_cmd_dllst();	

	// (void)argc;
	char *cmd_str1 = argv[1];
	
	
	cmd.type_in = STDIN_OUT;
	cmd.type_out = STDIN_OUT;
	cmd.infile = "infile.txt";
	cmd.outfile = "out";
	cmd.cmd = &cmd_str1;
	cmd.next= NULL;
	
	
	(void)argv;
	(void)argc;
	(void)envp;
	// lst = NULL;
	// env_lst = init_envp(envp);
	// cmd_table = add_cmd_dllst(cmd_table, &cmd);
	// if (!cmd_table)
	// 	return (1);
	// cmd_table->head = &cmd;
	// cmd_table->tail = &cmd;
	
	// char *cmd_str2 = argv[3];
	// cmd2.cmd = &cmd_str2;
	// cmd2.type_in = STDIN_OUT;
	// cmd2.type_out = STDIN_OUT;
	// cmd2.next = NULL;
	// cmd_table = add_cmd_dllst(cmd_table, &cmd2);
	// cmd_table->head = cmd_table->head->next;
	
	status = execution(&cmd, envp);	
	// while (true)
	// {
	// 	status = 0;
	// 	cmd_line = readline("[Minishell] > ");
		if (cmd_line == NULL)
			exit(EXIT_SUCCESS);
	// 	// lst = lexing(cmd_line);
	// 	if (ft_strlen(cmd_line) > 0)
	// 		add_history(cmd_line);
	// 	// print_token(lst->head);
	// 	// cmd_table = parsing(lst);
	// 	// print_cmd(cmd_table);
	// 	// if (ft_strncmp(cmd_line, "cd", 2) == OK)
	// 	// 	status = cd(cmd_line + 3);
	// }
	// // clear_env_lst(env_lst->head);
	return (status);
}
