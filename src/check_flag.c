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
	while (flags[i] != 0)
	{
		if (c == flags[i])
			return (1);
		i++;
	}
	return (0);
}

int	retrieve_flag(char **av, int i, int ac)
{
	if (ft_strcmp(av[i], "-h") == 0)
		get_man("USAGE");
	else if (ft_strcmp(av[i], "-m") == 0)
	{
		if (i + 1 < ac)
		{
			if (!get_man(av[i + 1]))
				get_man("MANUALS");
		}
		else if (!get_man(av[i + 1]) || i + 1 >= ac)
			get_man("MANUALS");
	}
	return (1);
}

int	parse_flag(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (is_know_flag(av[i]))
		{
			if (retrieve_flag(av, i, ac))
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
