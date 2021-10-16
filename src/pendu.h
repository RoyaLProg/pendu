#ifndef PENDU_H
# define PENDU_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_game
{
	int		tries;
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
char	ft_getc(char c);
int		count_word(const char *dict);
int		ft_strlen(const char *str);
int		verif_dict(char *dict);
int		ft_strcmp(char *s1, char *s2);
int		readline(int fd, char *buf);

#endif
