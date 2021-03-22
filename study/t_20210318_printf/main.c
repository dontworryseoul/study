#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	ft_printf("\n|%-4.*x|", 4, 0);
	ft_printf("\n|%-4.*x|", 3, 0);
	ft_printf("\n|%-4.*x|", 2, 0);
	ft_printf("\n|%-4.*x|", 1, 0);
	   printf("\n|%-4.*x|<== org", 4, 0);
	printf("\n");
	return (0);
}
