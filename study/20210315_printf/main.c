#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
ft_printf("%d", 12345);
/*
ft_printf("\n");
		//result : |12345|
		//return : 5
ft_printf("%d", -12345);
ft_printf("\n");
		//result : |-12345|
		//return : 6
ft_printf("%3d", 12345);
ft_printf("\n");
		//result : |12345|
		//return : 5
*/
// ft_printf("%7d", 12345);
// ft_printf("\n");
		//result : |  12345|
		//return : 7
/*
ft_printf("%-7d", 12345);
ft_printf("\n");
		//result : |12345  |
		//return : 7
ft_printf("%-d", 12345);
ft_printf("\n");
		//result : |12345|
		//return : 5
ft_printf("%*d", 7, 12345);
ft_printf("\n");
		//result : |  12345|
		//return : 7
ft_printf("%*d", -7, 12345);
ft_printf("\n");
		//result : |12345  |
		//return : 7
ft_printf("%.d", 12345);
ft_printf("\n");
		//result : |12345|
		//return : 5
ft_printf("%.0d", 12345);
ft_printf("\n");
		//result : |12345|
		//return : 5
ft_printf("%.3d", 12345);
ft_printf("\n");
		//result : |12345|
		//return : 5
ft_printf("%.7d", 12345);
ft_printf("\n");
		//result : |0012345|
		//return : 7
ft_printf("%-.7d", 12345);
ft_printf("\n");
		//result : |0012345|
		//return : 7
ft_printf("%-9.7d", 12345);
ft_printf("\n");
		//result : |0012345  |
		//return : 9
ft_printf("%9.7d", 12345);
ft_printf("\n");
		//result : |  0012345|
		//return : 9
ft_printf("%-7.9d", 12345);
ft_printf("\n");
		//result : |000012345|
		//return : 9
ft_printf("%-3.7d", 12345);
ft_printf("\n");
		//result : |0012345|
		//return : 7
ft_printf("%-7.3d", 12345);
ft_printf("\n");
		//result : |12345  |
		//return : 7
ft_printf("%.3d", -12345);
ft_printf("\n");
		//result : |-12345|
		//return : 6
ft_printf("%.7d", -12345);
ft_printf("\n");
		//result : |-0012345|
		//return : 8
ft_printf("%-.7d", -12345);
ft_printf("\n");
		//result : |-0012345|
		//return : 8
ft_printf("%-9.7d", -12345);
ft_printf("\n");
		//result : |-0012345 |
		//return : 9
ft_printf("%-7.9d", -12345);
ft_printf("\n");
		//result : |-000012345|
		//return : 10
ft_printf("%-3.7d", -12345);
ft_printf("\n");
		//result : |-0012345|
		//return : 8
ft_printf("%-7.3d", -12345);
ft_printf("\n");
		//result : |-12345 |
		//return : 7
ft_printf("%0d", 12345);
ft_printf("\n");
		//result : |12345|
		//return : 5
ft_printf("%07d", 12345);
ft_printf("\n");
		//result : |0012345|
		//return : 7
ft_printf("%d", 0);
ft_printf("\n");
		//result : |0|
		//return : 1
ft_printf("%3d", 0);
ft_printf("\n");
		//result : |  0|
		//return : 3
ft_printf("%3.d", 0);
ft_printf("\n");
		//result : |   |
		//return : 3
ft_printf("%03d", 0);
ft_printf("\n");
		//result : |000|
		//return : 3
ft_printf("%09.0d", 12345);
ft_printf("\n");
		//result : |    12345|
		//return : 9
ft_printf("%09.7d", 12345);
ft_printf("\n");
		//result : |  0012345|
		//return : 9
ft_printf("%07.9d", 12345);
ft_printf("\n");
		//result : |000012345|
		//return : 9
ft_printf("%.d", 0);
ft_printf("\n");
		//result : ||
		//return : 0
ft_printf("%.3d", 0);
ft_printf("\n");
		//result : |000|
		//return : 3
ft_printf("% d", 12345);
ft_printf("\n");
		//result : | 12345|
		//return : 6
ft_printf("% d", -12345);
ft_printf("\n");
		//result : |-12345|
		//return : 6
ft_printf("% -d", 12345);
ft_printf("\n");
		//result : | 12345|
		//return : 6
ft_printf("% 3d", 12345);
ft_printf("\n");
		//result : | 12345|
		//return : 6
ft_printf("% 7d", 12345);
ft_printf("\n");
		//result : |  12345|
		//return : 7
ft_printf("%+d", 12345);
ft_printf("\n");
		//result : |+12345|
		//return : 6
ft_printf("%+d", -12345);
ft_printf("\n");
		//result : |-12345|
		//return : 6
ft_printf("%+-d", 12345);
ft_printf("\n");
		//result : |+12345|
		//return : 6
ft_printf("%+-9d", 12345);
ft_printf("\n");
		//result : |+12345   |
		//return : 9
ft_printf("%+9d", 12345);
ft_printf("\n");
		//result : |   +12345|
		//return : 9
ft_printf("%+09d", 12345);
ft_printf("\n");
		//result : |+00012345|
		//return : 9
ft_printf("%+09d", -12345);
ft_printf("\n");
		//result : |-00012345|
		//return : 9
ft_printf("%-+09d", 12345);
ft_printf("\n");
		warning : flag '0' is ignored when flag '-' is present
ft_printf("%+ 09d", 12345);
ft_printf("\n");
		warning : flag ' ' is ignored when flag '+' is present
ft_printf("%+9.7d", 12345);
ft_printf("\n");
		//result : | +0012345|
		//return : 9
ft_printf("%+09.7d", 12345);
ft_printf("\n");
		//result : | +0012345|
		//return : 9
ft_printf("%+7.9d", 12345);
ft_printf("\n");
		//result : |+000012345|
		//return : 10
ft_printf("%+07.9d", 12345);
ft_printf("\n");
		//result : |+000012345|
		//return : 10
ft_printf("%+9.7d", -12345);
ft_printf("\n");
		//result : | -0012345|
		//return : 9
ft_printf("%+09.7d", -12345);
ft_printf("\n");
		//result : | -0012345|
		//return : 9
ft_printf("%+7.9d", -12345);
ft_printf("\n");
		//result : |-000012345|
		//return : 10
ft_printf("%+07.9d", -12345);
ft_printf("\n");
		//result : |-000012345|
		//return : 10
ft_printf("%#d", 0);
ft_printf("\n");
		undefined behavior warning: flag '#' with 'd'
			*/
return (0);
}
