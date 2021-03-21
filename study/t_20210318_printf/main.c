#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	char *ch;
	int num;
	int num1;

	num = 0;
	num1 = 0;
	ch = "";

	/*
	ft_printf("\n%x", 768955);
	printf("\n%x", 768955);
	printf("\n");

	*/
	num1 = ft_printf("cpy: %.p|", NULL);
	printf("\n");
	printf("\norg: %.p|", NULL);
	printf("\n");

	num1 = ft_printf("cpy: %-16.p|", NULL);
	printf("\n");
	printf("\norg: %-16.p|", NULL);
	printf("\n");

	num1 = ft_printf("cpy: %-6p|", ch);
	printf("\n");
	printf("\norg: %-6p|", ch);
	printf("\n");
	printf("0123456789");
	printf("0123456789");
	printf("0123456789");
	//num = printf("%p",ch);
	//printf("\n");
	num1 = ft_printf("min: %p|", NULL);
	printf("\n");
	printf("\nnum1: %d", num1);
	printf("\n");
	printf("\norg: %p|", NULL);
	printf("\n");

	num1 = ft_printf("min: %.p|", ch);
	printf("\n");
	printf("\nnum1: %d", num1);
	printf("\n");
	printf("\norg: %.p|", ch);
	printf("\n");
	/*
	printf("te: %d\n"), 
	printf("|===num : %d", num);
	num = ft_printf("%p", &ret);
	printf("\n");

	printf("num : %d", num);
	printf("\n");

	printf("Where");
	printf("\n");
	
	printf("org:");
	num = printf("%p", &ret);
	printf("\n");
	printf("num : %d", num);
	*/
	return (0);
}
