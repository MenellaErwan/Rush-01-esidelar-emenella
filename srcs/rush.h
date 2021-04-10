#ifndef RUSH_H
# define RUSH_H
# include <stdio.h>
# include <stdlib.h>

typedef struct  s_pos
{
    int x;
    int y;
    int height;
}               t_pos;

void   swap (int *x, int *y);
void   sort_element(t_pos *element[], int n);
t_pos   *init_pos(int x, int y, int height);
void    print_element(t_pos *element[], int n);
void   sort_x_element(t_pos *element[], int n);
void   sort_y_element(t_pos *element[], int n);
#endif