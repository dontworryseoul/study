/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_center.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jso <jso@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 22:17:56 by jso               #+#    #+#             */
/*   Updated: 2021/03/19 20:49:13 by jso              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_check_type(const char **f, t_flags *flg)
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
		flg->type = **f;
}

void	ft_printf_printing_types(va_list ap, t_flags *flg)
{
	if (flg->type == 'p')
		ft_printf_ptr((long long)va_arg(ap, void *), flg);
}
