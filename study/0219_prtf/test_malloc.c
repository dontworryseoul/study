
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *ch;

	ch = 0;
	ch = (char *)malloc(10);
	printf("mal : %p\n", ch);
	free(ch);

	printf("mal : %p\n", ch);
	ch = 0;
	printf("mal 2: %p\n", ch);

	static int *num[10];

	printf("%p\n", num);
	printf("%p\n", num[0]);
	printf("=====\n");
	printf("%p\n", &num[1]);
	printf("%p\n", &num[2]);
	printf("%p\n", num[3]);
	printf("%p\n", num[4]);
	
	return (0);
}
