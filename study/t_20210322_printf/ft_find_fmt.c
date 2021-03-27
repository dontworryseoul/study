/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_fmt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jso <jso@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 07:37:35 by jso               #+#    #+#             */
/*   Updated: 2021/03/28 01:05:55 by jso              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_struct(void)
{
	g_flg.left = 0;
	g_flg.zero = 0;
	g_flg.prcs = -1;
	g_flg.width = 0;
	g_flg.type = 0;
}

void	ft_check_flgs(const char **fmt)
{
	while (**fmt == '-' || **fmt == '0')
	{
		if (**fmt == '-')
			g_flg.left = 1;
		else
			g_flg.zero = 1;
		++(*fmt);
	}
}

void	ft_check_width(va_list ap, const char **fmt)
{
	if (**fmt == '*' || (**fmt >= '0' && **fmt <= '9'))
	{
		if (**fmt == '*')
		{
			g_flg.width = va_arg(ap, int);
			++(*fmt);
		}
		else if (**fmt >= '0' && **fmt <= '9')
		{
			while (**fmt >= '0' && **fmt <= '9')
			{
				g_flg.width = (g_flg.width * 10) + (**fmt - '0');
				++(*fmt);
			}
		}
		if (g_flg.width < 0)
		{
			g_flg.left = 1;
			g_flg.width *= -1;
		}
	}
}

void	ft_check_prcs(va_list ap, const char **fmt)
{
	if (**fmt == '.')
	{
		++(*fmt);
		g_flg.prcs = 0;
		if (**fmt == '*')
		{
			g_flg.prcs = va_arg(ap, int);
			++(*fmt);
		}
		else if (**fmt >= '0' && **fmt <= '9')
		{
			while (**fmt >= '0' && **fmt <= '9')
			{
				g_flg.prcs = (g_flg.prcs * 10) + (**fmt - '0');
				++(*fmt);
			}
		}
	}
}

void	ft_find_fmt(va_list ap, const char *fmt)
{
	while (*fmt)
	{
		if (*fmt == '%')
		{
			++fmt;
			ft_init_struct();
			ft_check_flgs(&fmt);
			ft_check_width(ap, &fmt);
			ft_check_prcs(ap, &fmt);
			ft_check_type(&fmt);
			ft_print_types(ap);
		}
		else
			ft_printf_putchar(*fmt);
		if (g_flg.ret_value == -1)
			break ;
		++fmt;
	}
}
