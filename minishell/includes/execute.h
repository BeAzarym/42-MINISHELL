/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2023/08/25 15:47:03 by angassin         ###   ########.fr       */
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

/*									[Src]									*/

// signal.c
void	ignore_shell_signal(void);
void	set_sigint_in_child(int signal);

// execution.c
int		execution(t_cmd *cmd, char **envp);
void	execute(t_cmd *argv, char **envp);

// pipex.c
void	heredoc(const char *limiter);
void	create_process(t_cmd *cmd, char **envp);
int		lastcmd_process(t_cmd *cmd, char **envp, int arg_counter);

/*									[Utils]								*/

// exe_utils.c
void	error_exit(char *error_msg);
int		infile_open(char *file);
int		outfile_append_open(char *file);
int		outfile_truncate_open(char *file);
void	duplicate(int fd_src, int fd_dest, char *error);

#endif