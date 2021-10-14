#ifndef PENDU_H
# define PENDU_H
# include <unistd.h>
# include <fcntl.h>

void	ft_putstr(const char *str);
void	ft_putnbr(int nb);
void	write_nbr(unsigned int v);
char	getc(char c);
int	count_word(const char *dict);

#endif
