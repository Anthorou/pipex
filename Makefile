# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/30 18:05:32 by aroussea          #+#    #+#              #
#    Updated: 2023/04/14 15:10:06 by aroussea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = pipex
SOURCE = src/main.c \
		 src/free.c \
		 src/parsing.c \
		 
LIB = libft/libft.a
HEADERS	:= -I ./include
OBJS = $(SOURCE:.c=.o)

all: lib $(NAME)

sanit: CFLAGS += -fsanitize=address
sanit: re

lib:
	@make -C libft

%.o : %.c 
	$(CC) -g $(CFLAGS) -o $@ -c $< $(HEADERS)
	
$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIB) $(HEADERS) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@make clean -C libft
	
fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft
	$(info Tous propre!)

re: fclean all

.PHONY: all, clean, fclean, re
