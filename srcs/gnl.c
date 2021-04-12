#include "rush.h"
#define BUFFER_SIZE 220

uint_fast64_t		ft_strlen(unsigned char * restrict const src)
{
	uint_fast64_t				i;
	uint_fast64_t				len;
	uint_fast64_t * restrict	str;

	i = 0;
	len = 255;
	str = (uint_fast64_t *)src;
	if (!str)
		return (0);
	while (*str && *str & len)
	{
		i++;
		len <<= 8;
		if (len == 0xFF00000000000000)
		{
			if (*str & len)
				i++;
			else
				return (i);
			str++;
			len = 255;
		}
	}
	return (i);
}

unsigned char    *ft_strcpy(unsigned char * restrict dest,
	unsigned char * restrict const src, uint_fast64_t len)
{
	return(ft_memcpy(dest, src, len));
}

static inline uint_fast8_t is_digit(int ascii)
{
    return ((ascii >= '0') & (ascii <= '9'));
}

static uint_fast32_t ft_atoi(const unsigned char *s)
{
    uint_fast32_t number;
    uint_fast32_t index;

    number = 0;
    index = 0;
    while (is_digit(*(s + index)))
        number = number * 10 + *s++ - '0';
    return (number);
}

static uint_fast32_t param(uint_fast8_t convert)
{
    size_t			ret;
    unsigned char	p;
    unsigned char	save[32UL];

    ret = 1;
    p = 0;
    while ((ret = read(0, save + p, 1UL)) > 0L && (*(save + p) != '\n'))
		++p;
	if (convert)
		return (ft_atoi(save));
	else
		return (save[0]);
}

int		get_next_line(unsigned char **str, uint_fast32_t n)
{
	unsigned char result[n + 1];
	uint_fast32_t ret;
	uint_fast32_t i;

	i = -1;
	ret = 1;
	*str = malloc(sizeof(char) * (n * n + 1));
	result[n] = 0;
	while (++i < n && ret)
	{
		ret = read(0, result, n * n);
		if (!ret)
		{
			free(*str);
			return (1);
		}
		else
			ft_strcpy(*str + i * n, result, n);
	}
	(*str)[n * n] = 0;
	return (0);
}

void ft_str_to_map(unsigned char *str, uint_fast64_t size, char c)
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
	unsigned char	*str = NULL;
	uint_fast8_t	para;
	int	chara;

	para = param(1);
	chara = param(0);
	if (get_next_line(&str, para))
		return (0);
	ft_str_to_map(str, para, chara);
	free(str);
}