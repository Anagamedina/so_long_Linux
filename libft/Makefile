# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/20 18:38:08 by anamedin          #+#    #+#              #
#    Updated: 2024/08/01 13:25:05 by anamedin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
ARC = ar -rcs

NAME = libft.a
HEADER = libft.h

SRCS := ft_bzero.c ft_calloc.c ft_split.c ft_strlen.c \
		ft_printf.c ft_hex.c ft_print_string.c ft_putchar.c ft_putnbr.c \
		ft_unsignedint.c

OBJS = $(SRCS:.c=.o)

#Regla implícita
all: $(NAME)

$(NAME): $(OBJS)
	$(ARC) $(NAME) $(OBJS)

%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
