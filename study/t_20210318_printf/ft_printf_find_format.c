/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_find_format.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jso <jso@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 20:43:43 by jso               #+#    #+#             */
/*   Updated: 2021/03/19 14:11:53 by jso              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_init_struct(t_flags *flg)
{
	flg->left = 0;
	flg->zero = 0;
	flg->width = 0;
	flg->dot = 0;
	flg->prcs = 0;
	flg->type = 0;
}

void	ft_printf_check_flag(const char **fmt, t_flags *flg)
{
	while (**fmt == '-' || **fmt == '0')
	{
		if (**fmt == '-')
			flg->left = 1;
		else
			flg->zero = 1;
		++(*fmt);
	}
}

void	ft_printf_check_width(va_list ap, const char **fmt, t_flags *flg)
{
	if (**fmt == '*' || (**fmt >= '0' && **fmt <= '9'))
	{
		if (**fmt == '*')
		{
			flg->width = va_arg(ap, int);
			++(*fmt);
		}
		else if (**fmt >= '0' && **fmt <= '9')
		{
			while (**fmt >= '0' && **fmt <= '9')
			{
				flg->width = (flg->width * 10) + (**fmt - '0');
				++(*fmt);
			}
		}
		if (flg->width < 0)
		{
			flg->left = 1;
			flg->width *= -1;
		}
	}
}

void	ft_printf_check_pres(va_list ap, const char **fmt, t_flags *flg)
{
	if (**fmt == '.')
	{
		++(*fmt);
		flg->dot = 1;
		if (**fmt == '*')
		{
			flg->prcs = va_arg(ap, int);
			++(*fmt);
		}
		else if (**fmt >= '0' && **fmt <= '9')
		{
			while (**fmt >= '0' && **fmt <= '9')
			{
				flg->prcs = (flg->prcs * 10) + (**fmt - '0');
				++(*fmt);
			}
		}
	}
}

void	ft_printf_find_format(va_list ap, const char *fmt, t_flags *flg)
{
	while (*fmt)
	{
		if (*fmt == '%')
		{
			++fmt;
			ft_printf_init_struct(flg);
			ft_printf_check_flag(&fmt, flg);
			ft_printf_check_width(ap, &fmt, flg);
			ft_printf_check_pres(ap, &fmt, flg);
			ft_printf_check_type(&fmt, flg);
			ft_printf_printing_types(ap, flg);
		}
		else
		{
			ft_printf_putchar(*fmt);
		}
	++fmt;
	}		
}
