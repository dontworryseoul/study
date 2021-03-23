/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c_s_per.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jso <jso@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 08:39:55 by jso               #+#    #+#             */
/*   Updated: 2021/03/23 19:20:01 by jso              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void	ft_print_s(char *str)
{
	int len;
	int cp_len;

	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	if (len > g_flg.prcs && (-1 != g_flg.prcs))
		len = g_flg.prcs;
	cp_len = len;
	if (g_flg.left)
	{
		while (len-- && str)
		{
			ft_printf_putchar(*str);
			++str;
		}
		ft_padding(cp_len);
	}
	else
	{
		ft_padding(cp_len);
		while (len-- && str)
		{
			ft_printf_putchar(*str);
			++str;
		}
	}
}
