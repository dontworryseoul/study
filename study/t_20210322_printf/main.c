#include "ft_printf.h"

int main(void)
{

	unsigned int u_num;

	u_num = 0xFFFFFFFF;
	ft_printf("\n%u", u_num);
	ft_printf("\n%u", 0);
	ft_printf("\n%05.3u", 1);
	ft_printf("\n");

	/* c, s type
	ft_printf("\nhello%c", 'Y');
	ft_printf("\nhello%4c", 'Y');
	ft_printf("\nhello%-4c", 'Y');

	ft_printf("\nhello%%");
	ft_printf("\nhello%4%");
	ft_printf("\nhello%-4%");

	ft_printf("\nhello%s", 0);
	ft_printf("\nhello%.4s", 0);
	ft_printf("\nhello%-4s", "string");
	 c, s type */
	return (0);
}
