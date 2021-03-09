#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
    int num = 0;

    ft_printf("\n");
    num = ft_printf("Hello%cworld",'+');
    ft_printf("\n\n=======");
    ft_printf("\nstring printing good");
    ft_printf("\n=======");
    ft_printf("\n");
    printf("num : %d\n", num);
	ft_printf("\n");

	/*
	num = 0;
    ft_printf("Hello world");
    num = ft_printf("Hello world");
    ft_printf("\n\n=======");
    ft_printf("\nstring printing good");
    ft_printf("\n=======");
    printf("\n");
    printf("num : %d", num);
	*/
    return (0);
}
