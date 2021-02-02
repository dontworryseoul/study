/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jso <jso@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 15:16:44 by jso               #+#    #+#             */
/*   Updated: 2021/02/02 15:37:31 by jso              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char buf[10 + 1];

	read(fd, buf, 10);
	buf[10] = '\0';
	*line = ft_strdup(buf);
	return (0);
}

int main(void)
{
	char	*line;
	int fd;

	fd =  open("text.txt", O_RDONLY);
	get_next_line(fd, &line);
	printf("fd: %d\n", fd);
	printf("buf: %s\n", line);
	close(fd);
	return (0);
}
