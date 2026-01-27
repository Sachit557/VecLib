#ifndef VECTOR_H
#define VECTOR_H

typedef struct
{
    void *data;
    size_t len;
    size_t cap;
    size_t elem_size;
} Vector;

/* lifecycle */
int vector_init(Vector *v, size_t elem_size);
void vector_free(Vector *v);

/* operations */
int vector_push(Vector *v, const void *elem);
int vector_pop(Vector *v, void *out);
void *vector_get(Vector *v, size_t index);

#endif
