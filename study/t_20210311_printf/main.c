#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	int ret;
	int i = 2;
	
	while (i--)
	{
		//ret = ft_printf("Hello%-5cWorld", '+');
		ret = ft_printf("|hello%-5cworld|", '+');
		printf("\n");
		printf("0123456789\n");
		printf("return value : %d", ret);
		printf("\n");
		printf("\n");
	}
	return (0);
}
