/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jso <jso@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 11:26:49 by jso               #+#    #+#             */
/*   Updated: 2021/02/02 17:29:59 by jso              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strdup(const char *s)
{
	char	*s_cpy;
	size_t	len;

	len = ft_strlen(s);
	if (s == 0)
		return (NULL);
	if (!(s_cpy = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_memcpy(s_cpy, s, len);
	s_cpy[len] = '\0';
	return (s_cpy);
}

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
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_cpy;
	unsigned char	*src_cpy;

	dest_cpy = (unsigned char *)dest;
	src_cpy = (unsigned char *)src;
	if (dest == src)
		return (dest);
	while (n--)
	{
		*dest_cpy++ = *src_cpy++;
	}
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (*s++)
		++i;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (42)
	{
		if (*s == c)
			return ((char *)s);
		if (*s == '\0')
			return (NULL);
		++s;
	}
}
