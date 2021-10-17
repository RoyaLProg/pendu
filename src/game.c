#include "pendu.h"

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

void	affichage2(char *guessed, int i, int j, int len)
{
	char	*alph;

	alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	if (i > ((len * 2) - 1) + 5 && j % 2 == 0)
	{
		if (i % 2 == 1)
			ft_putstr(" ");
		else if (!is_guessed(alph[(10 * j / 2) + ((i - (len * 2) - 6) / 2)]
				, guessed))
		{
			if ((10 * j / 2) + ((i - (len * 2) - 6) / 2) < ft_strlen(alph))
				write(1, &alph[(10 * j / 2) + ((i - (len * 2) - 6) / 2)], 1);
		}
		else
			ft_putstr(" ");
	}
	else if (j % 2 == 0 && (j != 4 || i > ((len * 2) - 2)))
		ft_putstr(" ");
}

void	affichage(char *word, char *guessed)
{
	int		i;
	int		j;
	int		len;

	j = 0;
	len = ft_strlen(word);
	while (j < 5)
	{
		i = 0;
		while (i < ((len * 2) - 1) + 5 + 19)
		{
			if (i < ((len * 2) - 1) && j == 4)
			{
				if (i % 2 == 1)
					ft_putstr(" ");
				else
					put_letter(word, guessed, i / 2);
			}
			affichage2(guessed, i, j, len);
			i++;
		}
		ft_putstr("\n");
		j++;
	}
}	

void	choose_word(char *dict, char *word)
{
	int		i;
	int		fd;
	int 	nb;
	char	*line;
	fd = open(dict, O_RDONLY);
	nb = rand() % count_word(dict);
	i = 0;
	while(i < nb)
	{
		readline(fd, line);
	}
	word = malloc(ft_strlen(line));
	ft_strcpy(word, line);
	free(line);
}