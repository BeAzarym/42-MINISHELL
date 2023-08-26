/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 10:00:21 by angassin          #+#    #+#             */
/*   Updated: 2023/08/26 12:50:53 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
/*									[Includes]								*/

# include <signal.h>
# include <sys/errno.h>
// waitpid
# include <sys/errno.h>
# include <sys/wait.h>
// waitpid
# include <sys/wait.h>
// open
# include <fcntl.h>
// readline
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
// sigaction
# include <signal.h>
// chdir
# include <stdbool.h>
# include <unistd.h>
// libft and other includes
# include "../libft/includes/libft.h"
// # include "execute.h"

/*									[Typedefs]								*/

typedef struct s_token_lst
{
	struct s_token		*head;
	struct s_token		*tail;
	int					size;
}						t_tkn_lst;

typedef struct s_token
{
	char				type;
	char				*value;
	struct s_token		*next;
}						t_token;

typedef struct s_env_lst
{
	struct s_env		*head;
	struct s_env		*tail;
	int					size;
}						t_env_lst;

typedef struct s_env
{
	char				*key;
	char				*value;
	struct s_env		*next;
}						t_env;

typedef struct s_cmd_dllst
{
	struct s_cmd		*head;
	struct s_cmd		*tail;
	int					size;
}						t_cmd_dllst;

typedef struct s_redir_node
{
	char				type;
	char				*file;
	struct s_redir_node	*next;
}						t_redir_node;

typedef struct s_redir_lst
{
	struct s_redir_node	*head;
	struct s_redir_node	*tail;
	int					size;
}						t_redir_lst;

typedef struct s_cmd
{
	char				*infile;
	char				*outfile;
	t_redir_lst			*redir_in;
	t_redir_lst			*redir_out;
	char				**cmd;
	struct s_cmd		*next;
}						t_cmd;

/*									[Macros]								*/
# define CHILD 0

enum					e_redirect
{
	STDIN_OUT,
	HEREDOC,
	INFILE,
	TRUNCATE,
	APPEND
};

/*									[Macros]								*/
# define OK 0

/*									[Global]								*/

bool				g_signalset;

/*									[Src]									*/



// parsingerrno
char					**arg_split(char *s, char *sep);
t_token					*create_token(char *word, char type, t_token *lst);
void					print_token(t_token *lst);
t_token					*get_lstlast(t_token *lst);
void					add_back(t_token *src, t_token *new);
void					clear_lst(t_token *lst);
t_token					*init_token(char *value);
t_tkn_lst				*init_tkn_lst(void);
t_tkn_lst				*add_lst_tkn(char *value,
							t_tkn_lst *lst);
int						jump_to_next_sep(char *s, char *sep, int i);
int						escape_quotes(char *str, int n);
char					define_type(char *value);
int						is_sep(char c, char *sep);
int						locate_token(char *value, char *token);
t_tkn_lst				*token_split(t_tkn_lst *stack, t_tkn_lst *new);
t_env_lst				*init_env_lst(void);
t_env_lst				*add_lst_env(char *key, char *value, t_env_lst *lst);
t_env_lst				*init_envp(char **envp);
char					**envp_split(char *str);
void					print_env(t_env_lst *lst);
void					clear_env_lst(t_env *lst);
void					clear_tkn_lst(t_token *lst);
t_tkn_lst				*lexing(char *str);
t_cmd					*init_cmd_struct(void);
t_cmd_dllst				*init_cmd_dllst(void);
t_cmd_dllst				*add_cmd_dllst(t_cmd_dllst *dllst, t_cmd *cmd);
void					print_cmd(t_cmd_dllst *dllst);
t_cmd_dllst				*parsing(t_tkn_lst *lst, t_cmd_dllst *cmd_table);
int						have_redirect_arg(t_tkn_lst *lst);
t_tkn_lst				*handle_redirect(t_tkn_lst *lst, t_cmd *cmd_table);
t_redir_lst				*add_redir_lst(t_redir_lst *lst, t_redir_node *node);
t_redir_node			*init_redir_node(void);
t_redir_lst				*init_redir_lst(void);
void					print_redir(t_redir_lst *lst);
void					extract_data(t_tkn_lst *lst, t_cmd *node);
char					**convert_env_to_exec(t_env_lst *env_lst);
// // execution.c
// int		execution(t_cmd *cmd, char **envp);
// void	execute(t_cmd *argv, char **envp);

// // pipex.c
// void	heredoc(const char *limiter);
// void	create_process(t_cmd *cmd, char **envp);
// int		lastcmd_process(t_cmd *cmd, char **envp, int arg_counter);

// /*									[Utils]								*/

// // exe_utils.c
// void	error_exit(char *error_msg);
// int		infile_open(char *file);
// int		outfile_append_open(char *file);
// int		outfile_truncate_open(char *file);
// void	duplicate(int fd_src, int fd_dest, char *error);

#endif