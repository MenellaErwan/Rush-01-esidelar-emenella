#ifndef RUSH_H
# define RUSH_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdint.h>

typedef struct s_map
{
	char	**map;
	int		size;
	char	c;
}			t_map;

void	affiche_square(t_map *map, int size, int x, int y);
int		ft_valide_square(t_map *map, int size, int x, int y);
t_map	*ft_init_map(char **str, int size, char c);
void	ft_resolve(t_map *map, int size);
#endif