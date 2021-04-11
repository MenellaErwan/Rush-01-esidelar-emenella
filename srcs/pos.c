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