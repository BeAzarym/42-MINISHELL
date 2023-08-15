/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:34:10 by cchabeau          #+#    #+#             */
/*   Updated: 2023/08/15 14:01:52 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_tkn_lst	*lst;
	t_env_lst	*env_lst;
	t_cmd_node	*cmd;
	char	*cmd_line;
	int		status;
	t_cmd	command;

	(void)argc;
	// cmd.type_in = STDIN_OUT;
	// cmd.type_out = STDIN_OUT;
	// cmd.infile = "infile.txt";
	// cmd.outfile = "out";
	// cmd.cmd = &argv[1];
	// cmd.next= NULL;

	status = execution(&command, envp);	
	(void)argv;
	(void)argc;
	(void)envp;
	lst = NULL;
	env_lst = init_envp(envp);
	cmd = init_cmd_node();
	if (!cmd)
		return (1);
	while (true)
	{
		status = 0;
		cmd_line = readline("[Minishell] > ");
		lst = lexing(cmd_line);
		if (ft_strlen(cmd_line) > 0)
			add_history(cmd_line);
		print_token(lst->head);
		// cmd = parsing(lst);
		// print_cmd(cmd);
		if (ft_strncmp(cmd_line, "cd", 2) == OK)
			status = cd(cmd_line + 3);
	}
	clear_env_lst(env_lst->head);
	return (status);
}
