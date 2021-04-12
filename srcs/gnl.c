#include "rush.h"
#define BUFFER_SIZE 1

int     ft_isdigit(int c)
{
        if (c >= '0' && c <= '9')
                return (1);
        return (0);
}

int ft_atoi(const char *s)
{
    uint_fast32_t number;
    uint_fast32_t index;

    number = 0;
    index = 0;
    while (ft_isdigit(*(s + index)))
        number = number * 10 + *s++ - '0';
    return (number);
}

static int param(int convert)
{
    size_t			ret;
    char	p;
    char	save[32UL];

    ret = 1;
    p = 0;
    while ((ret = read(0, save + p, 1UL)) > 0L && (*(save + p) != '\n'))
		++p;
	if (convert)
		return (ft_atoi(save));
	else
		return (save[0]);
}

int ft_strlen(char *str)
{
    int i;
    i = 0;
    while(str[i])
        i++;
    return (i);
}

char *get_map(int size)
{
    int i;
    char *map;

    i = 0;
    if(!(map = malloc(sizeof(char) * size * size + 1)))
        return (NULL);
    map[size * size] = 0;
    while (i < size * size)
    {
        i += read(0, map + i, size + 1);
        i--;
    }
    return (map);
}

void ft_str_to_map(char *str, uint_fast64_t size, char c)
{
	t_pos	*element_sort_by_x[size * size];
	t_pos	*element_sort_by_y[size * size];
	uint_fast64_t		y = -1;
	uint_fast64_t		x = -1;
	uint_fast64_t		i = 0;

	while (++y < size)
	{ 
		while (++x < size)
		{
			element_sort_by_x[i] = init_pos(x, y, str[i] - 48);
			element_sort_by_y[i] = element_sort_by_x[i];
			i++;
		}
		x = -1;
	}

	ft_resolve(size, element_sort_by_x, element_sort_by_y, c);
}

int main()
{
	char	*str = NULL;
	int	    para;
	int	    chara;

	para = param(1);
	chara = param(0);
	str = get_map(para);
    // printf("%s\n", str);
	ft_str_to_map(str, para, chara);
	free(str);
}