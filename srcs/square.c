#include "rush.h"

void search_square (t_pos *element_sort_by_x[], t_pos *element_sort_by_y[], int n, char c)
{
	int array[(*element_sort_by_x[0]).height + 1][2];
	int i;
	int high;
	t_pos *pos;

	high = (*element_sort_by_x[0]).height;
	i = high;
	while(i >= 0)
	{
		array[i][0] = maxsize(element_sort_by_x, element_sort_by_y, n * n, i);
		array[i][1] = i;
		i--;
	}
	sort_array(array, high + 1);
	i = -1;
	while(++i < (*element_sort_by_x[0]).height + 1)
	{
		pos = find_big_square(element_sort_by_x, n * n, array[i][1], array[i][0]);
		if (pos)
		{
			ft_affiche(pos, array[i][0], n, element_sort_by_y, c);
			break ;
		}
	}
}

t_pos *find_big_square(t_pos *element[], int n, int height, int size)
{
	int i;
	int tmp;

	i = 0;
	tmp = 1;
	while (++i < n - 1 && (*element[i]).height != height);
	while (i < n - 1 && (*element[i]).height == height)
	{
		if((*element[i]).x == (*element[i - 1]).x)
			tmp++;
		else
			tmp = 1;
		if (size == tmp)
			break ;
		i++;
	}
	return(verif_square(element, n, size, i - size + 1));
}

t_pos *verif_square(t_pos *element[], int n, int size, int it)
{
	int i;
	int j;
	int g;
	t_pos *pos;

	j = -1;
	g = 0;
	if (it >= n)
		return (NULL);
	pos = element[it];
	while (++j < size - 1)
	{
		i = -1;
		while (++i < size && it + i + j + g < n - 1)
		{
			g = 0;
			while ((*element[it + i + j + g]).x == (*element[it + i + j + g + 1]).x)
				g++;
			g += i % size;
			if((*element[it + i + j]).x != (*element[it + i + j + g + 1]).x - 1 || (*element[it + i + j]).y != (*element[it + i + j + g + 1]).y || (*element[it + i + j]).height != (*element[it + i + j + g + 1]).height)
				return (NULL);
		}
		while ((*element[it + j]).x == (*element[it + j + 1]).x && j != size - 2)
			it++;
	}
	return (pos);
}

int maxsize(t_pos *element_sort_by_x[], t_pos *element_sort_by_y[], int n, int height)
{
	int max;
	int tmp;

	max = floorSqrt(len_by_height(element_sort_by_x, n, height));
	tmp = maxcol(element_sort_by_x, n, height);
	if (tmp < max)
		max = tmp;
	tmp = maxline(element_sort_by_y, n, height);
	if (tmp < max)
		max = tmp;
	return(max);
}

int maxcol(t_pos *element[], int n, int height)
{
	int i;
	int max;
	int tmp;

	i = -1;
	max = 0;
	tmp = 0;
	while (++i < n - 1 && (*element[i]).height != height);
	while (i < n - 1)
	{
		if ((*element[i]).height == height)
		{
			if((*element[i]).y < (*element[i + 1]).y)
				tmp++;
			else
				tmp = 0;
			if (max < tmp)
				max = tmp;
		}
		else
			tmp = 0;
		i++;
	}
	return (max + 1);
}