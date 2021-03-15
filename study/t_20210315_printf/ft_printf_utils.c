/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jso <jso@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 21:09:51 by jso               #+#    #+#             */
/*   Updated: 2021/03/16 02:14:42 by jso              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_padding(int byte, t_flags *flags)
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

int		ft_strlen(const char *str)	
{
	unsigned int	i;

	i = 0;
	while (*str++)
		++i;
	return (i);
}

int	ft_num_len(int num)
{
	int res_len;

	res_len = 0;
	if (num == 1 << 31)
		return (11);
	if (0 > num)
	{
		num = num * -1;
		++res_len;
	}
	while (0 < num)
	{
		num = num / 10;
		++res_len;
	}
	return (res_len);
}

