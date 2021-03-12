/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jso <jso@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 20:49:39 by jso               #+#    #+#             */
/*   Updated: 2021/03/12 13:37:41 by jso              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_flag(const char **fmt, t_flags *flags)
{
	while (**fmt == '-' || **fmt == '0')
	{
		if (**fmt == '-')
			flags->left = 1;
		else 
			flags->zero = 1;
		++*fmt;
	}
}

void	ft_check_width(va_list ap, const char **fmt, t_flags *flags)
{
	if (**fmt == '*' || (**fmt >= '0' && **fmt <= '9'))
	{
		if (**fmt == '*')
		{
			flags->width = va_arg(ap, int);
			++*fmt;
		}
		else if (**fmt >= '0' && **fmt <= '9')
		{
			while (**fmt >= '0' && **fmt <= '9')
			{
				flags->width = (flags->width * 10) + (**fmt - '0');
				++*fmt;
			}
		}
		if (flags->width < 0)
		{
			flags->left = 1;
			flags->width *= -1;
		}
	}
}

void	ft_check_precs(va_list ap, const char **fmt, t_flags *flags)
{
	if (**fmt == '.')
	{
		++*fmt;
		flags->dot = 1; 
		if (**fmt == '*')
		{
			flags->precision = va_arg(ap, int);
			++*fmt;
		}
		else if (**fmt >= '0' && **fmt <= '9')
		{
			while (**fmt >= '0' && **fmt <= '9')
			{
				flags->precision = (flags->precision * 10) + (**fmt - '0');
				++*fmt;
			}
		}
	}
}

void	ft_check_type(const char **f, t_flags *flags)
{
	if (**f == 'c' ||
			**f == 's' ||
			**f == '%' ||
			**f == 'p' ||
			**f == 'd' ||
			**f == 'i' ||
			**f == 'u' ||
			**f == 'x' ||
			**f == 'X')
		flags->type = **f;
}

void	ft_check_format(va_list ap, const char **fmt, t_flags *flags)
{
	ft_check_flag(fmt, flags);
	ft_check_width(ap, fmt, flags);
	ft_check_precs(ap, fmt, flags);
	ft_check_type(fmt, flags);
}
