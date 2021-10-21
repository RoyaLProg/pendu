#include <unistd.h>

void	ft_putstr(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	main(void)
{
	char	lol[3];

	lol[0] = 13;
	lol[1] = 10;
	ft_putstr(lol);
}
