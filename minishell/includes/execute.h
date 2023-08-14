/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 09:55:40 by angassin          #+#    #+#             */
/*   Updated: 2023/08/15 14:15:30 by angassin         ###   ########.fr       */
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

typedef struct s_cmd
{
	int				type_in;
	int				type_out;
	char			*infile;
	char			*outfile;
	char			**cmd;
	struct s_cmd	*next;
}				t_cmd;

/*									[Macros]								*/
# define CHILD 0

enum	e_redirect
{
	STDIN_OUT,
	HEREDOC,
	INFILE,
	TRUNCATE,
	APPEND
};

/*									[Src]									*/

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