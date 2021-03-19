#include <stdarg.h>
#include <stdio.h>

double ft_sum(int num_cnt, int num_cnt2, ...)
{
	double result = 0.0;
	va_list arg_lst;

	printf("first arg : %d\n", num_cnt);
	printf("second arg : %d\n", num_cnt2);
	
	va_start(arg_lst, num_cnt2);
	for (int i = 0; i < num_cnt; i++)
	{
		result += va_arg(arg_lst, double);
	}
	va_end(arg_lst);
	return result;
}

int main(void)
{
	double sum;

	sum = ft_sum(2, 21, 3.1, 5.2);
	printf("3.1 + 5.2 = %g\n", sum);

	return (0);
}
