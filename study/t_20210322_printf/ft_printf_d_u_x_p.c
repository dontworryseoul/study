/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d_u_x_p.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jso <jso@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 19:25:18 by jso               #+#    #+#             */
/*   Updated: 2021/03/28 01:27:06 by jso              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_u(unsigned int u_num)
{
	int		len;

	len = ft_count_padding(u_num, TEN);
	if (g_flg.left)
	{
		ft_comb_u(u_num, TEN, STR_DIGIT);
		ft_padding(len);
	}
	else
	{
		ft_padding(len);
		ft_comb_u(u_num, TEN, STR_DIGIT);
	}
}

void	ft_print_x(unsigned int x_num)
{
	char	*base;
	int		len;

	if (g_flg.type == 'x')
		base = LOWER_X;
	else
		base = UPPER_X;
	len = ft_count_padding(x_num, HEX);
	if (g_flg.left)
	{
		ft_comb_u(x_num, HEX, base);
		ft_padding(len);
	}
	else
	{
		ft_padding(len);
		ft_comb_u(x_num, HEX, base);
	}
}

void	ft_print_p(long long p_num)
{
	int		len;

	len = ft_count_padding(p_num, HEX) + 2;
	if (g_flg.left)
	{
		ft_comb_u(p_num, HEX, STR_POINT);
		ft_padding(len);
	}
	else
	{
		ft_padding(len);
		ft_comb_u(p_num, HEX, STR_POINT);
	}
}

void	ft_print_d(int n_num)
{
	int		len;

	len = ft_count_d_padding(n_num, TEN);
	if (g_flg.left)
	{
		ft_comb_u(n_num, TEN, STR_DIGIT);
		ft_padding(len);
	}
	else
	{
		ft_padding(len);
		ft_comb_u(n_num, TEN, STR_DIGIT);
	}
}
