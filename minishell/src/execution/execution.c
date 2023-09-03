/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:35:24 by angassin          #+#    #+#             */
/*   Updated: 2023/09/04 00:02:18 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execute.h"

static char	**commands_paths_array(char **envp);
static char	*command_access(char *cmd, char **paths);

/* 
	Redirects the input and output file descriptors if necessary and execute
	the commands in processes
*/
int	execution(t_cmd_lst *cmd_table, char **envp)
{
	int		fd_pipes[2][2];
	int		status;

	status = 0;
	fd_pipes[0][0] = -1;
	fd_pipes[0][1] = -1;
	fd_pipes[1][0] = -1;
	fd_pipes[1][1] = -1;
	printf("ONE MORE PRINT: %d\n", cmd_table->head->type_out);
	while (cmd_table->head->next != NULL)
	{
		printf("in loop\n");
		get_input_output(cmd_table);
		printf("fdout in execution : %d\n", cmd_table->head->fdout);
		printf("current cmd: %s\n", cmd_table->head->cmd[0]);
		create_process(cmd_table->head, envp, fd_pipes);
		cmd_table->head = cmd_table->head->next;
		fd_pipes[0][0] = fd_pipes[1][0];
		fd_pipes[0][1] = fd_pipes[1][1];
		fd_pipes[1][0] = -1;
		fd_pipes[1][1] = -1;
	}
	get_input_output(cmd_table);
	if (cmd_table->head->type_in == HEREDOC)
		heredoc(cmd_table, fd_pipes);
	if (cmd_table->head->cmd != NULL)
		status = lastcmd_process(cmd_table, envp, fd_pipes[0]);
	return (status);
}

/*
	Executes the command sent in argument, execve returns only in case
	of failure as the execve() function overlays the current process image
	with a new process image.
	// ft_putstr_fd("in execute\n", 2);
*/
void	execute(t_cmd *cmd, char **envp)
{
	char	**paths;
	char	*cmd_path;
	struct sigaction	sa;

	if (cmd == NULL)
		error_exit("parsing of the command failed");
	sa.sa_handler = &set_sigint_in_child;
	if (sigaction(SIGINT, &sa, NULL) == -1
		|| sigaction(SIGQUIT, &sa, NULL) == -1)
		error_exit("killed\n");
	paths = commands_paths_array(envp);
	cmd_path = command_access(cmd->cmd[0], paths);
	if (cmd_path == NULL)
	{
		ft_free_array(paths);
		exit(127);
	}
	execve(cmd_path, cmd->cmd, envp);
	perror("could not execute the command");
	free(cmd_path);
	exit(127);
}

/*
	Returns an array of the different paths to the executables
	or NULL if the PATH environment variable is not found.
*/
static char	**commands_paths_array(char **envp)
{
	int		i;
	char	**paths;
	char	*path_str;

	path_str = NULL;
	if (envp == NULL)
		return (0);
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == OK)
		{
			path_str = &envp[i][5];
			break ;
		}
		++i;
	}
	if (path_str == NULL)
		return (NULL);
	paths = ft_split(path_str, ':');
	return (paths);
}

/*
	Returns the path to the command given in argument if exists.
	Otherwise displays error and return NULL.
*/
static char	*command_access(char *cmd, char **paths)
{
	int		i;
	char	*cmd_address;
	char	*error;

	if (access(cmd, X_OK) == OK)
		return (cmd);
	i = -1;
	while (paths[++i])
	{
		cmd_address = variadic_strjoin(3, paths[i], "/", cmd);
		if (access(cmd_address, X_OK) == OK)
			return (cmd_address);
		free(cmd_address);
	}
	error = variadic_strjoin(3, "minishell: ", cmd, ": command not found\n");
	ft_putstr_fd(error, STDERR_FILENO);
	free(error);
	return (NULL);
}
