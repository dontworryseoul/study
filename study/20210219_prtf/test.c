#include <stdio.h>

int main(void)
{
	static int *num[10];

	printf("%d\n", sizeof(num));
	printf("%d\n", sizeof(num[0]));
	printf("%p\n", num);
	printf("%p\n", num[0]);
	printf("=====\n");
	printf("%p\n", &num[1]);
	printf("%p\n", &num[2]);
	printf("%p\n", num[3]);
	printf("%p\n", num[4]);
	return (0);
}
