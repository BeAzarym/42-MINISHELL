/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:34:10 by cchabeau          #+#    #+#             */
/*   Updated: 2023/09/20 13:25:30 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/builtins.h"
#include "../includes/execute.h"
#include "../includes/minishell.h"

static void	init(t_lists *lists, char **envp);
static void	eof(const char *cmd_line, int status);
static int	builtin_or_exe(t_env_lst *env_lst, t_cmd_lst *cmd_table,
				char *cmd_line, int status);
static int	prompt(t_lists *lists, int status);

bool		g_signalset = false;

// printf("cmd line is: %s\n", cmd_line);
// printf("status : %d\n", status);
// print_token(tkn_lst->head);
// print_cmd(cmd_table);
// printf("debug got here\n");
int	main(int argc, char **argv, char **envp)
{
	t_lists	lists;
	int		status;

	(void)argv;
	(void)argc;
	init(&lists, envp);
	ignore_shell_signal();
	while (true)
	{
		lists.cmd_table = init_cmd_lst();
		if (!lists.cmd_table)
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
	lists->cmd_table = init_cmd_lst();
	lists->tkn_lst = NULL;
	lists->env_lst = init_envp(envp);
}

static int	prompt(t_lists *lists, int status)
{
	char	*cmd_line;

	cmd_line = readline("[Minishell]$ ");
	eof(cmd_line, status);
	if (ft_strncmp(cmd_line, "", 1) == OK)
		status = 0;
	lists->tkn_lst = lexing(cmd_line);
	if (ft_strlen(cmd_line) > 0)
		add_history(cmd_line);
	lists->cmd_table = parsing(lists->tkn_lst, lists->cmd_table);
	process_expand(lists->cmd_table, lists->env_lst, status);
	builtin_or_exe(lists->env_lst, lists->cmd_table, cmd_line, status);
	free(cmd_line);
	clear_cmd_lst(lists->cmd_table);
	return (status);
}

/* Called with ctrl - d */
static void	eof(const char *cmd_line, int status)
{
	if (cmd_line == NULL)
	{
		printf("exit\n");
		exit(status);
	}
}

static int	builtin_or_exe(t_env_lst *env_lst, t_cmd_lst *cmd_table,
		char *cmd_line, int status)
{
	char	**env;

	if (cmd_table->head != NULL)
	{
		env = convert_env_to_exec(env_lst);
		status = execution(cmd_table, env);
		if (ft_strncmp(cmd_line, "cd", 2) == OK)
			status = cd(cmd_line + 3);
		if (ft_strncmp(cmd_line, "echo", 4) == OK)
			status = echo(cmd_line + 5);
		if (ft_strncmp(cmd_line, "env", 4) == OK)
			status = env_builtins(env_lst);
		if (ft_strncmp(cmd_line, "pwd", 3) == OK)
			status = pwd_builtins();
	}
	return (status);
}
