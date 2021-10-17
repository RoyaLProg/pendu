#include "pendu.h"

int	main(int ac, char **av)
{
	t_game	game;
	char	*flagreturn;

	game.dict = NULL;
	game.guessed = NULL;
	game.word = NULL;
	if (ac >= 3)
	{
		if (!parse_flags(ac, av, game.dict))
			return (1);
	}
	else if (game.dict == NULL)
	{
		game.dict = malloc(11);
		ft_strcpy(game.dict, "words.list");
	}
	game.guessed = malloc(27);
	choose_word(game.dict, game.word);
	free(game.dict);
	free(game.word);
	free(game.guessed);
}
