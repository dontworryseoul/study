#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

typedef struct  s_flags
{
    int     ret;
}           t_flags;

int ft_printf(const char *str, ...);

#endif
