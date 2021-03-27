/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_ft_print_d_u_x_p.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jso <jso@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 19:25:18 by jso               #+#    #+#             */
/*   Updated: 2021/03/28 00:36:30 by jso              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_divide_num(unsigned int num, int base_num)
{
	int cnt;

	cnt = 0;
	while (num)
	{
		num = num / base_num;
		++cnt;
	}
	return (cnt);
}

int		ft_count_number(unsigned int num, int base_num)
{
	int	len;
	int wid_0_len;

	len = ft_divide_num(num, base_num);
	if (0 < (g_flg.prcs - len))
		len = g_flg.prcs;
	wid_0_len = g_flg.width - len;
	if (wid_0_len > 0 && g_flg.zero && g_flg.left == 0 && g_flg.prcs < 0)
		len = wid_0_len;
	if (!g_flg.prcs && !num)
		--len;
	return (len);
}

void	ft_print_recur(unsigned int u_num, int n_base, char *base)
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

void	ft_comb_u(unsigned int u_num, int n_base, char *base)
{
	int		len;

	len = ft_divide_num(u_num, TEN);
	printf("56%d", len);

	ft_print_recur(u_num, n_base, base);
}

void	ft_print_u(unsigned int u_num)
{
	char	*base;
	int		len;

	printf("71%d", len);
	base = "0123456789";
	len = ft_count_number(u_num, TEN);
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
