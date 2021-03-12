#include "ft_printf.h"

void	ft_init_struct(t_flags *flags)
{
	flags->left = 0;
	flags->zero = 0;
	flags->precision = 0;
	flags->dot = 0;
	flags->width = 0;
	flags->type = 0;
	flags->padding_byte = 0;
}

void	ft_printf_all(va_list ap, t_flags *flags)
{
	if (flags->type == 'c')
		ft_printf_char(ap, flags);
	/*
	else if (flags->type == 's')
		printf_string(ap, flags);
	else if (flags->type == 'd')
		printf_deciaml(ap, flags);
	else if (flags->type == '%')
		printf_percent(ap, flags);
	*/
}

void	ft_printf_rst(va_list ap, const char *fmt, t_flags *flags)
{
	while (*fmt)
	{
		if (*fmt == '%')
		{
			++fmt;
			ft_init_struct(flags);
			ft_check_format(ap, &fmt, flags);
			ft_printf_all(ap, flags);
		}
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
	ft_printf_rst(ap, format, flags);
	va_end(ap);
	free(flags);
	return (flags->ret_value);
}
