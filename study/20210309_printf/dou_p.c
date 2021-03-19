#include <stdio.h>
void test(const char **te)
{
	++(*te);
}

int	main(void)
{
	const char *fff = "hell";

	printf("bef: %s\n", fff);
	printf("fff p: %p\n", fff);
	test(&fff);
	printf("%s\n", fff);
	printf("fff P: %p\n", fff);
	return (0);
}
