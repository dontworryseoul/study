#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	int ret;
	int i = 3;
	while (i--)
	{
	ret = ft_printf("Hello%cWorld", '+');
	printf("\n");
	printf("return value : %d", ret);
	printf("\n");
	printf("\n");
	}

	/*
	i = printf("Hello%cWorld", '+');
	printf("\n");
	printf("i: %d", i);
	*/
	return (0);
}
