NAME = minishell

SRC = 	minishell.c \
		lexing/lexer.c \
		lexing/arg_split.c \
		lexing/token.c \
		lexing/token_utils.c \
		lexing/env.c \
		lexing/env_utils.c \
		lexing/parser.c \
		lexing/parser_utils.c \
		lexing/redirect_handler.c \
		utils.c \

SRCS = $(addprefix $(SRC_DIR)/, $(SRC))		

OBJS = $(SRCS:.c=.o)

LIBFT = make -C ./libft

SRC_DIR = src
INC_DIR = include

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

CC = gcc

RM = @rm -rf

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:	$(NAME)

$(NAME) : $(OBJS)
	$(LIBFT)
	$(CC) $(CFLAGS) -Ilibft/libft -I $(INC_DIR) -o $(NAME) $(OBJS) -Llibft -lft -lreadline

clean:
	$(RM) $(OBJS)
	make -C ./libft clean

fclean: clean
	$(RM) $(NAME)
	make -C ./libft fclean

re: fclean all

.PHONY: all re clean fclean