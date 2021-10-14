#ifndef PENDU_H
# define PENDU_H
# include <unistd.h>
# include <fcntl.h>

void	ft_putstr(const char *str);
void	ft_putnbr(int nb);
void	write_nbr(unsigned int v);
void	affichage(char *word, char *guessed);
char	getc(char c);
int		count_word(const char *dict);
int		ft_strlen(const char *str);

#endif
