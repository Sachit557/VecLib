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
}