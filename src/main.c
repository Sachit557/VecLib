#include <stdio.h>
#include "vector.h"

int main(void)
{
    Vector v;
    vector_init(&v, sizeof(int));

    for (int i = 0; i < 11; i++)
    {
        vector_push(&v, &i);
    }
    int i = 99;
    vector_set(&v, 5, &i);
    printf("%d \n", *(int *)vector_get(&v, 5));

    for (int i = 0; i < 11; i++)
        printf("%d \n", *(int *)vector_get(&v, i));

    printf("%d", vector_size(&v));
    return 0;
}