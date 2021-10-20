#include "pendu.h"

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
	int		nb;
	char	*line;

	srand(time(NULL));
	line = NULL;
	nb = rand() % count_word(dict);
	i = -1;
	fd = open(dict, O_RDONLY);
	if (fd == -1)
		return ;
	while (++i < nb)
	{
		line = readline(fd, line);
		if (line[0] == 0)
			return ;
		free(line);
	}
	word = malloc(ft_strlen(line) + 1);
	if (word == NULL)
		return ;
	ft_strcpy(word, line);
	free(line);
	close(fd);
}

int	finish(char *word, char *guessed)
{
	int	i;

	i = 0;
	while (i < ft_strlen(word))
	{
		if (!is_guessed(word[i], guessed))
			return (0);
	}
	return (1);
}

void	ft_game(t_game game)
{
	int		count;
	char	c;

	count = 0;
	c = 0;
	choose_word(game.dict, game.word);
	while (!finish(game.word, game.guessed))
	{
		ft_putstr("Try : ");
		ft_putnbr(count);
		ft_putstr("\n\n\n");
		affichage(game.word, game.guessed);
		ft_putstr("\n\n\nPress any caraters on your keyboard");
		ft_getc(c);
		if (!is_guessed(c, game.guessed))
		{
			game.guessed[count] = c;
			count++;
		}
		else
			ft_putstr("charater already guessed");
		clear();
	}
}
