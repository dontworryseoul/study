#include <unistd.h>

void new_line(void)
{
	write(1, "\n", 1);
}

void gyo(char *s1, char *s2)
{
	int asci[256];
	int i, j;

	i = 0;
	while (i < 256)
		asci[i++] = 0;
	i = 0;
	while (s1[i])
	{
		j = 0;
		while (s2[j] && s1[i] != s2[j])
			j++;
		if (s1[i] == s2[j] && asci[(int)s1[i]] == 0)
		{
			asci[(int)s1[i]] = 1;
			write(1, s1 + i, 1);
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
	gyo(av[1], av[2]);
	new_line();
}
