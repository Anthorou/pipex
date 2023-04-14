# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 17:05:36 by aroussea          #+#    #+#              #
#    Updated: 2023/04/04 16:38:28 by aroussea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SOURCE = ft_bzero.c \
		 ft_isalnum.c \
		 ft_isalpha.c \
		 ft_isascii.c \
		 ft_isdigit.c \
		 ft_isprint.c \
		 ft_memcpy.c \
		 ft_memmove.c \
		 ft_memset.c \
		 ft_strchr.c \
		 ft_strlcat.c \
		 ft_strlcpy.c \
		 ft_strlen.c \
		 ft_tolower.c \
		 ft_toupper.c \
		 ft_strrchr.c \
		 ft_strncmp.c \
		 ft_memchr.c \
		 ft_memcmp.c \
		 ft_strnstr.c \
		 ft_atoi.c \
		 ft_calloc.c \
		 ft_strdup.c \
		 ft_substr.c \
		 ft_strjoin.c \
		 ft_strtrim.c \
		 ft_split.c \
		 ft_itoa.c \
		 ft_strmapi.c \
		 ft_striteri.c \
		 ft_putchar_fd.c \
		 ft_putstr_fd.c \
		 ft_putendl_fd.c \
		 ft_putnbr_fd.c \
		 ft_lstnew_bonus.c \
		 ft_lstsize_bonus.c \
		 ft_lstlast_bonus.c \
		 ft_lstadd_back_bonus.c \
		 get_next_line.c \
		 ft_count_words.c \
		 ft_abs.c \
		 get_all_line.c \

HEADER = libft.h
OBJS = $(SOURCE:.c=.o)

all: $(NAME)

%.o : %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
	
$(NAME): $(OBJS)
	$(info Allo toi!)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	$(info Bien le bonjour!)
	
clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all bonus 