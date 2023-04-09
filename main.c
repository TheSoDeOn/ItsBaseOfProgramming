#include <stdio.h>
#include <stdint.h>
#include "libs/data_structures/vector/vector.h"

void test_createVector_ZeroCapacity() {
    vector v = createVector(0);
    assert(v.size == 0);
    assert(v.capacity == 0);
    assert(v.data == NULL);
    deleteVector(&v);
}

void test_createVector_NotZeroCapacity() {
    vector v = createVector(5);
    assert(v.size == 0);
    assert(v.capacity == 5);
    assert(v.data != NULL);
    deleteVector(&v);
}

void test_createVector() {
    test_createVector_ZeroCapacity();
    test_createVector_NotZeroCapacity();
}

void test_reserve_FromZeroToZero() {
    vector v = createVector(0);
    reserve(&v, 0);
    assert(v.capacity == 0);
    assert(v.size == 0);
    assert(v.data == NULL);
    deleteVector(&v);
}

void test_reserve_FromZeroToNotZero() {
    vector v = createVector(0);
    reserve(&v, 5);
    assert(v.capacity == 5);
    assert(v.size == 0);
    assert(v.data != NULL);
    deleteVector(&v);
}

void test_reserve_FromNotZeroToZero() {
    vector v = createVector(5);
    reserve(&v, 0);
    assert(v.capacity == 0);
    assert(v.size == 0);
    assert(v.data == NULL);
    deleteVector(&v);
}

void test_reserve_toLesser() {
    vector v = createVector(5);
    int a[4] = {1, 2, 3, 4};
    for (int i = 0; i < 4; i++)
        pushBack(&v, a[i]);
    reserve(&v, 2);
    assert(v.capacity == 2);
    assert(v.size == 2);
    assert(v.data != NULL);
    for (int i = 0; i < v.size; i++)
        assert(v.data[i] == a[i]);
    deleteVector(&v);
}

void test_reserve_toMore() {
    vector v = createVector(5);
    int a[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++)
        pushBack(&v, a[i]);
    reserve(&v, 10);
    assert(v.capacity == 10);
    assert(v.size == 5);
    assert(v.data != NULL);
    for (int i = 0; i < v.size; i++)
        assert(v.data[i] == a[i]);
    deleteVector(&v);
}

void test_reserve() {
    test_reserve_FromZeroToZero();
    test_reserve_FromNotZeroToZero();
    test_reserve_toLesser();
    test_reserve_FromZeroToNotZero();
    test_reserve_toMore();
}

void test_shrinkToFit_toZero() {
    vector v = createVector(5);
    shrinkToFit(&v);
    assert(v.capacity == 0);
    assert(v.size == 0);
    deleteVector(&v);
}

void test_shrinkToFit_toNotZero() {
    vector v = createVector(5);
    for (int i = 0; i < 3; i++)
        pushBack(&v, i);
    shrinkToFit(&v);
    assert(v.capacity == 3);
    assert(v.size == 3);
    deleteVector(&v);
}

void test_shrinkToFit() {
    test_shrinkToFit_toZero();
    test_shrinkToFit_toNotZero();
}

void test_pushBack_emptyVector() {
    vector v = createVector(0);
    pushBack(&v, 5);
    assert(v.size == 1);
    assert(v.capacity == 1);
    assert(v.data[0] == 5);
    deleteVector(&v);
}

void test_pushBack_fullVector() {
    vector v = createVector(5);
    for (int i = 0; i < v.capacity; i++) {
        pushBack(&v, i);
    }
    assert(v.size == 5);
    pushBack(&v, 5);
    assert(v.data[v.size - 1] == 5);
    assert(v.size == 6);
    assert(v.capacity == 10);
    deleteVector(&v);
}

void test_pushBack() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);
    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
    deleteVector(&v);
}

void test_popBack() {
    test_popBack_notEmptyVector();
}

void test() {
    test_createVector();
    test_pushBack();
    test_popBack();
    test_reserve();
    test_shrinkToFit();
}

int main() {
    test();
}