/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jso <jso@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 14:46:49 by jso               #+#    #+#             */
/*   Updated: 2021/03/20 08:18:53 by jso              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_num_len(long long num, int base)
{
	int i;

	i = 0;
	while (num)
	{
		num = num / base;
		++i;
	}
	return (i);
}

void	ft_printf_recur_ptr(long long p_hex, char *base)
{
	if (p_hex > 15)
		ft_printf_recur_ptr(p_hex / 16, base);
	ft_printf_putchar(base[p_hex % 16]);
}
void	ft_print_padding(int len)
{
	while (len-- > 0)
		ft_printf_putchar(' ');
}

void	ft_printf_ptr(long long p_hex, t_flags *flg)
{
	char *base;
	int	len;

	len = 0;
	base = "0123456789abcdef";
	len = ft_printf_num_len(p_hex, 16);
	len = flg->width - len - 2;
	if (flg->dot && p_hex == ZERO)
		;
	else if (flg->left)
	{
		ft_printf_putchar(ASCII_ZERO);
		ft_printf_putchar(ASCII_SMALL_X);
		ft_printf_recur_ptr(p_hex, base);
		ft_print_padding(len);
	}
	else
	{
		while (len-- > 0)
			ft_printf_putchar(' ');
		ft_printf_putchar('0');
		ft_printf_putchar('x');
		ft_printf_recur_ptr(p_hex, base);
	}
}
