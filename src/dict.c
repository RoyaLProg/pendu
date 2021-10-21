#include "pendu.h"

char	*get_dict(char *dict, char **av)
{
	int	i;

	i = 0;
	while (av[i] != NULL)
	{
		if (ft_strcmp(av[i], "-d") == 0 && av[i + 1] != NULL)
		{
			dict = malloc(ft_strlen(av[i + 1]) + 1);
			if (dict == NULL)
				return (NULL);
			ft_strcpy(dict, av[i + 1]);
			return (dict);
		}
		i++;
	}
	return (NULL);
}
