NAME = minishell

SRC = 	minishell.c \
		lexing/lexer.c \
		lexing/arg_split.c \
		lexing/token.c \
		lexing/token_utils.c \
		lexing/env.c \
		lexing/env_utils.c \
		utils.c \

SRCS = $(addprefix $(SRC_DIR)/, $(SRC))		

OBJS = $(SRCS:.c=.o)

LIBFT = make -C ./src/libft

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
	$(CC) $(CFLAGS) -Isrc/libft -I $(INC_DIR) -o $(NAME) $(OBJS) -Lsrc/libft -lft -lreadline

clean:
	$(RM) $(OBJS)
	make -C ./src/libft clean

fclean: clean
	$(RM) $(NAME)
	make -C ./src/libft fclean

re: fclean all

.PHONY: all re clean fclean