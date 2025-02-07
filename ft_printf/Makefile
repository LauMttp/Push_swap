# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmouttap <lmouttap@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 22:09:10 by lmouttap          #+#    #+#              #
#    Updated: 2025/01/30 16:36:35 by lmouttap         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=ftprintf.a

CC=cc
CC_FLAGS=-Wall -Wextra -Werror

RM=rm -f

INC=./includes/
HEADER=	$(INC)../includes/ft_printf.h

SRC=./sources/
SOURCES=$(SRC)ft_printf.c $(SRC)ft_putnbr.c $(SRC)ft_putstr.c $(SRC)ft_putnbr_hexa.c $(SRC)ft_putptr.c

OBJECTS=$(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rcs $(NAME) $(OBJECTS)
	@echo "\033[37;1m$(NAME)         \033[32;1m| creation OK |\033[0;1m"

%.o: %.c $(HEADER)
	@$(CC) $(CC_FLAGS) -c $< -o $@ -I$(INC)

clean:
	@$(RM) $(OBJECTS)
	@echo "\033[37;1mftprintf.a objects \033[33;1m|   supp OK   |\033[0;1m"  

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[37;1m$(NAME)         \033[33;1m|   supp OK   |\033[0;1m"
	@echo "\033[34;1m                      | all cleared |"

re: fclean all

.PHONY: all clean fclean re
