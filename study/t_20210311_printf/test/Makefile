CC		= clang
LIB		= ar rcs
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f
NAME	= libftprintf.a
INC		= .ft_printf.h

MEM		= ft_printf.c

OBJ_MEM	= $(MEM:.c=.o)

.c.o:
		$(CC) $(CFLAGS) -c $< -I$(INC)

$(NAME)	: $(OBJ_MEM)
			$(LIB) $@ $^

all		: $(NAME)

clean	:
		$(RM) $(OBJ_MEM)

fclean	: clean
		$(RM) $(NAME)

re		: fclean all

.PHONY	: all clean fclean re
