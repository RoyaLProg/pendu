#include "pendu.h"

int	main(int ac, char **av)
{
	t_game	game;

	game.dict = NULL;
	game.guessed = NULL;
	game.word = NULL;
	if (ac >= 2)
	{
		if (!parse_flag(ac, av))
			return (1);
		game.dict = get_dict(game.dict, av);
	}
	if (game.dict == NULL)
	{
		game.dict = malloc(15);
		ft_strcpy(game.dict, "src/words.list");
	}
	if (verif_dict(game.dict))
	{
		game.word = choose_word(game.dict, game.word);
		game.guessed = malloc(27);
		ft_game(game.word, game.guessed);
	}
	free(game.dict);
	free(game.word);
	free(game.guessed);
}
