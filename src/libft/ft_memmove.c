/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jso <jso@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 16:51:52 by jso               #+#    #+#             */
/*   Updated: 2021/01/02 17:25:35 by jso              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_cpy;
	unsigned char	*src_cpy;

	dest_cpy = (unsigned char *)dest;
	src_cpy = (unsigned char *)src;
	if (dest_cpy == src_cpy)
		return (dest);
	if (dest_cpy > src_cpy)
	{
		dest_cpy = dest_cpy + n;
		src_cpy = src_cpy + n;
		while (n-- > 0)
			*(--dest_cpy) = *(--src_cpy);
	}
	else if (dest_cpy < src_cpy)
	{
		dest = ft_memcpy(dest_cpy, src_cpy, n);
	}
	return (dest);
}
