#include "rush.h"

void	ft_resolve(char **str, int size, char c)
{
	int y;
	int x;
	int i;
	t_map *map;

	y = -1;
	x = -1;
	i = size;
	map = ft_init_map(str, size);
	while (i)
	{
		while (++y < size)
		{
			while (++x < size)
				if (ft_valide_square(map, i, x, y))
				{
					affiche_square(map, i, x, y, c);
					return ;
				}
			x = -1;
		}
		y = -1;
		i--;
	}
}

t_map *ft_init_map(char **str, int size)
{
	t_map *map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->map = str;
	map->size = size;
	return (map);
}

int	ft_valide_square(t_map *map, int size, int x, int y)
{
	char c;
	int i;
	int j;

	i = x;
	j = y;
	c = map->map[y][x];
	if (x + size > map->size || y + size > map->size)
		return (0);
	while (y < size + j)
	{
		while (x < size + i)
		{
			if (c != map->map[y][x])
				return (0);
			x++;
		}
		x = i;
		y++;
	}
	return (1);
}

void	affiche_square(t_map *map, int size, int x, int y, char c)
{
	int i;
	int j;

	i = -1;
	j = -1;

	
	while (++i < map->size + 1)
	{
		while (++j < map->size + 1)
		{
			if (j >= x && j < x + size && i >= y && i < y + size)
				write(1, &c, 1);
			else
				write(1, &map->map[i][j], 1);
		}
		j = -1;
	}
}