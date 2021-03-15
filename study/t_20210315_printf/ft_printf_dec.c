/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jso </var/mail/jso>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 12:23:41 by jso               #+#    #+#             */
/*   Updated: 2021/03/15 21:17:47 by jso              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int num)
{
	if (0 > num)
	{
		write(1, "-", 1);
		num *= -1;
	}
	if (10 > num)
	{
		num = num % 10 + '0';
		write(1, &num, 1);
	}
	else
	{
		if (10 <= num)
			ft_putnbr(num / 10);
		num = num % 10 + '0';
		write(1, &num, 1);
	}
	return (num_len);
}

void	ft_printf_dec(va_list ap, t_flags *flags)
{
	long long int num;
	int num_len;

	num = va_arg(ap, int);
	num_len = ft_num_len(num);
	flags->ret_value = ft_putnbr(num);
}
