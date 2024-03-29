# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angassin <angassin@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/23 00:20:00 by angassin          #+#    #+#              #
#    Updated: 2023/10/08 19:16:23 by angassin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



#-------------------------------COLORS------------------------------------------

NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'
BLUE='\033[1;94m'
RED='\033[1;91m'

#-------------------------------VARIABLES---------------------------------------

NAME		= minishell

CC			= gcc

# CPPFLAGS 	= -I$(HOME)/.brew/opt/readline/include # Darwin
 CPPFLAGS 	= -I/opt/homebrew/opt/readline/include # M1Pro
# LDFLAGS 	= -L$(HOME)/.brew/opt/readline/lib	# Darwin
 LDFLAGS		= -L/opt/homebrew/opt/readline/lib # M1Pro

CFLAGS		= -Wall -Wextra -Werror

DEBUG		= 0

SANI		= 0

ifeq ($(SANI), 1)
	CFLAGS += 	-fsanitize=address -fsanitize=undefined \
				-fno-sanitize-recover=all	-fsanitize=float-divide-by-zero \
				-fsanitize=float-cast-overflow -fno-sanitize=null \
				-fno-sanitize=alignment
	DEBUG = 1
endif

ifeq ($(DEBUG), 1)
	CFLAGS += -g3
endif

#--------------------------------SOURCES----------------------------------------

SRC			= 	$(MINISHELL_SRC) $(UTILS_SRC)

LIBFT_A 	= 	libft.a
LIBFT_DIR 	= 	libft/
LIBFT		= 	$(addprefix libft/, $(LIBFT_A))
READLINE	=	 -lreadline 

MINISHELL	=	builtins/builtin.c builtins/unset.c builtins/unset_utils.c builtins/echo.c builtins/exit.c \
				builtins/export.c builtins/export_utils.c builtins/cd.c\
				execution/execution.c execution/pipex.c execution/execute.c execution/redir.c \
				execution/wait.c execution/here_doc.c \
				signals/signals.c signals/signal_functions.c \
				lexing/lexer.c \
				lexing/arg_split.c \
				lexing/check_arg.c \
				lexing/token.c \
				lexing/token_utils.c \
				lexing/env.c \
				lexing/env_utils.c \
				lexing/parser.c \
				lexing/parser_utils.c \
				lexing/subst_env.c \
				lexing/redirect_handler.c lexing/redir_struct.c \
				lexing/expander.c lexing/expander_utils.c \
				lexing/quote_handler.c lexing/quote_checker.c \
				minishell.c 
				
MINISHELL_SRC	= $(addprefix src/, $(MINISHELL))

UTILS		= 	exe_utils.c files_utils.c lexing_utils.c
UTILS_SRC	= 	$(addprefix utils/, $(UTILS))

OBJ			= 	$(SRC:.c=.o)

#---------------------------------RULES-----------------------------------------

%o: %c
	@echo $(GRAY)"Compiling...";
	@$(CC) $(CFLAGS) $(CPPFLAGS) -Iincludes  -c $< -o  $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo $(CURSIVE)$(GRAY) "     - Making libft..." $(NONE)
	@make -C $(LIBFT_DIR)
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
	@$(CC) $(CFLAGS)  $(OBJ) $(LIBFT)  $(LDFLAGS) $(CPPFLAGS) $(READLINE) -o $(NAME)
	@echo $(GREEN)"- Compiled -"$(NONE)

exe: all
	@make -C ./ clean
	@echo "     - Executing $(NAME)... \n"
	@./$(NAME)
	@echo "\n     - Done -"

debug : fclean
	make DEBUG=1
	
sanitize : fclean
	make SANI=1

clean:
	@echo $(CURSIVE)$(GRAY) "     - Removing object files..." $(NONE)
	@rm -rf $(OBJ) $(BONUS_OBJ)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@echo $(CURSIVE)$(GRAY) "     - Removing $(NAME)..." $(NONE)
	@rm -rf $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all debug exe clean fclean re bonus
