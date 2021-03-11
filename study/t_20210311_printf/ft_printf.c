#include "ft_printf.h"

static void printf_check_format(va_list ap, const char **fmt, t_flags *flags)
{
}

static void	printf_rst(va_list ap, const char *fmt, t_flags *flags)
{
	while (*fmt)
	{
		if (*fmt == '%')
			printf_check_format(ap, &fmt, flags);
		else
		{
			write(1, fmt, 1);
			flags->ret_value++;
		}
	++fmt;
	}
}

int			ft_printf(const char *format, ...)
{
	t_flags *flags;
	va_list ap;

	flags = malloc(sizeof(t_flags));
	flags->ret_value = 0;
	va_start(ap, format);
	printf_rst(ap, format, flags);
	va_end(ap);
	free(flags);
	return (flags->ret_value);
}
