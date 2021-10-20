#include "pendu.h"

int	main(int ac, char **av)
{
	t_game	game;

	game.dict = NULL;
	game.guessed = NULL;
	game.word = NULL;
	if (ac >= 2)
	{
		if (!parse_flag(ac, av, game.dict))
			return (1);
	}
	else
	{
		game.dict = malloc(11);
		ft_strcpy(game.dict, "words.list");
	}
	game.guessed = malloc(27);
	ft_game(game);
	free(game.dict);
	free(game.word);
	free(game.guessed);
}
