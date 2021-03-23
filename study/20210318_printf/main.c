#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	ft_printf("\n|%-4.*x|", 0, 0);
	   printf("\n|%-4.*x|<== org", 0, 0);
	printf("\n");
	return (0);
}
