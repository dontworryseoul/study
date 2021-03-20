/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jso <jso@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 14:46:49 by jso               #+#    #+#             */
/*   Updated: 2021/03/20 09:22:12 by jso              ###   ########.fr       */
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
void	ft_printf_padding(int len)
{
	while (len-- > 0)
		ft_printf_putchar(' ');
}

void	ft_printf_ptr_z_x(long long p_hex, t_flags *flg)
{
	char *base;

	base = "0123456789abcdef";
	ft_printf_putchar(ASCII_ZERO);
	ft_printf_putchar(ASCII_SMALL_X);
	if(!flg->dot && !p_hex)
		ft_printf_recur_ptr(p_hex, base);
}

void	ft_printf_ptr(long long p_hex, t_flags *flg)
{
	int	len;

	len = 0;
	len = ft_printf_num_len(p_hex, 16);
	len = flg->width - len - 2;
	if (flg->left)
	{
		ft_printf_ptr_z_x(p_hex,flg);
		ft_printf_padding(len);
	}
	else
	{
		ft_printf_padding(len);
		ft_printf_ptr_z_x(p_hex,flg);
	}
}
