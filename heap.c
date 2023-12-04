#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

const int capacidade = 10;

typedef struct{
    void *data;
    int priority;
} HeapNode;

struct Heap{
    HeapNode *nodes;
    int size;
    int capacity;
};

Heap *heap_construct(){
    Heap *h = (Heap *)calloc(1, sizeof(Heap));
    h->nodes = (HeapNode *)malloc(capacidade*sizeof(HeapNode));
    h->size = 0;
    h->capacity = capacidade;
    return h;
} // O(1)

void heap_swap(Heap *heap, int a, int b){
    HeapNode aux = heap->nodes[a];
    heap->nodes[a] = heap->nodes[b];
    heap->nodes[b] = aux;
}

void heapfy_up(Heap *heap){
    int index = heap->size-1;
    int indexpai;

    while(index != 0){
        indexpai = (index-1)/2;
        if(heap->nodes[index].priority < heap->nodes[indexpai].priority){
            heap_swap(heap, indexpai, index);
        }
        index = indexpai;
    }
}

void heap_push(Heap *heap, void *data, double priority){
    
    if(heap->size == heap->capacity){
        heap->capacity = 2*heap->capacity;
        heap->nodes = (HeapNode *)realloc(heap->nodes, heap->capacity*sizeof(HeapNode));
    }

    heap->nodes[heap->size].data = data;
    heap->nodes[heap->size].priority = priority;
    heap->size++;

    heapfy_up(heap);


} // O(log N)

bool heap_empty(Heap *heap){ //verify if the heap is empty
    
    if(heap->size == 0){
        return true;
    }
    else return false;
} // O(1)

void heapfy_down(Heap *heap){ //makes the lower number ocupy the 1 slot on heap 
    
    int indexpai = 0;
    int indexesq;
    int indexdir;

    while(indexpai < heap->size){  //check if the father have a son
        
        indexesq = (2*indexpai) + 1;
        indexdir = (2*indexpai) + 2;

        if(heap->nodes[indexdir].priority == 0){ //if right is empty compare left/father
            if(heap->nodes[indexesq].priority != 0){
                if(heap->nodes[indexpai].priority >= heap->nodes[indexesq].priority){
                heap_swap(heap, indexpai, indexesq);
                indexpai = indexesq;
            }
            else{break;}
            }
            else{break;}
        }

        else{ // compare right/left
            if(heap->nodes[indexdir].priority <= heap->nodes[indexesq].priority){ // if right < left 
                if(heap->nodes[indexpai].priority >= heap->nodes[indexdir].priority){ // compare right/father
                        heap_swap(heap, indexpai, indexdir);
                        indexpai = indexdir;
                    
                }
            }

            else{ //if left < right
                if(heap->nodes[indexpai].priority >= heap->nodes[indexesq].priority){ //compare left/father
                        heap_swap(heap, indexpai, indexesq);
                        indexpai = indexesq;
                }
            }
        }
    }
}
    
void *heap_pop(Heap *heap){
    HeapNode aux = heap->nodes[0];
    heap->nodes[0] = heap->nodes[heap->size-1]; //makes the last array number on top
    heap->nodes[heap->size-1].priority = 0;
    heap->size--;
    heapfy_down(heap);

    return aux.data; //return the removed number

} // O(log N)

void heap_destroy(Heap *heap){
    free(heap->nodes);
    free(heap);
} // O(1)
