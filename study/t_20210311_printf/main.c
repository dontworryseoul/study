#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
ft_printf("%s\n", "abcde");
ft_printf("%s\n", "");
ft_printf("%s\n", NULL);
ft_printf("%-s\n", "abcde");
ft_printf("%3s\n", "abcde");
ft_printf("%-3s\n", "abcde");
ft_printf("%7s\n", "abcde");
ft_printf("%-7s\n", "abcde");
ft_printf("%*s\n", 7, "abcde");
ft_printf("%*s\n", 0, "abcde");
ft_printf("%*s\n", -7, "abcde");
ft_printf("%.0s\n", "abcde");
ft_printf("%.s\n", "abcde");
ft_printf("%.3s\n", "abcde");
ft_printf("%.7s\n", "abcde");
ft_printf("%3.7s\n", "abcde");
ft_printf("%7.3s\n", "abcde");
ft_printf("%7.9s\n", "abcde");
ft_printf("%7.3s\n", NULL);
return (0);
}
