/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_pad.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jso <jso@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 00:25:57 by jso               #+#    #+#             */
/*   Updated: 2021/03/28 00:44:44 by jso              ###   ########.fr       */
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

int		ft_count_d_padding(long long num, int base_num)
{
	int	len;
	int cp_len;
	int wid_0_len;

	len = ft_divide_num(num, base_num);
	cp_len = len;
	if (num < 0)
		++cp_len;
	wid_0_len = g_flg.width - cp_len;
	while (g_flg.prcs > len++)
		++cp_len;
	while (wid_0_len > 0 && g_flg.zero && !g_flg.left && g_flg.prcs < 0)
	{
		--wid_0_len;
		++cp_len;
	}
	if (!g_flg.prcs && !num)
		--cp_len;
	return (cp_len);
}
