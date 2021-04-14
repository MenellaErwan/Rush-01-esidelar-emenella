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
    while ((ret = read(0, save + p, 1)) > 0 && (*(save + p) != '\n'))
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

char **get_map(int size)
{
    int i;
    int ret;
    char **map;

    i = -1;
    ret = 1;
    if(!(map = malloc(sizeof(char*) * (size))))
        return (NULL);
    while (++i < size && ret > 0)
    {
        if(!(map[i] = malloc(sizeof(char) * (size + 1))))
            return (NULL);
        read(0, map[i], size + 1);
    }
    return (map);
}

int main()
{
	char	**str = NULL;
	int	    para;
	int	    chara;

	para = param(1);
	chara = param(0);
	str = get_map(para);
    write(1, "\n", 1);
	ft_resolve(str, para, chara);
	free(str);
}