#include "pendu.h"

void	affichage2(char *guessed, int i, int j, int len)
{
	char	*alph;

	alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	if (i > ((len * 2) - 1) + 5 && j % 2 == 0)
	{
		if (i % 2 == 1)
			ft_printf(" ");
		else if ((10 * j / 2) + ((i - (len * 2) - 6) / 2) < ft_strlen(alph))
		{
			if (!is_guessed(alph[(10 * j / 2) + ((i - (len * 2) - 6) / 2)]
					, guessed))
				write(1, &alph[(10 * j / 2) + ((i - (len * 2) - 6) / 2)], 1);
			else
				ft_putstr(" ");
		}
	}
	else if (j % 2 == 0 && (j != 4 || i > ((len * 2) - 2)))
		ft_printf(" ");
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

char	*choose_word(char *dict, char *word)
{
	int		i;
	int		fd;
	int		nb;
	char	*line;

	srand(time(NULL));
	line = NULL;
	nb = rand() % count_word(dict);
	i = -1;
	fd = open(dict, O_RDONLY);
	if (fd == -1)
		return (0);
	while (++i < nb)
	{
		line = readline(&fd, line);
		free(line);
	}
	line = readline(&fd, line);
	word = malloc(ft_strlen(line) + 1);
	if (word == NULL)
		return (0);
	ft_strcpy(word, line);
	free(line);
	close(fd);
	return (word);
}

int	finish(char *word, char *guessed, int count)
{
	int	i;

	i = 0;
	if (count > 1000)
	{
		clear();
		ft_printf("You loose :/");
		return (1);
	}
	while (i < ft_strlen(word))
	{
		if (!is_guessed(word[i], guessed))
			return (0);
		i++;
	}
	return (1);
}

void	ft_game(char *word, char *guessed)
{
	int		count;
	char	c;

	guessed[0] = 0;
	count = 0;
	c = 0;
	while (!finish(word, guessed, count))
	{
		clear();
		ft_printf("Try : %d\n\n\n", count);
		affichage(word, guessed);
		ft_printf("\n\n\nPress any caraters on your keyboard : ");
		c = ft_getc(c);
		if (!is_guessed(c, guessed))
		{
			if (c != 1 && c != '\n' && c != 0)
			{
				guessed[count] = c;
				guessed[count + 1] = 0;
				count++;
			}
		}
	}
}
