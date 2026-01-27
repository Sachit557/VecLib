#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <stddef.h>
#include "vector.h"

int vector_init(Vector *v, size_t elem_size);
void vector_free(Vector *v);

int vector_push(Vector *v, const void *elem);
int vector_pop(Vector *v, void *out);
void *vector_get(Vector *v, size_t index);

int main(void)
{
}

int vector_init(Vector *v, size_t elem_size)
{
    if (v == NULL || elem_size <= 0)
        return -1;

    v->data = NULL;
    v->elem_size = elem_size;
    v->capacity = 0;
    v->size = 0;

    return 0;
}

void vector_free(Vector *v)
{
    if (v == NULL)
        return;

    if (v->data != NULL)
        free(v->data);

    v->data = NULL;
    v->capacity = 0;
    v->size = 0;
}

int vector_push(Vector *v, const void *elem)
{
    if (v == NULL || elem == NULL)
        return -1;

    if (v->size >= v->capacity)
    {
        size_t capacity = 0;
        if (v->capacity == 0)
            capacity = 1;
        else
            capacity = v->capacity * 2;

        void *data = realloc(v->data, capacity * v->elem_size);

        if (data == NULL)
            return -1;

        v->data = data;
        v->capacity = capacity;
    }

    char *data = (char *)v->data + v->elem_size * v->size;
    char *src = (char *)elem;

    for (size_t i = 0; i < v->elem_size; i++)
        data[i] = src[i];
    v->size++;

    return 0;
}

int vector_pop(Vector *v, void *out)
{
    if (v == NULL || v->size == 0)
        return -1;
}