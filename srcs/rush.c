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

    t_pos *element[SIZE * SIZE];
    int y = -1;
    int x = -1;
    int i = 0;
    while (++y < SIZE)
    { 
        while (++x < SIZE)
            element[i++] = init_pos(x, y, map[y][x]);
        x = -1;
    }
    
    // print_element(element, SIZE * SIZE);
    sort_element_by_y(element, SIZE * SIZE);
    sort_element_by_x(element, SIZE * SIZE);
    sort_element(element, SIZE * SIZE);
    print_element(element, SIZE * SIZE);
    i = -1;
    while(++i < 5)
    printf("%d=%d\n", i, maxsize(element, SIZE * SIZE, i));

    return (0);
}

void swap (int *x, int *y)
{
    if (x != y)
    {
        *x ^= *y;
        *y ^= *x;
        *x ^= *y;
    }
}

void   sort_element(t_pos *element[], int n)
{
    int i = -1;
    int j = -1;

    while (++i < n - 1)
    {
        while(++j < n - i - 1)
            if ((*element[j]).height < (*element[j + 1]).height)
                swap((void *)&element[j], (void *)&element[j + 1]);
        j = -1;
    }
}

void   sort_element_by_x(t_pos *element[], int n)
{
    int i = -1;
    int j = -1;

    while (++i < n - 1)
    {
        while(++j < n - i - 1)
            if ((*element[j]).x > (*element[j + 1]).x)
                swap((void *)&element[j], (void *)&element[j + 1]);
        j = -1;
    }
}

void   sort_element_by_y(t_pos *element[], int n)
{
    int i = -1;
    int j = -1;

    while (++i < n - 1)
    {
        while(++j < n - i - 1)
            if ((*element[j]).y > (*element[j + 1]).y)
                swap((void *)&element[j], (void *)&element[j + 1]);
        j = -1;
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
    return x;
 
    int i = 1, result = 1;
    while (result <= x)
    {
      i++;
      result = i * i;
    }
    return i - 1;
}

int maxsize(t_pos *element[], int n, int height)
{
    int max;
    int tmp;

    max = floorSqrt(len_by_height(element, n, height));
    tmp = maxcol(element, n, height);
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