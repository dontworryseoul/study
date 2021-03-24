/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_u_x_p.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jso <jso@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 19:25:18 by jso               #+#    #+#             */
/*   Updated: 2021/03/24 12:31:29 by jso              ###   ########.fr       */
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

void	ft_print_u(unsigned int u_num)
{
	char	*base;
	int		len;

	base = "0123456789";
	len = ft_count_number(u_num, 10);
	if (g_flg.left)
	{
		ft_get_u(u_num, 10, base);
		ft_padding(len);
	}
	else
	{
		ft_padding(len);
		ft_get_u(u_num, 10, base);
	}
}
