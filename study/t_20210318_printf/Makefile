# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jso <jso@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/18 20:43:00 by jso               #+#    #+#              #
#    Updated: 2021/03/19 15:40:29 by jso              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
LIB			= ar rcs
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
NAME		= libftprintf.a
INC			= .ft_printf.h

MEM			= ft_printf.c 		\
			  ft_printf_utils.c \
			  ft_printf_find_format.c 	\
			  ft_printf_print_center.c	\
			  ft_printf_ptr.c			\

OBJ			= $(MEM:.c=.o)

.c.o	:
			$(CC) $(CFLAGS) -c $< -I$(INC)

$(NAME)	:	$(OBJ)
			$(LIB) $@ $^

all		:	$(NAME)

clean	:
			$(RM) $(OBJ)
fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
