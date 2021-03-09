#include "ft_printf.h"

void printf_rst(va_list ap, char *format)
{

}

int ft_printf(const char *format, ...)
{
    t_flags *flags;
    va_list ap;

    flags->ret = 0;
    va_start(ap, format);
    printf_rst(ap, format);
    va_end(ap);
    retrun (flags->ret);
}