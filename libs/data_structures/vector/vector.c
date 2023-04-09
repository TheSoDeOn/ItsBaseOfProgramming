#include "vector.h"
#include <malloc.h>

void memoryAllocateError(const int *data) {
    if (data == NULL) {
        fprintf(stderr, "bad alloc ");
        exit(1);
    }
}

vector createVector(size_t n) {
    int *data;
    if (n) {
        data = (int *) malloc(n * sizeof(int));
        memoryAllocateError(data);
    } else
        data = NULL;
    return (vector) {data, 0, n};
}

void deleteVector(vector *v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

void reserve(vector *v, size_t newCapacity) {
    if (newCapacity) {
        v->data = (int *) realloc(v->data, newCapacity * sizeof(int));
        memoryAllocateError(v->data);
        v->capacity = newCapacity;
        if (v->size > newCapacity)
            v->size = newCapacity;
    } else
        deleteVector(v);
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    reserve(v, v->size);
}
