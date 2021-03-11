#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct	s_flags
{
	int			left;
	int			zero;
	int			precision;
	int			width;
	int			ret_value;
	char		type;
}				t_flags;

int				ft_printf(const char *format, ...);

#endif
