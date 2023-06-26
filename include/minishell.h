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
	int redirect;
} t_cmd;

char				**arg_split(char *s, char *sep);
t_token *create_token(char *word, char type, t_token *lst);
void print_chained(t_token *lst);
t_token *get_lstlast(t_token *lst);
void add_back(t_token *src, t_token *new);
void clear_lst(t_token *lst);

#endif