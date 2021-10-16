#include "pendu.h"

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
	while (flag[i] != 0)
	{
		if (c == flag[i])
			return (1);
	}
	return (0);
}

void	retrieve_flag(char **av, int i, char *dict)
{
	if (strcmp(av[i], "-d") == 0)
	{
		dict = malloc(ft_strlen(av[i + 1]));
		if (dict == -1)
			return (0);
		ft_strcpy(dict, av[i + 1]);
		return (1);
	}
	else if (strcmp(av[i], "-h") == 0)
	{
		get_man("USAGE");
		return (0);
	}
	else if (strcmp(av[i], "-m"))
	{
		if (!get_man(av[i + 1]))
			get_man("MANUALS");
		return (1);
	}
}

int	parse_flag(int ac, char **av, char *dict)
{
	int	to_parse;
	int	i;

	to_parse = (ac - 1) / 2;
	i = 1;
	while (i < ac)
	{
		if (is_know_flag(av[i]))
			retrieve_flag(av, i, dict);
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
