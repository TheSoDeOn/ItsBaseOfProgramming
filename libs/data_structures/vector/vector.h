#ifndef LABA14_VECTOR__H
#define LABA14_VECTOR__H

#include <stdint.h>
#include <assert.h>
#include <memory.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct vector_ {
    int *data; // указатель на элементы вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
} vector;

// возвращает структуру-дескриптор вектор из n значений
vector createVector(size_t n);

// изменяет количество
// памяти, выделенное под хранение элементов вектора v
void reserve(vector *v, size_t newCapacity);

// удаляет элементы из вектора v
void clear(vector *v);

// освобождает память, выделенную под
//неиспользуемые элементы вектора v
void shrinkToFit(vector *v);

// освобождает память, выделенную вектору v
void deleteVector(vector *v);


#endif //LABA14_VECTOR__H
