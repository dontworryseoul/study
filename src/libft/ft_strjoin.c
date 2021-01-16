/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jso <jso@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:32:40 by jso               #+#    #+#             */
/*   Updated: 2021/01/06 15:35:16 by jso              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr_str;
	size_t	len_s1;
	size_t	len_s2;

	if (s1 == 0 || s2 == 0)
		return (0);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	ptr_str = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (ptr_str == 0)
		return (0);
	ft_memcpy(ptr_str, s1, len_s1);
	ft_memcpy(&ptr_str[len_s1], s2, len_s2);
	ptr_str[len_s1 + len_s2] = 0;
	return (ptr_str);
}
