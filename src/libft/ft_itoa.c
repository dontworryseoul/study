/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jso <jso@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 00:38:26 by jso               #+#    #+#             */
/*   Updated: 2021/01/10 23:00:57 by jso              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	int len;

	len = 0;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static char	*ft_atoi_arr(char *str, int n, int len)
{
	while (len--)
	{
		str[len] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}

char		*ft_itoa(int n)
{
	unsigned char	sign;
	char			*str;
	int				len;

	len = 0;
	sign = '+';
	if ((long long)n <= -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
	{
		len++;
		n = n * -1;
		sign = '-';
	}
	len += ft_len(n);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	str = ft_atoi_arr(str, n, len);
	str[0] = (sign == '-') ? '-' : str[0];
	return (str);
}
