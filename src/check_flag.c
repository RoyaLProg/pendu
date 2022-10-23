#include "pendu.h"
#include <string.h>
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
	ft_putstr("Error : Unknown argument :");
	ft_putstr(flag);
	return (0);
}

static char	retrieve_flag(char **av, t_game *game)
{
	size_t	i;

	i = 0;
	while (av[++i])
	{
		if (i - 1 % 2 == 0)
		{
			if (!is_know_flag(av[i]))
				return (1);
		}
		else
		{
			if (!ft_strcmp(av[i - 1], "-m"))
			{
				if (!get_man(av[i]))
					get_man("MANUALS");
				return (1);
			}
			else if (!ft_strcmp(av[i - 1], "-h"))
			{
				get_man("USAGE");
				return (1);
			}
			else if (!ft_strcmp(av[i - 1], "-d"))
				game->dict = strdup(av[i]); 
		}
	}
	if (i % 2 == 0 && i != 1)
	{
		get_man("USAGE");
		return (1);
	}
	return (0);
}

static void	default_config(t_game *game)
{
	game->dict = malloc(15);
	ft_strcpy(game->dict, "src/words.list");
}

int	parse_flag(char **av, t_game *game)
{
	if (retrieve_flag(av, game))
		return (1);
	if (!game->dict)
		default_config(game);;
	return (0);
}
