/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:34:10 by cchabeau          #+#    #+#             */
/*   Updated: 2023/09/19 15:30:26 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/execute.h"
#include "../includes/builtins.h"

 bool	g_signalset = false;


int	main(int argc, char **argv, char **envp)
{
	t_tkn_lst	*lst;
	t_env_lst	*env_lst;
	t_cmd_lst	*cmd_table;
	char		*cmd_line;
	int			status;
	char		**env;

	g_signalset = false;
	ignore_shell_signal();
	cmd_table = init_cmd_lst();
	(void)argv;
	(void)argc;
	lst = NULL;
	env_lst = init_envp(envp);
	while (true)
	{
		cmd_table = init_cmd_lst();
		if (!cmd_table)
			return (1);
		set_sigint_in_main(SIGINT);
	 	cmd_line = readline("[Minishell]$ ");
		if (cmd_line == NULL) // to do : fix the printing of ^D
		{
			printf("exit\n");
			exit(status);
		}
		if (ft_strncmp(cmd_line, "", 1) == OK)
			status = 0;
		printf("cmd line is: %s\n", cmd_line);
		printf("status : %d\n", status);
		lst = lexing(cmd_line);
		if (ft_strlen(cmd_line) > 0)
			add_history(cmd_line);
		// print_token(lst->head); 
		cmd_table = parsing(lst, cmd_table);
		process_expand(cmd_table, env_lst, status);
		if (cmd_table->head != NULL)
		{
			print_cmd(cmd_table);
			env = convert_env_to_exec(env_lst);
			status = execution(cmd_table, env);
			// printf("debug got here\n");
			if (ft_strncmp(cmd_line, "cd", 2) == OK)
				status = cd(cmd_line + 3);
			if (ft_strncmp(cmd_line, "echo", 4) == OK)
				status = echo(cmd_line + 5);
			if (ft_strncmp(cmd_line, "env", 4) == OK)
				status = env_builtins(env_lst);
			if (ft_strncmp(cmd_line, "pwd", 3) == OK)
				status = pwd_builtins(env_lst);
		}
		free(cmd_line);
		clear_cmd_lst(cmd_table);
	}
	clear_env_lst(env_lst);
	return (status);
}
