#include "ft_printf.h"
#include <stdio.h>

void	print_s(va_list ap, t_flags *flags)
{
	char *str;

	str = va_arg(ap, char *);
	while (*str)
	{
		write(1, str++, 1);
		++flags->ret;
	}
}

void	print_c(va_list ap, t_flags *flags)
{
	char ch;

	ch = va_arg(ap, int);
	write(1, &ch, 1);
	flags->ret++;
}

void	printf_all(va_list ap, t_flags *flags)
{
	if (flags->type == 'c')
		print_c(ap, flags);
	else if (flags->type == 's')
		print_s(ap, flags);
	else if (flags->type == '%')
		print_percent(ap, flags);
}

void	check_type(const char **fmt, t_flags *flags)
{
	if ( **fmt == 'c' || **fmt == 's' || **fmt == '%' ||
			**fmt == 'p' || **fmt == 'd' || **fmt == 'i' || 
			**fmt == 'u' || **fmt == 'x' || **fmt == 'X')
		flags->type = **fmt;
}

void	init_flags(t_flags *flags)
{
	flags->type= 0;
}

void	checker(va_list ap, const char **fmt,  t_flags *flags)
{
	init_flags(flags);
	check_type(fmt, flags);
	printf_all(ap, flags);
}

void	printf_rst(va_list ap, const char **fmt, t_flags *flags)
{
	while (**fmt != '\0')
	{
		if (**fmt == '%')
		{
			++*fmt;
			checker(ap, fmt, flags);
		}
		else
		{
			write(1, *fmt, 1);
			flags->ret++;
		}
		++*fmt;
	}
}

int		ft_printf(const char *format, ...)
{
	t_flags *flags;
	va_list ap;

	flags = malloc(sizeof(t_flags));
	flags->ret = 0;
	va_start(ap, format);
	printf_rst(ap, &format, flags);
	va_end(ap);
	free (flags);
	return (flags->ret);
}
