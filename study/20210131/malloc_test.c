/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jso <jso@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 19:33:13 by jso               #+#    #+#             */
/*   Updated: 2021/01/31 20:19:41 by jso              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	char *ptr;
	int i;

	i = 0;
	ptr = malloc(200);
	ptr[200-1] = '\0';
	printf("size of ptr : %ld\n", sizeof(ptr));
	printf("%p\n", ptr);
	while(i < 201)
	{
		printf("%c, %d |",ptr[i], i);
		++i;
	}
	free(ptr);
	return (0);
}
