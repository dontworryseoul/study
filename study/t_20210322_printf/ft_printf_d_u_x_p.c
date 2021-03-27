/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d_u_x_p.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jso <jso@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 19:25:18 by jso               #+#    #+#             */
/*   Updated: 2021/03/26 17:50:35 by jso              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_divide_num(long long num, int base_num)
{
	int cnt;

	cnt = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		num = num / base_num;
		++cnt;
	}
	return (cnt);
}

int		ft_count_padding(long long num, int base_num)
{
	int	len;
	int wid_0_len;

	len = ft_divide_num(num, base_num);
	if (0 < (g_flg.prcs - len))
		len = g_flg.prcs;
	wid_0_len = g_flg.width - len;
	if (wid_0_len > 0 && g_flg.zero && g_flg.left == 0 && g_flg.prcs < 0)
		len = g_flg.width;
	if (!g_flg.prcs && !num)
		--len;
	return (len);
	}

void	ft_print_recur(long long u_num, int n_base, char *base)
{
	if (u_num >= (unsigned int)n_base)
		ft_print_recur(u_num / (unsigned int)n_base, n_base, base);
	ft_printf_putchar(base[u_num % (unsigned int)n_base]);
}

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

void	ft_comb_u(long long u_num, int n_base, char *base)
{
	int		len;

	if (base[16] == 'p')
	{
		ft_printf_putchar('0');
		ft_printf_putchar('x');
	}
	len = ft_divide_num(u_num, n_base);
	ft_print_0_prcs(len);
	ft_print_0_padding(g_flg.width - len);
	if (!(g_flg.prcs == 0 && u_num == 0))
		ft_print_recur(u_num, n_base, base);
}

void	ft_print_u(unsigned int u_num)
{
	char	*base;
	int		len;

	base = "0123456789";
	len = ft_count_padding(u_num, TEN);
	if (g_flg.left)
	{
		ft_comb_u(u_num, TEN, base);
		ft_padding(len);
	}
	else
	{
		ft_padding(len);
		ft_comb_u(u_num, TEN, base);
	}
}

void	ft_print_x(unsigned int x_num)
{
	char *base;
	int len;

	if (g_flg.type == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	len = ft_count_padding(x_num, 16);
	if (g_flg.left)
	{
		ft_comb_u(x_num, 16, base);
		ft_padding(len);
	}
	else
	{
		ft_padding(len);
		ft_comb_u(x_num, 16, base);
	}
}

void	ft_print_p(long long p_num)
{
	char *base;
	int len;

	base = "0123456789abcdefp";
	len = ft_count_padding(p_num, 16) + 2;
	if (g_flg.left)
	{
		ft_comb_u(p_num, 16, base);
		ft_padding(len);
	}
	else
	{
		ft_padding(len);
		ft_comb_u(p_num, 16, base);
	}
}

void	ft_print_d(int n_num)
{
	char *base;

	int len;
	base = "0123456789";
	len = ft_count_padding(n_num, 10);
	printf("\n153: %d", len);
	if (g_flg.left)
	{
		ft_comb_u(n_num, 10, base);
		ft_padding(len);
	}
	else
	{
		ft_padding(len);
		ft_comb_u(n_num, 10, base);
	}
}
