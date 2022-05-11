# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: catperei <catperei@42Lisboa.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/17 16:31:03 by catperei          #+#    #+#              #
#    Updated: 2022/04/17 16:31:37 by catperei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 	=	./ft_printf.c		\
			./ft_printf_utils.c \
			./ft_printf_utils_1.c

OBJS 	= $(SRCS:c=o)
NAME	= libftprintf.a
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

.PHONY: all bonus clean fclean re

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all
