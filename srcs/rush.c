#include "rush.h"

int	ft_resolve(int size,  t_pos *element_sort_by_x[], t_pos *element_sort_by_y[])
{
	sort_element_by_y(element_sort_by_x, size * size);
	sort_element_by_x(element_sort_by_x, size * size);
	sort_element_by_height(element_sort_by_x, size * size);
	sort_element_by_x(element_sort_by_y, size * size);
	sort_element_by_y(element_sort_by_y, size * size);
	sort_element_by_height(element_sort_by_y, size * size);
	search_square(element_sort_by_x, element_sort_by_y, size, (*element_sort_by_x[0]).height);
	ft_free_element(element_sort_by_x, size * size);
	return (0);
}

void	ft_free_element(t_pos *element[], int n)
{
	int i;

	i = -1;
	while (++i < n)
		free(element[i]);
}

t_pos   *init_pos(int x, int y, int height)
{
	t_pos *pos = malloc(sizeof(t_pos));
	if (pos) 
	{
		pos->x = x;
		pos->y = y;
		pos->height = height;
	}
	return (pos);
}

int		len_by_height(t_pos *element[], int n, int height)
{
	int i;
	int j;

	i = -1;
	j = 0;
	while (++i < n)
		if ((*element[i]).height == height)
			j++;
	return (j);
}

int		floorSqrt(int x)
{
	if (x == 0 || x == 1)
	return (x);
 
	int i = 1, result = 1;
	while (result <= x)
	{
	  i++;
	  result = i * i;
	}
	return (i - 1);
}

