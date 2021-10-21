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
	return (0);
}

void	clear(void)
{
	int	i;

	i = 0;
	while (i < 100)
	{
		ft_putstr("\e[1;1H\e[2J");
		i++;
	}
}

void	*readline(int *fd, char *buf)
{
	char	c;
	char	tmp[500];
	int		i;

	i = 0;
	while (read(*fd, &c, 1) && (c != '\n' && c != 0))
	{
		if (c != 13)
		{
			tmp[i] = c;
			tmp[i + 1] = 0;
			i++;
		}
	}
	buf = malloc(ft_strlen(tmp) + 1);
	if (buf == NULL)
		return (0);
	ft_strcpy(buf, tmp);
	return (buf);
}
