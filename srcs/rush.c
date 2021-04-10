#include "rush.h"
#define SIZE 12

int main()
{
    int map[SIZE][SIZE] =  {{0,0,0,0,0,0,0,1,1,1,1,1},
                            {0,0,0,0,0,0,1,1,1,1,1,1},
                            {0,0,0,0,0,1,1,1,2,2,2,2},
                            {0,1,1,1,1,1,1,2,2,2,2,2},
                            {0,2,2,2,2,2,2,2,2,2,2,2},
                            {0,3,3,3,3,3,3,3,3,3,3,3},
                            {0,2,2,2,2,2,2,2,2,2,2,2},
                            {0,3,3,3,3,3,3,3,3,3,3,3},
                            {0,3,3,3,3,3,3,3,3,3,3,3},
                            {0,4,4,4,4,4,4,4,4,4,4,4},
                            {0,4,4,4,4,4,4,4,4,4,4,4},
                            {0,0,0,0,0,0,0,0,0,0,0,0}};

    t_pos *element[SIZE * SIZE];
    int y = -1;
    int x = -1;
    int i = 0;
    while (++y < SIZE )
    { 
        while (++x < SIZE)
            element[i++] = init_pos(x, y, map[y][x]);
        x = -1;
    }
    
    // print_element(element, SIZE * SIZE);
    sort_element(element, SIZE * SIZE);
    // sort_y_element(element, SIZE * SIZE);
    // sort_x_element(element, SIZE * SIZE);
    print_element(element, SIZE * SIZE);


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
