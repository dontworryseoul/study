/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_per.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jso <jso@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 01:45:11 by jso               #+#    #+#             */
/*   Updated: 2021/03/14 03:26:51 by jso              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_per(t_flags *flags)
{
	if (flags->left)
	{
		write(1, "%", 1);
		ft_printf_padding(1, flags);
		flags->ret_value++;
	}
	else
	{
		ft_printf_padding(1, flags);
		write(1, "%", 1);
		flags->ret_value++;
	}
}
