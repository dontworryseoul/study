#include "ft_printf.h"

int main(void)
{
	int u_num = 198;
	int ret;

	ret = ft_printf("%-10s", "hello");
	ft_printf("\n");
	printf("\nret: %d", ret);
	return (0);
}
