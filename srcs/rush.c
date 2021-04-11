#include "rush.h"
#define SIZE 12

int main()
{
	int map[SIZE][SIZE] =  {{0,0,0,0,0,0,0,1,1,1,1,1},
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

	t_pos *element_sort_by_x[SIZE * SIZE];
	t_pos *element_sort_by_y[SIZE * SIZE];
	int y = -1;
	int x = -1;
	int i = 0;
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

void ft_free_element(t_pos *element[], int n)
{
	int i;

	i = -1;
	while (++i < n)
		free(element[i]);
}

void search_square (t_pos *element_sort_by_x[], t_pos *element_sort_by_y[], int n, int high)
{
	int array[high + 1][2];
	int i;
	t_pos *pos;

	i = high;
	while(i >= 0)
	{
		array[i][0] = maxsize(element_sort_by_x, element_sort_by_y, n, i);
		array[i][1] = i;
		i--;
	}
	sort_array(array, high + 1);
	i = -1;
	while(++i < high + 1)
	{
		pos = find_big_square(element_sort_by_x, n, array[i][1], array[i][0]);
		if (pos)
		{
			// affiche(pos, i);
			break ;
		}
	}
}

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

int len_by_height(t_pos *element[], int n, int height)
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

int floorSqrt(int x)
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
	while (i < n - 1 && (*element[i]).height == height)
	{
		if((*element[i]).y < (*element[i + 1]).y)
			tmp++;
		else
			tmp = 0;
		if (max < tmp)
			max = tmp;
		i++;
	}
	return (max + 1);
}

int maxline(t_pos *element[], int n, int height)
{
	int i;
	int max;
	int tmp;

	i = -1;
	max = 1;
	tmp = 1;
	while (++i < n - 1 && (*element[i]).height != height);
	while (i < n - 1 && (*element[i]).height == height)
	{
		if((*element[i]).x < (*element[i + 1]).x)
			tmp++;
		else
			tmp = 1;
		if (max < tmp)
			max = tmp;
		i++;
	}
	return (max);
}

void *find_big_square(t_pos *element[], int n, int height, int size)
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

void *verif_square(t_pos *element[], int n, int size, int it)
{
	int i;
	int j;
	int g;
	t_pos *pos;

	(void)n;
	j = -1;
	pos = element[it];
	while (++j < size - 1)
	{
		i = -1;
		while (++i < size)
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

void *ft_memcpy (void *dest, const void *src, size_t len)
{
  char *d = dest;
  const char *s = src;
  while (len--)
	*d++ = *s++;
  return dest;
}