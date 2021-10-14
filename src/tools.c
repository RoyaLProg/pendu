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

int	count_word(const char *dict)
{
	int	count;
	int	file;
	char	c;

	file = open(dict, O_RDONLY);
	if (file == -1)
		return (0);
	count = 0;
	while (c != 0 && read(file, &c, 1))
		if (c == '\n')
			count++;
	close(file);
	return (count);
}

char	getc(char c)
{
	while (1)
		if (read(2, &c, 1) && c != 0)
			return (c);
}

