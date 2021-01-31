/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jso <jso@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 18:43:37 by jso               #+#    #+#             */
/*   Updated: 2021/01/31 18:47:34 by jso              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int static_func(void)
{
	static int num = 0;

	++num;
	return (num);
}

int main(void)
{
	printf("%d\n", static_func());
	printf("%d\n", static_func());
	printf("%d\n", static_func());
	printf("%d\n", static_func());
	printf("%d\n", static_func());
	return (0);
}
