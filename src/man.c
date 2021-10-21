#include "pendu.h"

void	read_manual(int *fd)
{
	char	c;

	while (read(*fd, &c, 1))
	{
		if (c == '*')
			return ;
		write(1, &c, 1);
	}
}

int	get_man2(char *line, char *asked, int fd)
{
	if (line[0] == '*')
	{
		if (ft_strcmp(&line[3], asked) == 0)
		{
			read_manual(&fd);
			free(line);
			close(fd);
			return (1);
		}
	}
	return (0);
}

int	get_man(char *asked)
{
	int		fd;
	char	*line;
	int		i;

	line = NULL;
	fd = open("mans/manual.txt", O_RDONLY);
	if (fd == -1 || asked == NULL)
		return (0);
	i = 0;
	while (1)
	{
		line = readline(&fd, line);
		if (ft_strcmp(line, "***EOF") == 0)
			break ;
		if (get_man2(line, asked, fd))
			return (1);
		if (line[0] == 0)
			break ;
		free(line);
		i++;
	}
	free(line);
	close(fd);
	return (0);
}
