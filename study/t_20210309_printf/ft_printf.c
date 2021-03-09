#include "ft_printf.h"
#include <stdio.h>

void    checker(va_list ap, const char **fmt,  t_flags *flags)
{

}

void printf_rst(va_list ap, const char **fmt, t_flags *flags)
{
    while (**fmt != '\0')
    {
        // if (*fmt == '%')
        // {
        //     ++fmt;
        //     checker(ap, &fmt, flags);
        // }
        // else
        // {
            write(1, *fmt, 1);
            flags->ret++;
        // }
        ++*fmt;
    }
}

int ft_printf(const char *format, ...)
{
    t_flags *flags;
    va_list ap;

    flags->ret = 0;
    va_start(ap, format);
    printf_rst(ap, &format, flags);
    //printf("ft_printf: |%s|\n", format);
    va_end(ap);
    return (flags->ret);
}
