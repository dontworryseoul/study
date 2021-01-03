SRCS	=./ft_memset.c	\
		 ./ft_bzero.c	\
		 ./ft_memcpy.c	\
		 ./ft_memccpy.c	\
		 ./ft_memmove.c	\
		 ./ft_memchr.c	\
		 ./ft_memcmp.c	\
		 ./ft_strlen.c	\
		 ./ft_strlcpy.c	\
		 ./ft_isalpha.c	\
		 ./ft_isdigit.c	\
		 ./ft_isalnum.c	\
		 ./ft_isascii.c	\
		 ./ft_isprint.c	\

SRCS_B	= ./ft_lstnew.c \

NAME	= libft.a
OBJS	= $(SRCS:.c=.o)
OBJS_B	= $(SRCS_B:.c=.o)
INCS	= .
RM		= rm  -f
LIBC	= ar rc
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(INCS)

$(NAME) : $(OBJS)
	$(LIBC) $(NAME) $(OBJS)

all : $(NAME)

bonus : $(NAME) $(OBS_B)
	$(LIBC) $(NAME) $(OBSJ_B)

clean : 
	$(RM) $(OBJS) $(OBJS_B)

fclean : clean
	$(RM) $(NAME) $(bonus)

re : fclean all
