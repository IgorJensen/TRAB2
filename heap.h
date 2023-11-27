#ifndef _HEAP_H_
#define _HEAP_H_
#include <stdbool.h>

typedef struct Heap Heap;

Heap *heap_construct(); // O(1)

void heap_push(Heap *heap, void *data, double priority); // O(log N)

bool heap_empty(Heap *heap); // O(1)

void *heap_pop(Heap *heap); // O(log N)

void heap_destroy(Heap *heap); // O(1)

#endif