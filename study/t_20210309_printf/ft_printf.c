#include "ft_printf.h"

void printf_rst(va_list ap, char *fmt, t_flags *flags)
{
    while (*fmt)
    {
        if (*fmt != '%')
        {
            write(1, fmt, 1);
            flags->ret++;
        }
        else
            checker(ap, &(++fmt), flags);
    }
}

int ft_printf(const char *format, ...)
{
    t_flags *flags;
    va_list ap;

    flags->ret = 0;
    va_start(ap, format);
    printf_rst(ap, format, flags);
    va_end(ap);
    retrun (flags->ret);
}