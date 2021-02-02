/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jso <jso@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 15:16:44 by jso               #+#    #+#             */
/*   Updated: 2021/02/02 15:17:11 by jso              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{

}

int main(void)
{
	char	*line;
	int fd;

	fd =  open("text.txt", O_RDONLY);
	printf("%d\n", fd);
	close(fd);
	return (0);
}
