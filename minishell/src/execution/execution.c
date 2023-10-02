/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:35:24 by angassin          #+#    #+#             */
/*   Updated: 2023/10/02 14:06:14 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtins.h"
#include "../../includes/execute.h"

static void	pipes_swap(int fd_pipes[2][2]);
static int	redir(t_cmd *cmd_table);

/* 
	Redirects the input and output file descriptors if necessary and execute
	the commands in processess
	printf("in loop\n");
	
	printf("ONE MORE PRINT: %d\n", cmd_table->head->type_out);
	ls > out | cat -e :
	if (cmd_table->head->next->redir_out->head == NULL)
			cmd_table->head->next->fdout = cmd_table->head->fdout;
	printf("fdout in execution : %d\n", cmd_table->head->fdout);
	printf("current cmd: %s\n", cmd_table->head->cmd[0]);
*/
int	execution(t_cmd_lst *cmd_lst, t_env_lst *env_lst)
{
	int		fd_pipes[2][2];
	t_cmd	*cmd_table;

	cmd_table = cmd_lst->head;
	pipe_init(fd_pipes);
	while (cmd_table->next != NULL)
	{
		if (redir(cmd_table) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		pipe_execute(cmd_table, env_lst, fd_pipes);
		cmd_table = cmd_table->next;
		pipes_swap(fd_pipes);
	}
	if (redir(cmd_table) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (cmd_table->cmd != NULL)
		g_status = lastcmd_process(cmd_table, env_lst, fd_pipes[0],
				cmd_lst->size);
	unlink("/tmp/.heredoc.tmp");
	return (g_status);
}

static int	redir(t_cmd *cmd_table)
{
	if (get_input_output(cmd_table) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (cmd_table->type_in == HEREDOC)
		heredoc(cmd_table);
	return (EXIT_SUCCESS);
}

int	builtin_execute(t_env_lst *env_lst, t_cmd *cmd_node)
{
	if (cmd_node != NULL)
	{
		if (ft_strcmp(cmd_node->cmd[0], "cd") == OK)
			g_status = cd(cmd_node->cmd, env_lst);
		else if (ft_strcmp(cmd_node->cmd[0], "echo") == OK)
			g_status = echo(cmd_node->cmd);
		else if (ft_strcmp(cmd_node->cmd[0], "env") == OK)
			g_status = env_builtin(env_lst);
		else if (ft_strcmp(cmd_node->cmd[0], "pwd") == OK)
			g_status = pwd_builtin();
		else if (ft_strcmp(cmd_node->cmd[0], "exit") == OK)
			g_status = exit_builtin(cmd_node->cmd);
		else if (ft_strcmp(cmd_node->cmd[0], "export") == OK)
			g_status = export_builtin(cmd_node->cmd, env_lst);
		else if (ft_strcmp(cmd_node->cmd[0], "unset") == OK)
			g_status = unset_builtin(cmd_node->cmd, env_lst);
	}
	return (g_status);
}

static void	pipes_swap(int fd_pipes[2][2])
{
	fd_pipes[0][0] = fd_pipes[1][0];
	fd_pipes[0][1] = fd_pipes[1][1];
	fd_pipes[1][0] = -1;
	fd_pipes[1][1] = -1;
}

bool	is_builtin(char *cmd)
{
	if (cmd == NULL)
		return (0);
	if (ft_strcmp(cmd, "echo") == OK || ft_strcmp(cmd, "cd") == OK
		|| ft_strcmp(cmd, "pwd") == OK || ft_strcmp(cmd, "export") == OK
		|| ft_strcmp(cmd, "unset") == OK || ft_strcmp(cmd, "env") == OK
		|| ft_strcmp(cmd, "exit") == OK)
		return (true);
	return (false);
}
