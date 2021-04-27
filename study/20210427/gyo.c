#include <unistd.h>

void ft_newline(void)
{
	write(1, "\n", 1);
}

void ft_gyo(char *s1, char *s2)
{
	int asci[256] = {0};
	int i = 0;
	int j;

	while (s1[i])
	{
		j = 0;
		while (s2[j])
		{
			if (s1[i] == s2[j] && asci[(int)s1[i]] != 1)
			{
				asci[(int)s1[i]] = 1;
				write(1, &s1[i], 1);
			}
			++j;
		}
		i++;
	}
}

int main(int ac, char *av[])
{
	if (ac != 3)
	{
		ft_newline();
		return (0);
	}
	ft_gyo(av[1], av[2]);
	return (0);
}
