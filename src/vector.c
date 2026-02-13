#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"

int vector_init(Vector *v, size_t elem_size);
void vector_free(Vector *v);

int vector_push(Vector *v, const void *elem);
int vector_pop(Vector *v, void *out);
void *vector_get(Vector *v, size_t index);

int vector_set(Vector *v, size_t index, const void *elem);
void vector_clear(Vector *v);
int vector_resize(Vector *v, size_t new_size);

size_t vector_size(Vector *v);
size_t vector_capacity(Vector *v);

void vector_insert_at(Vector *v, const void *elem, size_t index);
void vector_remove_at(Vector *v, size_t index);

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
        size_t capacity;

        if (v->capacity == 0)
            capacity = 1;
        else
            capacity = v->capacity * 2;

        void *new_data = realloc(v->data, capacity * v->elem_size);

        if (new_data == NULL)
            return -1;

        v->data = new_data;
        v->capacity = capacity;
    }

    char *dest = (char *)v->data + (v->size * v->elem_size);
    memcpy(dest, elem, v->elem_size);
    v->size++;

    return 0;
}

int vector_pop(Vector *v, void *out)
{
    if (v == NULL || v->size == 0)
        return -1;

    char *dest = (char *)v->data + (v->elem_size * (v->size - 1));

    if (out != NULL)
        memcpy(out, dest, v->elem_size);

    v->size--;

    return 0;
}

void *vector_get(Vector *v, size_t index)
{
    if (v == NULL || index > v->size - 1)
        return NULL;

    char *dest = (char *)v->data + (v->elem_size * index);

    return (void *)dest;
}

int vector_set(Vector *v, size_t index, const void *elem)
{
    if (v == NULL || index > v->size - 1 || elem == NULL)
        return -1;

    char *dest = (char *)v->data + (index * v->elem_size);

    memcpy(dest, elem, v->elem_size);

    return 0;
}

void vector_clear(Vector *v)
{
    if (v == NULL)
        return;

    v->size = 0;
}

int vector_resize(Vector *v, size_t new_size)
{
    if (v == NULL)
        return -1;

    if (v->size == new_size)
        return 0;

    if (v->size > new_size || (new_size > v->size && new_size <= v->capacity))
    {
        v->size = new_size;
        return 0;
    }

    else
    {
        // finish this func
        size_t capacity = v->capacity;

        if (capacity == 0)
            capacity = 1;
        else
            while (capacity < new_size)
                capacity *= 2;

        void *new_data = realloc(v->data, v->capacity * v->elem_size);

        if (new_data == NULL)
            return -1;

        v->capacity = capacity;
        v->data = new_data;
        v->size = new_size;

        return 0;
    }

    // can initialize v->data with some value cause extra allocated memory contains garbage values

    return 0;
}

size_t vector_size(Vector *v)
{
    if (v == NULL)
        return 0;

    return v->size;
}

size_t vector_capacity(Vector *v)
{
    if (v == NULL)
        return 0;

    return v->capacity;
}

void vector_insert_at(Vector *v, const void *elem, size_t index)
{

    if (v == NULL || elem == NULL || index > v->size)
        return;

    if (v->size == v->capacity)
    {
        size_t cap;

        if (v->capacity == 0)
            cap = 1;

        else
            cap = 2 * v->capacity;

        void *data = realloc(v->data, cap * v->elem_size);

        if (data == NULL)
            return;

        v->data = data;
        v->capacity = cap;
    }

    char *base_pos = (char *)v->data;
}

void vector_remove_at(Vector *v, size_t index)
{
    if (v == NULL || index >= v->size)
        return;
}
