/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:34:10 by cchabeau          #+#    #+#             */
/*   Updated: 2023/09/29 11:37:26 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/execute.h"
#include "../includes/minishell.h"

static void	init(t_lists *lists, char **envp);
static void	eof(const char *cmd_line, int status);
static int	prompt(t_lists *lists, int status);

bool		g_signalset = false;

// printf("cmd line is: %s\n", cmd_line);
// printf("status : %d\n", status);
// print_token(tkn_lst->head);
// printf("debug got here\n");
int	main(int argc, char **argv, char **envp)
{
	t_lists	lists;
	int		status;

	(void)argv;
	(void)argc;
	init(&lists, envp);
	status = 0;
	while (true)
	{
		ignore_shell_signal();
		lists.cmd_table = init_cmd_lst();
		if (lists.cmd_table == NULL)
			return (1);
		set_sigint_in_main(SIGINT);
		status = prompt(&lists, status);
	}
	clear_env_lst(lists.env_lst);
	return (status);
}

static void	init(t_lists *lists, char **envp)
{
	g_signalset = false;
	lists->cmd_table = NULL;
	lists->tkn_lst = NULL;
	lists->env_lst = init_envp(envp);
}

/*
	Prompts the user for a command and executes it.
	Updates the history accordingly.
*/
//print_cmd(lists->cmd_table);
static int	prompt(t_lists *lists, int status)
{
	char	*cmd_line;

	cmd_line = readline("[Minishell]$ ");
	eof(cmd_line, status);
	if (ft_strncmp(cmd_line, "", 1) == OK)
		status = 0;
	lists->tkn_lst = lexing(cmd_line);
	if (ft_strlen(cmd_line) > 0)
	{
		add_history(cmd_line);
		lists->cmd_table = parsing(lists->tkn_lst, lists->cmd_table);
		process_expand(lists->cmd_table, lists->env_lst, status);
		status = execution(lists->cmd_table, lists->env_lst);
	}
	free(cmd_line);
	clear_cmd_lst(lists->cmd_table);
	return (status);
}

/* 
	Called with ctrl - d 
*/
static void	eof(const char *cmd_line, int status)
{
	if (cmd_line == NULL)
	{
		printf("exit\n");
		exit(status);
	}
}
