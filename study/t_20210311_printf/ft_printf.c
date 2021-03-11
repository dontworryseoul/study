#include "ft_printf.h"

static void	init_struct(t_flags *flags)
{
	flags->left = 0;
	flags->zero = 0;
	flags->precision = 0;
	flags->width = 0;
	flags->type = 0;
	flags->empty_padding_byte = 0;
}

static void	check_type(const char **f, t_flags *flags)
{
	if (**f == 'c' ||
			**f == 's' ||
			**f == '%' ||
			**f == 'p' ||
			**f == 'd' ||
			**f == 'i' ||
			**f == 'u' ||
			**f == 'x' ||
			**f == 'X')
		flags->type = **f;
}

void printf_padding(int byte, t_flags *flags)
{
	char 	padding_char;
	int		i;

	padding_char = ' ';
	i = 0;
	flags->empty_padding_byte = flags->width - byte;
	if (flags->zero == 1 && flags->type == '%' && flags->left == 0)
		padding_char = '0';
	while (flags->empty_padding_byte--)
	{
		write(1, &padding_char, 1);
		flags->ret_value++;
	}
}

static void	printf_char(va_list ap, t_flags *flags)
{
	char ch;

	ch = va_arg(ap, int);
	if (flags->left)
	{
		write(1, &ch, 1);
		flags->ret_value++;
		printf_padding(1, flags);
	}
}

static void	printf_all(va_list ap, t_flags *flags)
{
	if (flags->type == 'c')
		printf_char(ap, flags);
	/*
	else if (flags->type == 's')
		printf_string(ap, flags);
	else if (flags->type == 'd')
		printf_deciaml(ap, flags);
	else if (flags->type == '%')
		printf_percent(ap, flags);
		*/
}

static void	printf_check_flag(va_list ap, const char **fmt, t_flags *flags)
{
	while (**fmt == '-' || **fmt == '0')
	{
		if (**fmt == '-')
			flags->left = 1;
		else 
			flags->zero = 1;
		++*fmt;
	}
}

static void	printf_check_width(va_list ap, const char **fmt, t_flags *flags)
{
	if (**fmt == '*' || (**fmt >= '0' && **fmt <= '9'))
	{
		if (**fmt == '*')
		{
			flags->width = va_arg(ap, int);
			++*fmt;
		}
		else if (**fmt >= '0' && **fmt <= '9')
		{
			while (**fmt >= '0' && **fmt <= '9')
			{
				flags->width = (flags->width * 10) + (**fmt - '0');
				++*fmt;
			}
		}
	}
}

static void printf_check_precision(va_list ap, const char **fmt)
{
}

static void	printf_check_format(va_list ap, const char **fmt, t_flags *flags)
{
	++*fmt;
	init_struct(flags);
	printf_check_flag(ap, fmt, flags);
	printf_check_width(ap, fmt, flags);
	printf_check_precision(ap, fmt);
	check_type(fmt, flags);
	printf_all(ap, flags);
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
