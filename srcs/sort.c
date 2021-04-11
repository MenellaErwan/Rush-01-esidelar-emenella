#include "rush.h"

void   sort_array(int element[][2], int n)
{
	int i = 0;
	int j = -1;
	int tmp[2];

	while (++i < n - 1)
	{
		ft_memcpy(tmp, element[i], sizeof(int) * 2);
		j = i;
		while (j > 0 && element[j - 1][0] < tmp[0])
		{
			ft_memcpy(element[j], element[j - 1], sizeof(int) * 2);
			j--;
		}
		ft_memcpy(element[j], tmp, sizeof(int) * 2);
	}
}

void   sort_element_by_height(t_pos *element[], int n)
{
	 int i = 0;
	int j = -1;
	t_pos *tmp;

	while (++i < n - 1)
	{
		tmp = element[i];
		j = i;
		while (j > 0 && (*element[j - 1]).height < tmp->height)
		{
			element[j] = element[j - 1];
			j--;
		}
		element[j] = tmp;
	}
}

void   sort_element_by_x(t_pos *element[], int n)
{
	int i = 0;
	int j = -1;
	t_pos *tmp;

	while (++i < n - 1)
	{
		tmp = element[i];
		j = i;
		while (j > 0 && (*element[j - 1]).x > tmp->x)
		{
			element[j] = element[j - 1];
			j--;
		}
		element[j] = tmp;
	}
}

void   sort_element_by_y(t_pos *element[], int n)
{
	 int i = 0;
	int j = -1;
	t_pos *tmp;

	while (++i < n - 1)
	{
		tmp = element[i];
		j = i;
		while (j > 0 && (*element[j - 1]).y > tmp->y)
		{
			element[j] = element[j - 1];
			j--;
		}
		element[j] = tmp;
	}
}

void print_element(t_pos *element[], int n)
{
	int i = -1;

	while (++i < n)
			printf("Height: %d; Y: %d; X: %d\n", (*element[i]).height, (*element[i]).y, (*element[i]).x);
}