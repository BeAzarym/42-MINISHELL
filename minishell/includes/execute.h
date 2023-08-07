/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 09:55:40 by angassin          #+#    #+#             */
/*   Updated: 2023/08/07 16:15:46 by angassin         ###   ########.fr       */
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
// // libft and other includes
// # include "../libft/includes/libft.h"

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
void	execution(t_cmd *cmd, char **envp);

// pipex.c
// void		create_process(char *argv, char **envp);
// void		execute(char *argv, char **envp);
// int		lastcmd_process(int argc, char *argv, char **envp, int arg_counter);

// /*									[Utils]								*/

// void		error_exit(char *error_msg);
// int			infile_open(char *file);
// int			outfile_open(char *file);
// void		duplicate(int fd_src, int fd_dest, char *error);

#endif