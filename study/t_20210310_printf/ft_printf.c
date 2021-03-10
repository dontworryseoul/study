#include "ft_printf.h"

static void init_flag(t_flags *flags)
{
	flags->left = 0;
	flags->zero = 0;
	flags->precision = 0;
	flags->width = 0;
	flags->ret = 0;
	flags->type = 0;
}

static void check_fmt(va_list ap, const char **fmt, t_flags *flags)
{
	init_flag(flags);
	check_fmt(ap, *fmt);
	print_all(ap);
}

static void print_rst(va_list ap, const char *fmt, t_flags *flags)
{
	while (*fmt)
	{
		if (*fmt == '%')
			check_fmt(ap, &fmt, flags);
		else
		{
			write(1, fmt, 1);
			++flags->ret;
		}
	++fmt;
	}
}

int	ft_printf(const char *format, ...)
{
	t_flags *flags;
	va_list ap;

	flags = malloc(sizeof(t_flags));
	flags->ret = 0;
	va_start(ap, format);
	print_rst(ap, format, flags);
	va_end(ap);
	free(flags);
	return (flags->ret);
}
