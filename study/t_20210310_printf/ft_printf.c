#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_flags *flags;
	va_list ap;

	flags->ret = 0;
	va_start(ap, format);
	print_rst(ap, flags);
	va_end(ap);
	return (ret);
}
