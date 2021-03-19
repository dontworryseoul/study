/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jso <jso@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 19:47:32 by jso               #+#    #+#             */
/*   Updated: 2021/02/02 02:07:38 by jso              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	char	 		buf[1000 + 1];
	char		 	flg;
	static char		*remainder;
	unsigned char	*p_n;
	size_t			byte_read;
	
	flg = 1;
	if (remainder)
		*line = ft_strdup(remainder);
	else
		*line = ft_strdup("");
	while (flg && (byte_read = read(fd, buf, 1000)))
	{
		buf[byte_read] = '\0';
		if (p_n = ft_strchr(buf, '\n'))
		{
			*p_n = '\0';
			flg = 0;
			++p_n;
			remainder = ft_strdup(p_n);
		}
		*line = ft_strjoin(*line, buf);
	}
	return (0);
}

int main(void)
{
	char	*line;
	int		fd;

	fd = open("text.txt", O_RDONLY);
	get_next_line(fd, &line);
	printf("%s\n", line);

	get_next_line(fd, &line);
	printf("%s\n", line);

	free(line);
	close(fd);

	system("leaks a.out > leaks_result; cat leaks_result | grep leaked && rm -rf leaks_result");

	return (0);
}
