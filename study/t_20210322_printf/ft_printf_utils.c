/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jso <jso@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 12:36:55 by jso               #+#    #+#             */
/*   Updated: 2021/03/23 16:34:14 by jso              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_putchar(int c)
{
	write(1, &c, 1);
	++g_flg.ret_value;
}

int		ft_strlen(const char *s)
{
	unsigned int i;

	i = 0;
	while (*s)
	{
		++s;
		++i;
	}
	return (i);
}
