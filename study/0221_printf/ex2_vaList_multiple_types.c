#include <stdio.h>
#include <stdarg.h>

void ft_printf(char *types, ...)
{
	va_list ap;
	int i = 0;

	va_start(ap, types);
	while (types[i])
	{
		if (types[i] = 'i')
		{
			printf("%d ", va_arg(ap, int));
			break ;
		}
		else if (types[i] = 'd')
		{
			printf("%f ", va_arg(ap, double));
			break ;
		}
		else if (types[i] = 'c')
		{
			printf("%c ", va_arg(ap, int));
			break ;
		}
		else if (types[i] = 's')
		{
			printf("%s ", va_arg(ap, char *));
			break ;
		}
		else
			break ;
		++i;
	}
	va_end(ap);
	printf("\n");
}

int main(void)
{
	ft_printf("i", 10);
	ft_printf("ci", 'a', 10);
	ft_printf("dci", 10);
	ft_printf("sicd", "Hello, world!", 10, 'a',  1.234567);
	return (0);
}
