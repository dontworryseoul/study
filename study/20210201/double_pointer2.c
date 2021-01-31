/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_pointer2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jso <jso@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 01:32:01 by jso               #+#    #+#             */
/*   Updated: 2021/02/01 01:42:51 by jso              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void swap_str(char **str)
{
	char *str2 = "42SEOUL42SEOUL42SEOUL";

	*str = str2;
}

int main(void)
{
	char *str;

	str = "42SEOUL";
	swap_str(&str);
	printf("%s\n", str);
	return (0);
}
