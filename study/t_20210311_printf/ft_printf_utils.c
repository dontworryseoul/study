#include "ft_printf.h"

void printf_padding(int byte, t_flags *flags)
{
	char 	padding_char;
	int		i;

	padding_char = ' ';
	i = 0;
	flags->padding_byte = flags->width - byte;
	if (flags->zero == 1 && flags->type == '%' && flags->left == 0)
		padding_char = '0';
	while (flags->padding_byte-- > 0)
	{
		write(1, &padding_char, 1);
		flags->ret_value++;
	}
}
