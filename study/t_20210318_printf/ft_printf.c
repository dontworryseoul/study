/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jso <jso@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 04:53:58 by jso               #+#    #+#             */
/*   Updated: 2021/03/19 13:01:19 by jso              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *fmt, ...)
{
	va_list ap;
	t_flags *flg;

	g_ret_value = 0;
	va_start(ap, fmt);
	flg = malloc(sizeof(t_flags));
	ft_printf_find_format(ap, fmt, flg);
	va_end(ap);
	free(flg);
	return(g_ret_value);
}
