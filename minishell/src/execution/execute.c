/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:12:10 by angassin          #+#    #+#             */
/*   Updated: 2023/10/02 17:49:58 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execute.h"

static char	**commands_paths_array(char **envp);
static char	*command_access(char *cmd, char **paths);
static char	*check_path(char *cmd, char **paths);

/*
	Executes the command sent in argument, execve returns only in case
	of failure as the execve() function overlays the current process image
	with a new process image.
	// ft_putstr_fd("in execute\n", 2);
*/
void	execute(t_cmd *cmd, char **envp)
{
	char				**paths;
	char				*cmd_path;
	struct sigaction	sa;


	if (cmd == NULL)
		error_exit("parsing of the command failed");
	set_sigint_in_child(SIGINT);
	if (sigaction(SIGQUIT, &sa, NULL) == -1
		|| sigaction(SIGINT, &sa, NULL) == -1)
		error_exit ("signal_problem");
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
	char	*error;
	char	*cmd_address;

	cmd_address = check_path(cmd, paths);
	if (cmd_address != NULL)
		return (cmd_address);
	if (access(cmd, X_OK) == OK)
		return (cmd);
	if (cmd[0] == '/')
	{
		error = variadic_strjoin(3, "minishell: ", cmd, ": command not found\n");
		ft_putstr_fd(error, STDERR_FILENO);
		free(error);
		return (NULL);
	}
	else
	{
		error = variadic_strjoin(3, "minishell: ", cmd, ": command not found\n");
		ft_putstr_fd(error, STDERR_FILENO);
	}
	free(error);
	return (NULL);
}

static char	*check_path(char *cmd, char **paths)
{
	int		i;
	char	*cmd_address;

	i = -1;
	while (paths[++i])
	{
		cmd_address = variadic_strjoin(3, paths[i], "/", cmd);
		if (access(cmd_address, X_OK) == OK)
			return (cmd_address);
		free(cmd_address);
	}
	return (NULL);
}
