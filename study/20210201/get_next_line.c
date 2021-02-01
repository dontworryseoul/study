/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jso <jso@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 19:47:32 by jso               #+#    #+#             */
/*   Updated: 2021/02/01 23:25:42 by jso              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	char buf[10 + 1];

	read(fd, buf, 10); 
//	buf[10] = '\0';
	*line = ft_strdup(buf);
	return (0);
}

int main(void)
{
	char	*line;
	int		fd;

	line = "hello";
	fd = open("text.txt", O_RDONLY);
	get_next_line(fd, &line);
	printf("%s\n", line);
	close(fd);
	return (0);
}
