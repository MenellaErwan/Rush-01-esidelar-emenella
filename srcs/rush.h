#ifndef RUSH_H
# define RUSH_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdint.h>

typedef struct  s_pos
{
	int x;
	int y;
	int height;
}				t_pos;

void	swap (int *x, int *y);
void	sort_element_by_height(t_pos *element[], int n);
t_pos	*init_pos(int x, int y, int height);
void	print_element(t_pos *element[], int n);
int		len_by_height(t_pos *element[], int n, int height);
void	sort_element_by_x(t_pos *element[], int n);
void	sort_element_by_y(t_pos *element[], int n);
int		floorSqrt(int x);
int		maxline(t_pos *element[], int n, int height);
int		maxsize(t_pos *element_sort_by_x[], t_pos *element_sort_by_y[], int n, int height);
int		maxcol(t_pos *element[], int n, int height);
void	*verif_square(t_pos *element[], int n, int size, int it);
void	*find_big_square(t_pos *element[], int n, int height, int size);
void	sort_array(int element[][2], int n);
void	search_square (t_pos *element_sort_by_x[], t_pos *element_sort_by_y[], int n, int high);
void	*ft_memcpy (void *dest, const void *src, size_t len);
void	ft_free_element(t_pos *element[], int n);
#endif