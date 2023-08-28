/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:35:24 by angassin          #+#    #+#             */
/*   Updated: 2023/08/28 13:28:39 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execute.h"

static char	**commands_paths_array(char **envp);
static char	*command_access(char *cmd, char **paths);

/* 
	Redirects the input and output file descriptors if necessary and execute
	the commands in processes
*/
int	execution(t_cmd *cmd, char **envp)
{
	int			fdin;
	int			fdout;
	int			fd_first_pipe[2];
	t_redir_lst	*out_lst;

	fd_first_pipe[0] = -1;
	fd_first_pipe[1] = -1;
	if (cmd->type_in == HEREDOC)
		heredoc(cmd->cmd[0]);
	else if (cmd->type_in == INFILE)
	{
		fdin = infile_open(cmd->infile);
		duplicate(fdin, STDIN_FILENO, "duplication of the infile failed");
	}
	printf("ONE MORE PRINT: %d\n", cmd->type_out);
	if (cmd->type_out == STDIN_OUT)
		fdout = STDOUT_FILENO;
	else
	{

		out_lst = cmd->redir_out;
		while (out_lst->head != NULL)
		{
			if (out_lst->head->type == TRUNCATE)
				fdout = outfile_truncate_open(out_lst->head->file);
			else if (out_lst->head->type == APPEND)
				fdout = outfile_append_open(out_lst->head->file);
			out_lst->head = out_lst->head->next;
		}
		printf("fdout in execution : %d\n", fdout);	
	}
	while (cmd->next != NULL)
	{
		create_process(cmd, envp, fd_first_pipe);
		cmd = cmd->next;
	}
	return (lastcmd_process(cmd, envp, 2, fdout, fd_first_pipe));
}

/*
	Executes the command sent in argument, execve returns only in case
	of failure as the execve() function overlays the current process image
	with a new process image.
*/
void	execute(t_cmd *cmd, char **envp)
{
	char	**paths;
	char	*cmd_path;
	// char	**cmd;
	struct sigaction	sa;
	
	// if (!argv || !argv[0])
	// 	error_exit("parse error near """);
	// cmd = ft_split(argv->cmd, ' ');
	// if (cmd == NULL)
	// 	error_exit("parsing of the command failed");
	ft_putstr_fd("in execute\n", 2);
	sa.sa_handler = &set_sigint_in_child;
	if (sigaction(SIGINT, &sa, NULL) == -1
		|| sigaction(SIGQUIT, &sa, NULL) == -1)
		error_exit("killed\n");
	paths = commands_paths_array(envp);
	cmd_path = command_access(cmd->cmd[0], paths);
	if (cmd_path == NULL)
	{
		// ft_free_array(cmd);
		ft_free_array(paths);
		exit(127);
	}
	execve(cmd_path, cmd->cmd, envp);
	perror("could not execute the command");
	// ft_free_array(cmd);
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
