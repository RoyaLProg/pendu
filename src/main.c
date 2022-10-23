#include "pendu.h"

int	main(int ac, char **av)
{
	t_game	game;

	(void)ac;
	game.dict = NULL;
	game.guessed = NULL;
	game.word = NULL;
	if (parse_flag(av, &game))
		return (EXIT_FAILURE);
	if (verif_dict(game.dict))
	{
		game.word = choose_word(game.dict, game.word);
		game.guessed = malloc(27);
		ft_game(game.word, game.guessed);
	}
	else
		ft_printf("error\n");
	free(game.dict);
	free(game.word);
	free(game.guessed);
}
