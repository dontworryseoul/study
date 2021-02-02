/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jso <jso@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 15:16:44 by jso               #+#    #+#             */
/*   Updated: 2021/02/02 17:28:51 by jso              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char buf[10 + 1];
	int	get_byte;

	*line = ft_strdup("");
	while (get_byte = read(fd, buf, 10))
	{
		if (ft_strchr(buf, '\n')
		{
			break ;
		}
		buf[get_byte] = '\0';
		*line = ft_strjoin(*line, buf);
	}
	return (0);
}

int main(void)
{
	char	*line;
	int fd;

	fd =  open("text.txt", O_RDONLY);
	get_next_line(fd, &line);
	printf("fd: %d\n", fd);
	printf("%s", line);
	free(line);
	close(fd);
	return (0);
}
