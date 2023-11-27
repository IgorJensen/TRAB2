#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#include "dijkstra.h"
#include "vector.h"
#include <stdbool.h>

//bool vector
Vector visitados_construct(int size){
    Vector *visitados = vector_construct();
    for(int i = 0 ; i < size; i++){
        vector_push_back (visitados, false);
    }
    return visitados;
}

Vector *visitado(Vector *visitados, int source){
    Vector *vizinhos = vector_construct();
    bool visitado_check;
    Node_Mapa *aux = vector_get()
    
}



