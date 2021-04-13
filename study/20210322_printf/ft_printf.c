/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jso <jso@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 07:18:08 by jso               #+#    #+#             */
/*   Updated: 2021/03/22 08:23:32 by jso              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list ap;

	g_flg.ret_value = 0;
	va_start(ap, fmt);
	ft_find_fmt(ap, fmt);
	va_end(ap);
	return (g_flg.ret_value);
}
