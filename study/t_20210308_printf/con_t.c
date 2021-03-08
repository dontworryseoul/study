#include <stdio.h>
void test(const char **te)
{
	++*te;
}

int	main(void)
{
	const char *fff = "hell";
	char * ddd = "world";

	test(&fff);
	printf("%s\n", fff);
	return (0);
}
