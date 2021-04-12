#include "rush.h"

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

void *ft_memcpy (void *dest, const void *src, size_t len)
{
  char *d = dest;
  const char *s = src;
  while (len--)
	*d++ = *s++;
  return dest;
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_affiche(t_pos *pos, int size, int n, t_pos *element[])
{
	int y;
	int x;
	int i;

	y = -1;
	x = -1;
	i = 0;
	sort_element_by_x(element, n * n);
	sort_element_by_y(element, n * n);
	while (++y < n)
	{
		while (++x < n)
		{
			if (x >= pos->x && x < pos->x + size && y >= pos->y && y < pos->y + size)
				ft_putchar('x');
			else
				ft_putchar((*element[i]).height + 48);
			i++;
		}
		x = -1;
		write(1, "\n", 1);
	}
}