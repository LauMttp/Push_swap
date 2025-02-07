# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmouttap <lmouttap@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/13 19:36:59 by lmouttap          #+#    #+#              #
#    Updated: 2025/01/30 16:39:55 by lmouttap         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

CC = cc
CC_FLAGS = -Wall -Wextra -Werror -g

RM = rm -f

INC = ./includes/
HEADER =	$(INC)/push_swap.h

SRC = ./sources/
SOURCES = $(SRC)ft_split.c $(SRC)instructions_2.c $(SRC)instructions.c $(SRC)push_swap.c $(SRC)sort_2.c $(SRC)sort_3.c $(SRC)sort_4.c $(SRC)sort.c $(SRC)stack.c $(SRC)utils.c

OBJECTS = $(SOURCES:.c=.o)

# FT_PRINTF settings
FT_PRINTF_DIR = ./ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/ftprintf.a

all: $(NAME)

$(NAME): $(OBJECTS) $(FT_PRINTF)
	@$(CC) $(OBJECTS) $(FT_PRINTF) -o $(NAME)
	@echo "\033[37;1m$(NAME)         \033[32;1m| creation OK |\033[0;1m"

$(FT_PRINTF):
	@make -C $(FT_PRINTF_DIR)

%.o: %.c $(HEADER)
	@$(CC) $(CC_FLAGS) -c $< -o $@ -I$(INC)

clean:
	@$(RM) $(OBJECTS)
	@make clean -C $(FT_PRINTF_DIR)
	@echo "\033[37;1mftprintf.a objects \033[33;1m|   supp OK   |\033[0;1m"

fclean: clean
	@$(RM) $(NAME) $(FT_PRINTF)
	@make fclean -C $(FT_PRINTF_DIR)
	@echo "\033[37;1m$(NAME)         \033[33;1m|   supp OK   |\033[0;1m"
	@echo "\033[34;1m                      | all cleared |"

re: fclean all

.PHONY: all clean fclean re