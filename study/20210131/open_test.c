/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jso <jso@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 15:43:36 by jso               #+#    #+#             */
/*   Updated: 2021/01/31 15:59:44 by jso              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	int fd;

	fd = open(argv[1], O_RDONLY);
	printf("%d\n", fd);
	close(fd);
	return (0);
}
