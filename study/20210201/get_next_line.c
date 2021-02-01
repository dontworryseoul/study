/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jso <jso@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 19:47:32 by jso               #+#    #+#             */
/*   Updated: 2021/02/01 19:53:13 by jso              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int		get_next_line(int fd, char **line)
{
	return (0);
}

int main(void)
{
	char	*line;
	int		fd;

	fd = open("text.txt", O_RDONLY);
	printf("%d\n",fd);
	close(fd);
	return (0);
}
