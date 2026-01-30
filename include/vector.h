#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>

typedef struct
{
    void *data;
    size_t elem_size;
    size_t size;
    size_t capacity;
} Vector;

int vector_init(Vector *v, size_t elem_size);
void vector_free(Vector *v);

int vector_push(Vector *v, const void *elem);
int vector_pop(Vector *v, void *out);
void *vector_get(Vector *v, size_t index);

#endif
