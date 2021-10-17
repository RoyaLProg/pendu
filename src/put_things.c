#include "pendu.h"

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

void	ft_putnbr(int nb)
{
	unsigned int	v;

	v = nb;
	write_nbr(v);
}

void	put_letter(char *word, char *guessed, int l)
{
	if (is_guessed(word[l], guessed))
		write(1, &word[l], 1);
	else
		ft_putstr("_");
}
