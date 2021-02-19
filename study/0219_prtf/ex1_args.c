#include <stdio.h>

void printNumbers(int args, ...)
{
	printf("%d\n ", args);
}

int main(void)
{
	
	printNumbers(1, 10);
	printNumbers('a', 10);
	printNumbers("a", 10);

	return (0);
}
