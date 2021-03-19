#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	int ret;

	ret = ft_printf("Hello");
	printf("\n");
	printf("ret : %d", ret);
	return (0);
}
