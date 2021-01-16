/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jso <jso@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 19:09:19 by jso               #+#    #+#             */
/*   Updated: 2021/01/05 02:07:49 by jso              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	l_dst;
	size_t	l_src;

	l_src = ft_strlen(src);
	l_dst = ft_strlen(dst);
	if (dst == NULL && size == 0)
		return (l_src);
	if (l_dst >= size)
		return (size + l_src);
	while (*dst && dst++)
		size--;
	while (*src && size > 1)
	{
		*dst++ = *src++;
		size--;
	}
	*dst = '\0';
	return (l_dst + l_src);
}
