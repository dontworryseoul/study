/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jso <jso@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 14:46:49 by jso               #+#    #+#             */
/*   Updated: 2021/03/21 23:49:40 by jso              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_recur_ptr(long long p_hex, char *base)
{
	if (p_hex > 15)
		ft_printf_recur_ptr(p_hex / 16, base);
	ft_printf_putchar(base[p_hex % 16]);
}
void	ft_printf_padding(int len)
{
	while (len-- > 0)
		ft_printf_putchar(' ');
}

void	ft_printf_ptr_hex(long long p_hex, t_flags *flg, char sw)
{
	char *base;

	base = "0123456789abcdef";
	if (sw == 'X')
		base = "0123456789ABCDEF";
	if (sw == 'h')
	{
		ft_printf_putchar(ASCII_ZERO);
		ft_printf_putchar(ASCII_SMALL_X);
	}
	if (flg->dot && p_hex == 0 && flg->width > 0)
		ft_printf_putchar('0');
	else if (flg->dot && p_hex == 0)
		;
	else
		ft_printf_recur_ptr(p_hex, base);
}

int		ft_printf_num_len(long long num, t_flags *flg, int base)
{
	int i;

	i = 0;
	if ((flg->dot == 0 && num == 0) || num == 0)
		++i;
	while (num)
	{
		num = num / base;
		++i;
	}
	return (i);
}

void	ft_printf_ptr(long long p_hex, t_flags *flg)
{
	int	len;

	len = 0;
	len = ft_printf_num_len(p_hex, flg, 16);
	len = flg->width - 2 - len;
	if (flg->left)
	{
		ft_printf_ptr_hex(p_hex, flg, 'h');
		ft_printf_padding(len);
	}
	else
	{
		ft_printf_padding(len);
		ft_printf_ptr_hex(p_hex, flg, 'h');
	}
}
