# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angassin <angassin@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/23 00:20:00 by angassin          #+#    #+#              #
#    Updated: 2023/08/08 16:19:10 by angassin         ###   ########.fr        #
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

CFLAGS		= -Wall -Wextra -Werror

DEBUG		= 0

# THREAD_SANI	= 0

SANI		= 0

# ifeq ($(THREAD_SANI), 1)
# 	CFLAGS += -fsanitize=thread
# 	DEBUG = 1
# endif

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

SRC			= $(MINISHELL_SRC) #$(UTILS_SRC)
SRC_BONUS	= $(BONUS_SRC) $(UTILS_SRC)

LIBFT_A 	= libft.a
LIBFT_DIR 	= libft/
LIBFT		= $(addprefix libft/, $(LIBFT_A))

MINISHELL		= main.c builtin.c execution.c pipex.c
MINISHELL_SRC	= $(addprefix src/, $(MINISHELL))

#UTILS		= utils.c
#UTILS_SRC	= $(addprefix utils/, $(UTILS))

#BONUS		= main_bonus.c
#BONUS_SRC	= $(addprefix src/, $(BONUS))

OBJ			= $(SRC:.c=.o)
#BONUS_OBJ	= $(SRC_BONUS:.c=.o)

#---------------------------------RULES-----------------------------------------

%o: %c
	@echo $(GRAY)"Compiling...";
	@$(CC) $(CFLAGS) -Iincludes -c $< -o  $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo $(CURSIVE)$(GRAY) "     - Making libft..." $(NONE)
	@make -C $(LIBFT_DIR)
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -lreadline -o $(NAME)
	@echo $(GREEN)"- Compiled -"$(NONE)

# bonus : $(BONUS_OBJ)
# 	@echo $(CURSIVE)$(GRAY) "     - Making libft..." $(NONE)
# 	@make -C $(LIBFT_DIR)
# 	@$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIBFT) -o $(NAME)
# 	@echo $(GREEN)"- Bonus compiled -"$(NONE)

# exe: all
# 	@make -C ./ clean
# 	@echo "     - Executing $(NAME)... \n"
# 	@./$(NAME) infile "ls -l" "wc -l" outfile
# 	@echo "\n     - Done -"

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