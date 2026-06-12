#include <stdio.h>
#include "vector.h"

int main(void)
{
    Vector vec;
    vector_init(&vec, sizeof(int));

    for (int i = 0; i < 100; i++)
        vector_push(&vec, &i);
    for (int i = 0; i < 100; i++)
        printf("%d ", *(int *)vector_get(&vec, i));

    printf("\nVal at index %d is %d", 10, *(int *)vector_get(&vec, 5));

    printf("Size is %zu and capacity is %zu", vector_size(&vec), vector_capacity(&vec));

    return 0;
}