/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:48:25 by angassin          #+#    #+#             */
/*   Updated: 2023/08/30 13:44:36 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H
/*									[Includes]								*/

# include <signal.h>

# include <sys/errno.h>
// waitpid
# include <sys/wait.h>
// open
# include <fcntl.h>
// other includes
# include "minishell.h"

/*									[Typedefs]								*/



/*									[Macros]								*/
# define CHILD 0

/*									[Global]								*/

bool	g_signalset;

/*									[Src]									*/

// signal.c
void	ignore_shell_signal(void);
void	set_sigint_in_child(int signal);

// execution.c
int		execution(t_cmd *cmd, char **envp);
void	execute(t_cmd *argv, char **envp);

// pipex.c
void	heredoc(const char *limiter);
void	create_process(t_cmd *cmd, char **envp, int fd[2]);
int		lastcmd_process(t_cmd *cmd, char **envp, int arg_counter, int fdout, int fd_pipe[2]);

/*									[Utils]									  */

// exe_utils.c
void	error_exit(char *error_msg);
void	duplicate(int fd_src, int fd_dest, char *error);
// files_utils.c
void	get_input_output(t_cmd_lst *cmd_table);
int		infile_open(char *file);
int		outfile_append_open(char *file);
int		outfile_truncate_open(char *file);


#endif