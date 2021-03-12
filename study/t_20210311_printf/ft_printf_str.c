/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jso <jso@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 20:50:00 by jso               #+#    #+#             */
/*   Updated: 2021/03/12 15:18:10 by jso              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_printf_str(va_list ap, t_flags *flags)
{
	char	*str;
	int		len;

	str = va_arg(ap, char *);
	if (str == 0)
		str = "(null)";
	len = ft_strlen(str);
	if (len > flags->precision && 0 < flags->precision && flags->dot)
		len = flags->precision;
	if (flags->left)
	{
		write(1, str, len);
		flags->ret_value += len;
		ft_printf_padding(len, flags);
	}
	else
	{
		ft_printf_padding(len, flags);
		write(1, str, len);
		flags->ret_value += len;
	}
}
