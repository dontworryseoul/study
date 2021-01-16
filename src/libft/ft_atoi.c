/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jso <jso@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 03:15:57 by jso               #+#    #+#             */
/*   Updated: 2021/01/10 23:13:35 by jso              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_isspace(const char *ch)
{
	return (*ch == ' ' || *ch == '\t' || *ch == '\n' ||
			*ch == '\v' || *ch == '\f' || *ch == '\r');
}

static int	is_in_range(const char *str)
{
	if (str[0] == '-')
	{
		if (ft_strlen(&str[1]) >= 10)
		{
			if (ft_strncmp(&str[1], "2147483648", 10) > 0)
				return (0);
		}
	}
	else
	{
		if (ft_strlen(&str[0]) >= 10)
		{
			if (ft_strncmp(str, "2147483647", 10) > 0)
				return (-1);
		}
	}
	return (1);
}

int			ft_atoi(const char *nptr)
{
	int				conv_num;
	unsigned char	neg;

	neg = '+';
	conv_num = 0;
	if (is_in_range(nptr) != 1)
		return (is_in_range(nptr));
	while (ft_isspace(nptr))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
		neg = (*nptr++ == '-') ? '-' : '+';
	while (ft_isdigit(*nptr))
		conv_num = conv_num * 10 + (*nptr++ - '0');
	if (neg == '-')
		return (long long int)(conv_num * -1);
	else
		return (long long int)(conv_num);
}
