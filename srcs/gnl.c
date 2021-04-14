#include "rush.h"
#define BUFFER_SIZE 1

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *s)
{
	int	number;
	int	index;

	number = 0;
	index = 0;
	while (ft_isdigit(*(s + index)))
		number = number * 10 + *s++ - '0';
	return (number);
}

int	param(int convert)
{
	size_t	ret;
	char	p;
	char	save[32UL];

	p = 0;
	ret = read(0, save + p, 1);
	while ((*(save + p) != '\n') && ret > 0)
	{
		++p;
		ret = read(0, save + p, 1);
	}
	if (convert)
		return (ft_atoi(save));
	else
		return (save[0]);
}

char	**get_map(int size)
{
	int		i;
	int		ret;
	char	**map;

	i = -1;
	ret = 1;
	map = malloc(sizeof(char *) * size);
	if (!map)
		return (NULL);
	while (++i < size && ret > 0)
	{
		map[i] = malloc(sizeof(char) * (size + 1));
		if (!map[i])
			return (NULL);
		read(0, map[i], size + 1);
	}
	return (map);
}

int	main(void)
{
	char	**str;
	int		para;
	int		chara;
	t_map	*map;

	str = NULL;
	para = param(1);
	chara = param(0);
	str = get_map(para);
	map = ft_init_map(str, para, chara);
	ft_resolve(map, para);
	free(str);
}
