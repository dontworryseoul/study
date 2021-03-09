#ifndef FT_PRINTF_H
# define ft_PRINTF_H

# include <stdarg.h>

typedef struct  s_flags
{
    int     ret;
}           t_flags;

int ft_printf(const char *str, ...);

#endif
