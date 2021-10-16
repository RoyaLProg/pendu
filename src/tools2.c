#include "pendu.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != 0 && s2[i] != 0)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	clear(void)
{
	int	i;

	i = 0;
	while (i < 10000)
	{
		ft_putstr("\e[1;1H\e[2J");
		i++;
	}
}

int	readline(int fd, char *buf)
{
	char	c;
	char	tmp[100];
	int		i;

	i = 0;
	while (read(fd, &c, 1) && (c != '\n' || c != 0))
	{
		tmp[i] = c;
		tmp[i + 1] = 0;
		i++;
	}
	buf = malloc(ft_strlen(tmp));
	if (!buf)
		return (0);
	ft_strcpy(buf, tmp);
	return (1);
}
