#include "pendu.h"

int	verif_dict(char *dict)
{
	int		fd;
	char	c;

	fd = open(dict, O_RDONLY);
	if (!fd)
	{
		ft_putstr("Error : Could'nt open dict file\n");
		return (0);
	}
	while (read(1, &c, 1))
	{
		if ((c < 'a' || c > 'z') && (c != '\n' && c != '0'))
		{
			ft_putstr("Dictionary not in norm");
			ft_putstr("(use flag \"-m dict_norm\" to see more)\n");
			return (0);
			break ;
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
