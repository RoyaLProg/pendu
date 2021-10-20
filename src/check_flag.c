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

int	retrieve_flag(char **av, int i, char *dict)
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
		if (!get_man(av[i + 1]))
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
			if (retrieve_flag(av, i, dict))
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
