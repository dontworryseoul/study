/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jso <jso@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 21:55:57 by jso               #+#    #+#             */
/*   Updated: 2021/01/01 01:37:53 by jso              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char *s_ptr;
	unsigned char uch_data;

	s_ptr = (unsigned char*)s;
	uch_data = (unsigned char)c;
	while (n--)
	{
		*s_ptr++ = uch_data;
	}
	return (s);
}
