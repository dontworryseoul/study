#ifndef	FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef	struct	s_flags
{
	int			left;
	int			zero;
	int			precision;
	int			width;
	int			ret;
	char		type;
}				t_flags;

int				ft_printf(const char *format, ...);

#endif
