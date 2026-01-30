#include <stdio.h>
#include "../include/vector.h"

int main(void)
{

    Vector v;
    vector_init(&v, sizeof(int));

    for (int i = 0; i <= 10; i++)
    {
        vector_push(&v, &i);
    }

    printf("The size of the vector is %d and the capacity is %d", v.size, v.capacity);

    for (int i = 0; i < 10; i++)
    {
        int *a = vector_get(&v, i);
        printf("%d\n", *a);
    }

    return 0;
}