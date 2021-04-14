#include "rush.h"

void	ft_resolve(t_map *map, int size)
{
	int		y;
	int		x;
	int		condition;

	y = -1;
	x = -1;
	condition = 0;
	while (size)
	{
		while (++y < map->size)
		{
			while (++x < map->size)
			{
				condition = ft_valide_square(map, size, x, y);
				if (condition)
				{
					affiche_square(map, size, x, y);
					return ;
				}
			}
			x = -1;
		}
		y = -1;
		size--;
	}
}

t_map	*ft_init_map(char **str, int size, char c)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->map = str;
	map->size = size;
	map->c = c;
	return (map);
}

int	ft_valide_square(t_map *map, int size, int x, int y)
{
	char	c;
	int		i;
	int		j;

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

void	affiche_square(t_map *map, int size, int x, int y)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < map->size + 1)
	{
		while (++j < map->size + 1)
		{
			if (j >= x && j < x + size && i >= y && i < y + size)
				write(1, &map->c, 1);
			else
				write(1, &map->map[i][j], 1);
		}
		j = -1;
	}
}
