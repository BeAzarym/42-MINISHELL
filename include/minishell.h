#ifndef MINISHELL_H
# define MINISHELL_H

# include "../src/libft/libft.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>

enum				e_redirect
{
	IN = 1,
	OUT = 2,
	APPND = 3
};

typedef struct s_token_lst
{
	struct s_token	*head;
	struct s_token	*tail;
	int				size;
}					t_tkn_lst;

typedef struct s_token
{
	char			type;
	char			*value;
	struct s_token	*next;
}					t_token;

typedef struct s_env_lst
{
	struct s_env	*head;
	struct s_env	*tail;
	int				size;
}					t_env_lst;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}					t_env;

typedef struct s_cmd_node
{
	struct s_cmd	*head;
	struct s_cmd	*tail;
	int				size;
}					t_cmd_node;

typedef struct s_cmd
{
	int				type_in;
	int				type_out;
	char			*infile;
	char			*outfile;
	char			**cmd;
	struct s_cmd	*next;
}					t_cmd;

char				**arg_split(char *s, char *sep);
t_token				*create_token(char *word, char type, t_token *lst);
void				print_token(t_token *lst);
t_token				*get_lstlast(t_token *lst);
void				add_back(t_token *src, t_token *new);
void				clear_lst(t_token *lst);
t_token				*init_token(char *value);
t_tkn_lst			*init_tkn_lst(void);
t_tkn_lst	*add_lst_tkn(char *value,
						t_tkn_lst *lst);
int					jump_to_next_sep(char *s, char *sep, int i);
int					escape_quotes(char *str, int n);
char				define_type(char *value);
int					is_sep(char c, char *sep);
int					locate_token(char *value, char *token);
t_tkn_lst			*token_split(t_tkn_lst *stack, t_tkn_lst *new);
t_env_lst			*init_env_lst(void);
t_env_lst			*add_lst_env(char *key, char *value, t_env_lst *lst);
t_env_lst			*init_envp(char **envp);
char				**envp_split(char *str);
void				print_env(t_env_lst *lst);
void				clear_env_lst(t_env *lst);
void				clear_tkn_lst(t_token *lst);
t_tkn_lst			*lexing(char *str);
t_cmd				*init_cmd_struct(void);
t_cmd_node			*init_cmd_node(void);
t_cmd_node			*add_cmd_node(t_cmd_node *node, t_cmd *cmd);
void				print_cmd(t_cmd_node *node);
t_cmd_node			*parsing(t_tkn_lst *lst);

#endif
