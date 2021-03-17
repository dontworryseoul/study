/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jso <jso@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:35:19 by jso               #+#    #+#             */
/*   Updated: 2021/03/17 22:43:46 by jso              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_rst(va_list ap, const char *fmt, t_flags *flg)
{
	
}

int		ft_printf(const char *fmt, ...)
{
	va_list ap;
	t_flags *flg;

	flg = malloc(sizeof(t_flags));
	g_ret_value = 0;
	va_start(ap, fmt);
	ft_printf_rst(ap, fmt, flg);
	va_end(ap);
	free(flg);
	return(g_ret_value);
}
