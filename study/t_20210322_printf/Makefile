# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jso <jso@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/22 07:11:42 by jso               #+#    #+#              #
#    Updated: 2021/03/23 12:36:45 by jso              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	cc

LIB		=	ar rcs

CFLAGS 	=	-Wall -Wextra -Werror

RM		=	rm -f

NAME	=	libftprintf.a

INC		=	.ft_printf.h

MEM		= 	ft_printf.c		\
			ft_find_fmt.c		\
			ft_printf_center.c	\
			ft_printf_c_s_per.c	\
			ft_printf_utils.c	\

OBJ		=	$(MEM:.c=.o)

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
