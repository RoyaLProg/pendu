#ifndef PENDU_H
# define PENDU_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <time.h>
# include <stdarg.h>

typedef struct s_game
{
	char	*guessed;
	char	*word;
	char	*dict;
}t_game;

void	clear(void);
void	ft_putstr(const char *str);
void	ft_putnbr(int nb);
void	write_nbr(unsigned int v);
void	affichage(char *word, char *guessed);
void	ft_strcpy(char *dest, char *src);
void	put_letter(char *word, char *guessed, int l);
void	ft_game(char *word, char *guessed);
void	ft_printf(const char *str, ...);
char	ft_getc(char c);
char	*choose_word(char *word, char *dict);
char	*get_dict(char *dict, char **av);
int		parse_flag(char **av, t_game *game);
int		get_man(char *asked);
int		is_guessed(char c, char *guessed);
int		count_word(const char *dict);
int		ft_strlen(const char *str);
int		verif_dict(char *dict);
int		ft_strcmp(char *s1, char *s2);
void	*readline(int *fd, char *buf);

#endif
