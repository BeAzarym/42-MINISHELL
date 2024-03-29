/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:34:10 by cchabeau          #+#    #+#             */
/*   Updated: 2023/10/08 16:29:39 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/execute.h"
#include "../includes/minishell.h"

int			g_status;
static void	init(t_lists *lists, char **envp);
static void	eof(const char *cmd_line);
static void	prompt(t_lists *lists);
static bool	is_whitespace(char *str);

// printf("cmd line is: %s\n", cmd_line);
// printf("status : %d\n", status);
// print_token(tkn_lst->head);
// print_cmd(cmd_table);
// printf("debug got here\n");
// printf("cmd line is: %s\n", cmd_line);
// printf("status : %d\n", status);
// print_token(tkn_lst->head);
// printf("debug got here\n");
int	main(int argc, char **argv, char **envp)
{
	t_lists	lists;

	(void)argv;
	(void)argc;
	init(&lists, envp);
	while (true)
	{
		lists.cmd_table = init_cmd_lst();
		if (lists.cmd_table == NULL)
			return (2);
		prompt(&lists);
		clear_cmd_lst(lists.cmd_table);
	}
	clear_env_lst(lists.env_lst);
	return (g_status);
}

static void	init(t_lists *lists, char **envp)
{
	g_status = 0;
	lists->cmd_table = NULL;
	lists->tkn_lst = NULL;
	lists->env_lst = init_envp(envp);
}

/*
	Prompts the user for a command and executes it.
	Updates the history accordingly.
*/
//print_cmd(lists->cmd_table);
static void	prompt(t_lists *lists)
{
	char	*cmd_line;

	cmd_line = readline("[Miniꞩhell]$ ");
	set_signals(MAIN_H);
	eof(cmd_line);
	if (ft_strlen(cmd_line) > 0 && !is_whitespace(cmd_line))
	{
		add_history(cmd_line);
		lists->tkn_lst = lexing(cmd_line);
		if (!lists->tkn_lst)
		{
			free(cmd_line);
			g_status = 1;
			return ;
		}
		lists->cmd_table = parsing(lists->tkn_lst, lists->cmd_table);
		process_expand(lists->cmd_table, lists->env_lst);
		if (lists->cmd_table->head != NULL)
			execution(lists->cmd_table, lists->env_lst);
	}
	free(cmd_line);
}

/* 
	Called with ctrl - d 
*/
static void	eof(const char *cmd_line)
{
	if (cmd_line == NULL)
	{
		ft_putstr_fd("exit\n", 2);
		exit(g_status);
	}
}

static bool	is_whitespace(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_sep(str[i], " \n\t\r\f\t\b"))
			i++;
		else
			return (false);
	}
	return (true);
}
