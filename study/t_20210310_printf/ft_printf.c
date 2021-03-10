#include "ft_printf.h"

static void check_fmt(va_list ap, const char **fmt, t_flags *flags)
{
}

static void print_rst(va_list ap, const char *fmt, t_flags *flags)
{
	while (*fmt)
	{
		if (*fmt == '%')
			check_fmt(ap, &fmt, flags);
		else
			write(1, fmt, 1);
		++fmt;
		++flags->ret;
	}
}

int	ft_printf(const char *format, ...)
{
	t_flags *flags;
	va_list ap;

	flags->ret = 0;
	flags = malloc(sizeof(t_flags));
	va_start(ap, format);
	print_rst(ap, format, flags);
	va_end(ap);
	free(flags);
	return (flags->ret);
}
