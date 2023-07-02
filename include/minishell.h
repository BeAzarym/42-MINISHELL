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

typedef struct s_token_stack
{
	struct s_token	*head;
	struct s_token	*tail;
	int				size;
}					t_tkn_stack;

typedef struct s_token
{
	char			type;
	char			*value;
	struct s_token	*next;
}					t_token;

typedef struct s_cmd
{
	char			*cmd;
	char			**arg;
	int				redirect;
}					t_cmd;

char				**arg_split(char *s, char *sep);
t_token				*create_token(char *word, char type, t_token *lst);
void				print_chained(t_token *lst);
t_token				*get_lstlast(t_token *lst);
void				add_back(t_token *src, t_token *new);
void				clear_lst(t_token *lst);
t_token				*init_token(char *value);
t_tkn_stack			*init_stack(void);
t_tkn_stack	*add_stack(char *value,
						t_tkn_stack *stack);
int					jump_to_next_sep(char *s, char *sep, int i);
int					escape_quotes(char *str, int n);
char				define_type(char *value);
int					is_sep(char c, char *sep);
int					locate_token(char *value, char *token);
t_tkn_stack *token_split(t_tkn_stack *stack, t_tkn_stack *new);

#endif
