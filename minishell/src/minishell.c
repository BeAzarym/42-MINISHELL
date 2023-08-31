/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:34:10 by cchabeau          #+#    #+#             */
/*   Updated: 2023/08/31 16:38:16 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/execute.h"
#include "../includes/builtins.h"

int	main(int argc, char **argv, char **envp)
{
	t_tkn_lst	*lst;
	t_env_lst	*env_lst;
	t_cmd_dllst	*cmd_table;
	char		*cmd_line;
	int			status;

	g_signalset = false;
	ignore_shell_signal();
	cmd_table = init_cmd_dllst();
	(void)argv;
	(void)argc;
	lst = NULL;
	env_lst = init_envp(envp);
	while (true)
	{
		cmd_table = init_cmd_dllst();
		if (!cmd_table)
			return (1);
		status = 0;
		cmd_line = readline("[Minishell] > ");
		printf("cmd line is: %s\n", cmd_line);
		if (cmd_line == NULL)
			exit(EXIT_SUCCESS);
		lst = lexing(cmd_line);
		if (ft_strlen(cmd_line) > 0)
			add_history(cmd_line);
		// print_token(lst->head); 
		cmd_table = parsing(lst, cmd_table);
		// print_cmd(cmd_table);// segfault
		get_input_output(cmd_table);
		status = execution(cmd_table->head, envp);
		// printf("debug got here\n");
		if (ft_strncmp(cmd_line, "cd", 2) == OK)
			status = cd(cmd_line + 3);
		if (ft_strncmp(cmd_line, "echo", 4) == OK)
			status = echo(cmd_line + 5);
	}
	clear_env_lst(env_lst);
	return (status);
}
