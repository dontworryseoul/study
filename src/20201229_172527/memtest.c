#include <stdio.h>

void	*memset(void *s, int c, size_t n)
{
	size_t i;
	unsigned char *s_cpy;

	s_cpy = (unsigned char *)s;
	i = 0 ;
	while (i < n)
	{
		s_cpy[i] == c;
		i++;
	}
	return (s);
}

int main(void)
{
	char arr1[10] = {'0','1','2','3','4','5','6','7','8','9'};
	char *result;
	
	result = (char *)memset(arr1, '0', sizeof(arr1));
	printf("%s\n", result);
	return (0);
}

