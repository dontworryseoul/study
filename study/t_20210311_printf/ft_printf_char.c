#include "ft_printf.h"

void	printf_char(va_list ap, t_flags *flags)
{
	char ch;

	ch = va_arg(ap, int);
	if (flags->left)
	{
		write(1, &ch, 1);
		flags->ret_value++;
		printf_padding(1, flags);
	}
	else
	{
		printf_padding(1, flags);
		write(1, &ch, 1);
		flags->ret_value++;
	}
}
