#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	int ret;
	int i = 2;
	
	while (i--)
	{
		ret = ft_printf("Hello World", '+');
		printf("\n");
		printf("return value : %d", ret);
		printf("\n");
		printf("\n");
	}
	return (0);
}
