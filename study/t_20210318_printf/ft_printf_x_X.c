/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x_X.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jso <jso@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 08:33:22 by jso               #+#    #+#             */
/*   Updated: 2021/03/21 22:26:56 by jso              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_print_0_padding(int len, t_flags *flg)
{
	if ((flg->prcs > len) || (flg->zero && (flg->width > len)))
	{
		if (flg->prcs > len)
			len = flg->prcs - len;
		else
			len = flg->width - len;
		while (len-- > 0)
			ft_printf_putchar('0');
	}
}

void	ft_printf_x_X_padding(int len, t_flags *flg)
{
	if (len < flg->width && !flg->zero)
	{
		len = flg->width - len;
		while (len-- > 0)
			ft_printf_putchar(' ');
	}
}

void	ft_printf_x_X(unsigned int num, t_flags *flg)
{
	char	sw;
	int		len;

	sw = 'x';
	if (flg->type == 'X')
		sw = 'X';
	len = ft_printf_num_len(num, flg, 16);
	if (flg->left)
	{
		ft_printf_print_0_padding(len, flg);
		ft_printf_ptr_hex(num, flg, sw);
		ft_printf_x_X_padding(len, flg);
	}
	else
	{
		ft_printf_print_0_padding(len, flg);
		ft_printf_x_X_padding(len, flg);
		ft_printf_ptr_hex(num, flg, sw);
	}
}
