/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x_X.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jso <jso@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 08:33:22 by jso               #+#    #+#             */
/*   Updated: 2021/03/22 05:52:26 by jso              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_print_0_padding(t_flags *flg)
{
	int len;

	len = flg->len;
	if (flg->prcs > len)
	{
		len = (flg->prcs) - len;
		while (len-- > 0)
		{
			++(flg->len);
			ft_printf_putchar('0');
		}
	}
	if ((flg->width) - len > 0)
	{
		len = (flg->width) - len;
		if (flg->zero && !flg->left && !flg->prcs && len--)
		{
			ft_printf_putchar('0');
			++(flg->len);
		}
	}
}

void	ft_printf_x_X_padding(t_flags *flg)
{
	int len;

	len = flg->width - flg->len;
	if (0 < flg->width && !flg->zero)
	{
		while (len-- > 0)
			ft_printf_putchar(' ');
	}
}

void	ft_printf_x_X(unsigned int num, t_flags *flg)
{
	flg->len = ft_printf_num_len(num, flg, 16);
	if (flg->left)
	{
		ft_printf_print_0_padding(flg);
		ft_printf_ptr_hex(num, flg);
		ft_printf_x_X_padding(flg);
	}
	else
	{
		ft_printf_x_X_padding(flg);
		ft_printf_print_0_padding(flg);
		ft_printf_ptr_hex(num, flg);
	}
}
