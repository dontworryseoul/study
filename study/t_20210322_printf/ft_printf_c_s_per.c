/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c_s_per.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jso <jso@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 08:39:55 by jso               #+#    #+#             */
/*   Updated: 2021/03/23 15:08:51 by jso              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_padding(int byte)
{
	char  padding_char;

	if (g_flg.type == '%' && g_flg.zero && !g_flg.left)
		padding_char = '0';
	else
		padding_char = ' ';
	if (0 < (g_flg.width - byte))
	{
		g_flg.width = g_flg.width -byte;
		while (g_flg.width--)
			ft_printf_putchar(padding_char);
	}
}

void	ft_print_c(int ch)
{
	int byte;

	byte = 1;
	if (g_flg.left)
	{
		ft_printf_putchar(ch);
		ft_padding(byte);
	}
	else
	{
		ft_padding(byte);
		ft_printf_putchar(ch);
	}
}

void	ft_print_percent(void)
{
	int byte;

	byte = 1;
	if (g_flg.left)
	{
		ft_printf_putchar('%');
		ft_padding(byte);
	}
	else
	{
		ft_padding(byte);
		ft_printf_putchar('%');
	}
}
