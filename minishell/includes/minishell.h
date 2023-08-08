/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 10:00:21 by angassin          #+#    #+#             */
/*   Updated: 2023/08/08 16:13:54 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
/*									[Includes]								*/

# include <sys/errno.h>
// waitpid
# include <sys/wait.h>
// open
# include <fcntl.h>
// readline
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
// chdir
# include <unistd.h>

# include <stdbool.h>
// libft and other includes
# include "../libft/includes/libft.h"
# include "execute.h"

/*									[Typedefs]								*/



/*									[Macros]								*/
# define OK 0

/*									[Src]									*/

// builtin.c
int	cd(char *cmd);

/*									[Utils]									*/

#endif