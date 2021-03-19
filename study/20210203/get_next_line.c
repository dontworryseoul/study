/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jso <jso@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 20:05:03 by jso               #+#    #+#             */
/*   Updated: 2021/02/04 00:49:12 by jso              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "fcntl.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


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

int	get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	char		*tmp;
	char		*tmp_rtn;
	int			get_byte;
	char		flg;
	static char *remainder;

	flg = 1;
	*line = "\0"; 
	if (remainder)
		*line = ft_strdup(remainder);
	else
		*line = ft_strdup("");
	while (flg && (get_byte = read(fd, buf, BUFFER_SIZE)))
	{
		buf[BUFFER_SIZE] = '\0';
		if ((tmp_rtn = ft_strchr(buf, '\n')))
		{
			*tmp_rtn = '\0';
			flg = 0;
			++tmp_rtn;
			remainder = ft_strdup(tmp_rtn);
		}
		tmp = *line;
		*line = ft_strjoin(*line, buf) ;
		free(tmp);
	}
	if (get_byte == 1)
		return (1);
	else if (get_byte == -1)
		return (-1);
	return (0);
}

int main(void)
{
	char	*line;
	int		fd;

	fd = open("../20210201/text.txt", O_RDONLY);
	get_next_line(fd, &line);
	printf("%s\n", line);

	get_next_line(fd, &line);
	printf("%s\n", line);
	free(line);
	close(fd);
	system("leaks a.out > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");
	return (0);
}
