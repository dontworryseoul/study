/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jso <jso@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 16:04:53 by jso               #+#    #+#             */
/*   Updated: 2021/01/31 19:18:35 by jso              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int fd;
	char buf[100];

	fd = open(argv[1], O_RDONLY);
	read(fd, buf, 10);
	printf("%s\n", buf);
	close(fd);
	return (0);
}
