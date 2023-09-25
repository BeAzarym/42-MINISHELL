/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:35:24 by angassin          #+#    #+#             */
/*   Updated: 2023/09/25 13:57:15 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtins.h"
#include "../../includes/execute.h"

static void	pipes_swap(int fd_pipes[2][2]);

/* 
	Redirects the input and output file descriptors if necessary and execute
	the commands in processess
	printf("in loop\n");
	
	printf("ONE MORE PRINT: %d\n", cmd_table->head->type_out);
	ls > out | cat -e :
	if (cmd_table->head->next->redir_out->head == NULL)
			cmd_table->head->next->fdout = cmd_table->head->fdout;
*/
int	execution(t_cmd_lst *cmd_lst, t_env_lst *env_lst)
{
	int			fd_pipes[2][2];
	int			status;
	t_cmd_lst	*cmd_table;

	g_signalset = false;
	status = 0;
	cmd_table = cmd_lst;
	pipe_init(fd_pipes);
	while (cmd_table->head->next != NULL)
	{
		get_input_output(cmd_table);
		if (cmd_table->head->type_in == HEREDOC)
			heredoc(cmd_table);
		pipe_execute(cmd_table->head, env_lst, fd_pipes);
		cmd_table->head = cmd_table->head->next;
		pipes_swap(fd_pipes);
	}
	get_input_output(cmd_table);
	printf("fdout in execution : %d\n", cmd_table->head->fdout);
	printf("current cmd: %s\n", cmd_table->head->cmd[0]);
	if (is_builtin(cmd_table->head->cmd[0]))
	{
		lastcmd_dup(cmd_table->head, fd_pipes[0]);
		status = builtin_execute(env_lst, cmd_table->head, status);
	}
	else
	{
		if (cmd_table->head->type_in == HEREDOC)
			heredoc(cmd_table);
		if (cmd_table->head->cmd != NULL)
			status = lastcmd_process(cmd_table, env_lst, fd_pipes[0]);
	}
	unlink("/tmp/.heredoc.tmp");
	return (status);
}

int	builtin_execute(t_env_lst *env_lst, t_cmd *cmd_node, int status)
{
	if (cmd_node != NULL)
	{
		if (ft_strcmp(cmd_node->cmd[0], "cd") == OK)
			status = cd(cmd_node->cmd, env_lst);
		else if (ft_strcmp(cmd_node->cmd[0], "echo") == OK)
			status = echo(cmd_node->cmd);
		else if (ft_strcmp(cmd_node->cmd[0], "env") == OK)
			status = env_builtin(env_lst);
		else if (ft_strcmp(cmd_node->cmd[0], "pwd") == OK)
			status = pwd_builtin();
		else if (ft_strcmp(cmd_node->cmd[0], "exit") == OK)
			status = exit_builtin(cmd_node->cmd, status);
	}
	return (status);
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
