#include "pendu.h"

int	verif_dict(char *dict)
{
	int		i;
	int		fd;
	char	*c;

	i = 0;
	fd = open(dict, O_RDONLY);
	if (!fd)
	{
		ft_putstr("Error : Could'nt open file\n");
		return (0);
	}
	while (read(1, &c, 1))
	{
		if ((c < 'a' || c > 'z') && (c != '\n' || c != '0'))
		{
			ft_putstr("Dictionary not in norm");
			ft_putstr("(use flag \"-m dict_norm\" to see more)\n");
			return (0);
			break ;
		}
	}
	return (1);
}
