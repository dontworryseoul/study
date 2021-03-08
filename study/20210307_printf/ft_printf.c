#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	int ret;
	va_list ap;

	ret = 0;
	va_start(ap, format);
	va_end(ap);
	return (ret);
}
