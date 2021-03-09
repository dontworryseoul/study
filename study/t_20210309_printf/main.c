#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
    int num = 0;
    num = ft_printf("Hello world");
    printf("\n");
    printf("num : %d", num);
    return (0);
}
