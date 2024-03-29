#include "pendu.h"

int	verif_dict(char *dict)
{
	int		fd;
	char	c;

	if (!dict)
		return (1);
	fd = open(dict, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Error : Could'nt open dict file\n");
		return (0);
	}
	while (read(fd, &c, 1) && c != 0)
	{
		write(1, &c, 1);
		if ((c < 'a' || c > 'z') && (c != 10 && c != 13))
		{
			ft_printf("	Dictionary not in norm \
(use flag \"-m DICT_NORM\" to see more)\n");
			close(fd);
			return (0);
		}
	}
	close(fd);
	return (1);
}

int	is_guessed(char c, char *guessed)
{
	int	i;
	int	len;
	int	adjust;

	if (guessed[0] == 0)
		return (0);
	len = ft_strlen(guessed);
	if (c >= 'A' && c <= 'Z')
		adjust = 32;
	else
		adjust = -32;
	i = 0;
	while (i < len)
	{
		if (c == guessed[i] || c + adjust == guessed[i])
			return (1);
		i++;
	}
	return (0);
}
