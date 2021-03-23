/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_center.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jso <jso@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 08:26:02 by jso               #+#    #+#             */
/*   Updated: 2021/03/23 15:29:14 by jso              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_type(const char **f)
{
	if (**f == 'c' ||
			**f == 's' ||
			**f == '%' ||
			**f == 'p' ||
			**f == 'd' || **f == 'i' ||
			**f == 'u' ||
			**f == 'x' ||
			**f == 'X')
		g_flg.type = **f;
}

void	ft_print_types(va_list ap)
{
	if (g_flg.type == 'c')
		ft_print_c(va_arg(ap, int));
	if (g_flg.type == '%')
		ft_print_percent();
}
