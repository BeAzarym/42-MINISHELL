/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:48:25 by angassin          #+#    #+#             */
/*   Updated: 2023/09/25 12:47:00 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H
/*									[Includes]								*/

# include <stdbool.h>
// waitpid
# include <sys/wait.h>
// open
# include <fcntl.h>
// chdir
# include <unistd.h>
// other includes
# include "minishell.h"

/*									[Macros]								*/
# define CHILD 0
# define CLOSED -1

/*									[Global]								*/

extern bool	g_signalset;

/*									[Src]									*/

// signal.c
void	ignore_shell_signal(void);
void	set_sigint_in_child(int signal);
void	set_sigint_in_main(int signal);

// execution.c
int		execution(t_cmd_lst *cmd_lst, t_env_lst *env_lst);
int		builtin_execute(t_env_lst *env_lst, t_cmd *cmd_node, int status);
bool	is_builtin(char *cmd);

// here_doc.c
void	heredoc(t_cmd_lst *cmd_lst);

// pipex.c
void	pipe_execute(t_cmd *cmd, t_env_lst *env_lst, int fd_pipes[2][2]);
int		lastcmd_process(t_cmd_lst *cmd_lst, t_env_lst *env_lst, int fd_pipe[2]);
void	execute(t_cmd *argv, char **envp);
void	lastcmd_dup(t_cmd *cmd_node, int fd_pipes[2]);

/*									[Utils]									  */

// exe_utils.c
void	error_exit(char *error_msg);
void	duplicate(int fd_src, int fd_dest, char *error);
void	pipe_init(int fd_pipes[2][2]);
void	pipe_branching(t_cmd *cmd, int fd_pipes[2][2]);
void	pipe_closing(t_cmd *cmd, int fd_pipes[2][2]);

// files_utils.c
void	get_input_output(t_cmd_lst *cmd_table);
int		infile_open(char *file);
int		outfile_append_open(char *file);
int		outfile_truncate_open(char *file);

#endif