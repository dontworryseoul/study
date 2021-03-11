#include "ft_printf.h"

static void init_struct(t_flags *flags)
{
	flags->left = 0;
	flags->zero = 0;
	flags->precision = 0;
	flags->width = 0;
	flags->type = 0;
}

static void check_type(const char **fmt, t_flags *flags)
{
	if (**fmt == 'c' || **fmt == 's' || **fmt == '%' ||
			**fmt == 'p' || **fmt == 'd' || **fmt == 'i' ||
			**fmt == 'u' || **fmt == 'x' || **fmt == 'X')
		flags->type = **fmt;
}

static void print_c(va_list ap, t_flags *flags)
{
	char ch;

	ch = va_arg(ap, int);
	write(1, &ch, 1);
	flags->ret++;
}

static void  print_all(va_list ap, t_flags *flags)
{
	if (flags->type == 'c')
		print_c(ap, flags);
}

static void check_fmt(va_list ap, const char **fmt, t_flags *flags)
{
	++*fmt;
	init_struct(flags);
	check_type(fmt, flags);
	print_all(ap, flags);
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
			flags->ret++;
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
