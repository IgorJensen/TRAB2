#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#include "dijkstra.h"
#include "vector.h"
#include <stdbool.h>
#include "problem.h"

//bool vector
Vector *visitados_construct(int size){
    Vector *visitados = vector_construct();
    for(int i = 0 ; i < size; i++){
        vector_push_back (visitados, false);
    }
    return visitados;
}

Node_Mapa vizinhos(void *data){

}

Vector *dijkstra_solve(Vector_Mapa *problem_data){
    Heap *nao_visitados = heap_construct();
    Vector *visitados = visitados_construct(problem_data->size);
    Node_Mapa *Node0 = node_mapa_construct(0, 0, 0);

    heap_push(nao_visitados, Node0->valor_node, Node0->custo_total);
    while(heap_empty(nao_visitados) == false){
        Node_Mapa *no_removido = heap_pop(nao_visitados);

        
    }

}