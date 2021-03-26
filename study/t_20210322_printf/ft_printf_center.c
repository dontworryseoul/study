/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_center.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jso <jso@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 08:26:02 by jso               #+#    #+#             */
/*   Updated: 2021/03/25 19:36:42 by jso              ###   ########.fr       */
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
	else if (g_flg.type == '%')
		ft_print_percent();
	else if (g_flg.type == 's')
		ft_print_s(va_arg(ap, char *));
	else if (g_flg.type == 'u')
		ft_print_u(va_arg(ap, unsigned int));
	else if ((g_flg.type == 'x') || (g_flg.type == 'X'))
		ft_print_x(va_arg(ap, unsigned int));
	else if (g_flg.type == 'p')
		ft_print_p((long long)va_arg(ap, void *));
}
