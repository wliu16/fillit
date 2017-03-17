# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wliu <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/29 14:26:26 by wliu              #+#    #+#              #
#    Updated: 2016/12/12 16:17:50 by wliu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = free.c \
	  list.c \
	  min_max.c	\
	  print.c \
	  solver.c \
	  main.c \
	  new.c \
	  readfile.c \
	  functions.c \
	  valid_tetrim.c

O_FILES = free.o \
		  list.o \
		  min_max.o	\
		  print.o \
		  solver.o \
		  main.o \
		  new.o \
		  readfile.o \
		  functions.o \
		  valid_tetrim.o

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
		$(CC) $(FLAGS) -c $(SRC)
		$(CC) $(FLAGS) -o $(NAME) $(O_FILES)

clean:
		/bin/rm -f $(O_FILES)

fclean: clean
		/bin/rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
