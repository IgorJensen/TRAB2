#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#include "problem.h"

typedef struct
{
    int val;
    int antecessor;
} Node;

int main(){
leitura_arquivo();

//Heap *h = heap_construct();

/*    int tamanho = 6;

    for (int i = tamanho; i > 0; i--)
    {
        Node *a = (Node *)calloc(1, sizeof(Node));
        a->val = i;
        a->antecessor = 0;
        heap_push(h, a, a->val);
    }
    Node *z = heap_pop(h);

    z = heap_pop(h);

    printf("Valor do node removido: %d\n", z->val);
*/

    return 0;
}