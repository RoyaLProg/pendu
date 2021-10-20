#include "pendu.h"

void	write_nbr(unsigned int v)
{
	if (v < 10)
	{
		v += 48;
		write(1, &v, 1);
		return ;
	}
	write_nbr(v / 10);
	write_nbr(v % 10);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

int	count_word(const char *dict)
{
	int		count;
	int		file;
	char	c;

	file = open(dict, O_RDONLY);
	if (file == -1)
		return (1);
	count = 0;
	while (read(file, &c, 1))
		if (c == '\n')
			count++;
	close(file);
	return (count);
}

char	ft_getc(char c)
{
	while (1)
		if (read(2, &c, 1) && c != 0)
			return (c);
}

void	ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != 0)
	{
		dest[i] = src[i];
		dest[i + 1] = 0;
		i++;
	}
}
