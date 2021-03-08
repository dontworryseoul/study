
#include <stdio.h>

void printNumbers(char *args, ...)
{
	printf("%s\n ", args);
}

int main(void)
{
	char *str = "Hello";	

	printNumbers(str, 10);
	return (0);
}
