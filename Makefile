# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pifourni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/24 14:13:50 by pifourni          #+#    #+#              #
#    Updated: 2025/08/27 21:35:44 by pifourni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

CC = cc
CFLAGS = -Wall -Wextra  -Iincludes -g -fsanitize=address
LIB = -g -fsanitize=address
SRC = Src/help_parser.c \
	  Src/main.c \
	  Src/parser.c \
	  Src/solve.c \
	  Src/print.c \
	  Src/help_solve.c

OBJ = $(SRC:.c=.o)
NAME = bsq

all: $(OBJ)
	$(CC) -o $(NAME) $+ $(LIB)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm $(OBJ)

fclean: clean
	rm $(NAME)

re: fclean all

