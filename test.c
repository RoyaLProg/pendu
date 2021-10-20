#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct s_game
{
	int		tries;
	char	*guessed;
	char	*word;
	char	*dict;
}t_game;

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
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

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != 0 && s2[i] != 0)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	ft_putnbr(int nb)
{
	unsigned int	v;

	v = nb;
	write_nbr(v);
}

void	*readline(int fd, char *buf)
{
	char	c;
	char	tmp[500];
	int		i;

	i = 0;
	while (read(fd, &c, 1) && (c != '\n' && c != 0))
	{
		tmp[i] = c;
		tmp[i + 1] = 0;
		i++;
	}
	buf = malloc(ft_strlen(tmp) + 1);
	if (buf == NULL)
		return (0);
	ft_strcpy(buf, tmp);
	return (buf);
}

void	read_manual(int fd, char *line)
{
	while (1)
	{
		line = readline(fd, line);
		if (line[0] == '*')
			return ;
		ft_putstr(line);
		ft_putstr("\n");
		free(line);
	}
}

int	get_man(char *asked)
{
	int		fd;
	char	*line;
	int		i;

	line = NULL;
	fd = open("mans/manual.txt", O_RDONLY);
	if (fd == -1)
		return (0);
	i = 0;
	while (1)
	{
		line = readline(fd, line);
		if (line[0] == '*')
		{
			if (ft_strcmp(&line[3], asked) == 0)
			{
				read_manual(fd, line);
				return (1);
			}
		}
		if (line[0] == 0)
			return (0);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}

int	is_know_flag(char *flag)
{
	char	c;
	char	*flags;
	int		i;

	flags = "hmd";
	c = flag[0];
	if (c != '-')
		return (0);
	c = flag[1];
	i = 0;
	while (flags[i] != 0)
	{
		if (c == flags[i])
			return (1);
		i++;
	}
	return (0);
}

int	retrieve_flag(char **av, int i, int ac, char *dict)
{
	if (ft_strcmp(av[i], "-d") == 0)
	{
		dict = malloc(ft_strlen(av[i + 1]));
		if (dict == NULL)
			return (0);
		ft_strcpy(dict, av[i + 1]);
		return (1);
	}
	else if (ft_strcmp(av[i], "-h") == 0)
	{
		get_man("USAGE");
		return (0);
	}
	else if (ft_strcmp(av[i], "-m"))
	{
		if (i + 1 < ac)
			get_man(av[i + 1]);
		else
			get_man("MANUALS");
		return (1);
	}
	return (0);
}

int	parse_flag(int ac, char **av, char *dict)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (is_know_flag(av[i]))
		{
			if (retrieve_flag(av, i, ac, dict))
				i += 2;
			else
				return (0);
		}
		else
		{
			ft_putstr("Unknow flag : ");
			ft_putstr(av[i]);
			ft_putstr("\n");
			get_man("USAGE");
			return (0);
		}
	}
	return (1);
}

int	main(int ac, char **av)
{
	char	*dict;

	dict = NULL;
	parse_flag(ac, av, dict);
}
