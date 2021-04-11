#include "rush.h"
#define SIZE 12

int	main(void)
{
	t_pos	*element_sort_by_x[SIZE * SIZE];
	t_pos	*element_sort_by_y[SIZE * SIZE];
	int		y = -1;
	int		x = -1;
	int		i = 0;
	int		map[SIZE][SIZE] =  {{0,0,0,0,0,0,0,1,1,1,1,1},
								{0,0,0,0,0,0,1,1,1,1,1,1},
								{0,0,0,0,0,1,1,1,2,2,2,2},
								{0,1,1,1,1,1,1,2,2,2,2,2},
								{0,2,2,2,2,2,2,2,2,2,2,2},
								{0,2,2,2,2,2,2,2,2,2,2,2},
								{0,3,3,3,3,3,3,3,3,3,3,3},
								{0,3,3,3,3,3,3,3,3,3,3,3},
								{0,3,3,3,3,3,3,3,3,3,3,3},
								{0,4,4,4,4,4,4,4,4,4,4,4},
								{0,4,4,4,4,4,4,4,4,4,4,4},
								{0,0,0,0,0,0,0,0,0,0,0,0}};

	while (++y < SIZE)
	{ 
		while (++x < SIZE)
		{
			element_sort_by_x[i] = init_pos(x, y, map[y][x]);
			element_sort_by_y[i] = element_sort_by_x[i];
			i++;
		}
		x = -1;
	}
	sort_element_by_y(element_sort_by_x, SIZE * SIZE);
	sort_element_by_x(element_sort_by_x, SIZE * SIZE);
	sort_element_by_height(element_sort_by_x, SIZE * SIZE);
	sort_element_by_x(element_sort_by_y, SIZE * SIZE);
	sort_element_by_y(element_sort_by_y, SIZE * SIZE);
	sort_element_by_height(element_sort_by_y, SIZE * SIZE);
	search_square(element_sort_by_x, element_sort_by_y, SIZE * SIZE, (*element_sort_by_x[0]).height);
	ft_free_element(element_sort_by_x, SIZE * SIZE);
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

