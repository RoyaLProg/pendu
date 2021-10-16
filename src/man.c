#include "pendu.h"

void	get_man(char *asked)
{
	int		fd;
	char	*line;

	fd = open("../mans/manual.txt", O_RDONLY);
	if (fd == -1)
		return (0);
	while (readline(fd, line))
	{
		if (line[0] == '*')
		{
			if (strcmp(&line[3], asked) == 0)
			{
				ft_putstr("\n");
				while (readline(fd, line) && line[0] != '*')
				{
					ft_putstr(line);
					ft_putstr("\n");
					free(line);
				}
				return (1);
			}
		}
		free(line);
	}
	return (0);
}
