#include <unistd.h>

void new_line(void)
{
	write(1, "\n", 1);
}

void ft_union(char *s1, char *s2)
{
	int asci[256];
	int i;

	i = 0;
	while (i < 256)
		asci[i++] = 0;
	i = 0;
	while (s1[i])
	{
		if (asci[(int)s1[i]] == 0)
		{
			asci[(int)s1[i]] = 1;
			write(1, s1 + i, 1);
		}
		i++;
	}
	i = 0;
	while (s2[i])
	{
		if (asci[(int)s2[i]] == 0)
		{
			asci[(int)s2[i]] = 1;
			write(1, s2 + i, 1);
		}
	i++;
	}	
}

int main(int ac, char *av[])
{
	if (ac != 3)
	{
		new_line();
		return (0);
	}
	ft_union(av[1], av[2]);
	new_line();
}
