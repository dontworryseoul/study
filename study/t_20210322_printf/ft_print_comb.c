/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jso <jso@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 00:23:37 by jso               #+#    #+#             */
/*   Updated: 2021/03/30 12:32:23 by jso              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_0_prcs(int len)
{
	while (g_flg.prcs > len++)
		ft_printf_putchar('0');
}

void	ft_print_0_padding(int len)
{
	int cp_len;

	cp_len = len;
	if (g_flg.left == 0 && g_flg.zero == 1 && g_flg.prcs < 0)
	{
		while (cp_len-- > 0)
			ft_printf_putchar('0');
	}
}

void	ft_print_recur(long long u_num, int n_base, char *base)
{
	if (u_num >= n_base)
		ft_print_recur(u_num / n_base, n_base, base);
	ft_printf_putchar(base[u_num % n_base]);
}

void	ft_comb_u(long long u_num, int n_base, char *base)
{
	int		len;
	int		cp_len;

	if (base[16] == 'p')
	{
		ft_printf_putchar('0');
		ft_printf_putchar('x');
	}
	if (u_num < 0)
		ft_printf_putchar('-');
	len = ft_divide_num(u_num, n_base);
	ft_print_0_prcs(len);
	cp_len = g_flg.width - len;
	if (u_num < 0)
	{
		--cp_len;
		u_num *= -1;
	}
	ft_print_0_padding(cp_len);
	if (!(g_flg.prcs == 0 && u_num == 0))
		ft_print_recur(u_num, n_base, base);
}
