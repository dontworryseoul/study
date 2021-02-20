#include <stdarg.h>

int printf_rst(va_list ap, const char *format)
{
	int i;

	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			i += checker(ap, &format[i + 1]);
		else
			write(1, &format[i], 1);
		++i;
	}
		return (i);
}

int ft_printf(const char *format, ...)
{
	int rst;

	va_list ap;
	va_start(ap, format);
	printf_rst(ap, format);
	va_end(ap);
	return (rst);

}

int main(void)
{
	ft_printf("assdfasd%%f %d as %d df %c %s", 1717171717, 15151515, '%', "I did.");
	return (0);
}
