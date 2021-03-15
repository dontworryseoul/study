#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
ft_printf("%%");
	//	result : |%|
//		return : 1
printf("\n");
ft_printf("%5%");
//		result : |    %|
	//	return : 5
printf("\n");
ft_printf("%-5%");
		//result : |%    |
//		return : 5
printf("\n");
ft_printf("%-%");
	//	result : |%|
	//	return : 1
printf("\n");
ft_printf("%*%", 5);
	//	result : |    %|
	//	return : 5
printf("\n");
ft_printf("%*%", -5);
	//	result : |%    |
	//	return : 5
printf("\n");
ft_printf("%.5%");
	//	result : |%|
	//	return : 1
printf("\n");
//ft_printf("%.-5%");
	//	warning : invalid conversion specifier '-'
ft_printf("%.*%", -5);
	//	result : |%|
	//	return : 1
printf("\n");
ft_printf("%.%");
		//result : |%|
	//	return : 1
printf("\n");
ft_printf("%.0%");
	//	result : |%|
	//	return : 1
printf("\n");
ft_printf("%05%");
	//	result : |0000%|
	//	return : 5
printf("\n");
ft_printf("%-05%");
	//	result : |%    |
	//	return : 5
/*
ft_printf("% %");
	//	result : |%|
	//	return : 1
printf("\n");
ft_printf("% 05%");
	//	result : |0000%|
	//	return : 5

ft_printf("%#5%");
	//	result : |    %|
	//	return : 5
ft_printf("%+5%");
	//	result : |    %|
	//	return : 5
*/
return (0);
}
