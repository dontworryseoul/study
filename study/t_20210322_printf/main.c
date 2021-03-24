#include "ft_printf.h"

int main(void)
{
	ft_printf("\nhello%c", 'Y');
	ft_printf("\nhello%4c", 'Y');
	ft_printf("\nhello%-4c", 'Y');

	ft_printf("\nhello%%");
	ft_printf("\nhello%4%");
	ft_printf("\nhello%-4%");

	ft_printf("\nhello%s", 0);
	ft_printf("\nhello%.4s", 0);
	ft_printf("\nhello%-4s", "string");
	return (0);
}
