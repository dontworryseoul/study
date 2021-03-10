#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct  s_flags
{
	int		ret;
	int		type;
	int		flags;
}           t_flags;

int ft_printf(const char *str, ...);

#endif
