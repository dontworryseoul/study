/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jso <jso@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 00:39:35 by jso               #+#    #+#             */
/*   Updated: 2021/02/01 01:12:45 by jso              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void pointer(char *str)
{
	char *str_1;

	str_1 = "Good day to play.";
	str = str_1;
}

int main(void)
{
	char *str;

	str = "Hello";
	pointer(str);
	printf("%s\n", str);
	return (0);
}
