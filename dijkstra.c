#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#include "dijkstra.h"
#include "vector.h"
#include <stdbool.h>
#include "problem.h"
#include "path.h"

//bool vector
Vector *visitados_construct(int size){
    Vector *visitados = vector_construct();
    for(int i = 0 ; i < size; i++){
        vector_push_back (visitados, false);
    }
    return visitados;
}

//retorna os vizinhos do nó
Vector *vizinhos_get(Vector *visitados, Vector *nodes, int origem){
    Vector *vizinhos = vector_construct();
    
    for(int i = 0 ; i < vector_size(nodes); i++){
        Node_Mapa *aux = vector_get(nodes, i);
        bool visita = vector_get(visitados, aux->valor_node);

        if(aux->node_source == origem && visita == false){
            vector_push_back(vizinhos, aux);
        }
    }
    return vizinhos;
}

bool check_visita(Vector *visitados){

    for(int i = 0; i < vector_size(visitados); i++){

        if(vector_get(visitados, i) == false){
            return false;
        }
    }
    return true;
}

Vector *dijkstra_solve(Vector_Mapa *problem_data){
    
    Heap *nao_visitados = heap_construct();
    Vector *visitados = visitados_construct(problem_data->size);
    Node_Mapa *Node0 = node_mapa_construct(0, 0, 0);
    Vector *caminhos = paths_construct(problem_data->size);
    bool visita = true;
    Node_Mapa *path_node;
    heap_push(nao_visitados, Node0, Node0->custo_total);

    while(heap_empty(nao_visitados) == false || check_visita(visitados) == false){
        Node_Mapa *no_removido = heap_pop(nao_visitados);
        
        if (vector_get(visitados, no_removido->valor_node) == false){
            
        //caminhos
        path_node = vector_get(caminhos, no_removido->valor_node);
        path_node->custo_total = no_removido->custo_total;
        path_node->custo = no_removido->custo;
        path_node->node_source = no_removido->node_source;
        
        Vector *vizinhos = vizinhos_get(visitados, problem_data->nodes, no_removido->node_source);
        
        for(int i = 0; i < vector_size(vizinhos); i++){
            Node_Mapa *Node = vector_get(vizinhos, i);
            printf("Source: %d Valor: %d   ", Node->node_source, Node->valor_node);
            Node->custo_total = Node->custo + no_removido->custo_total;
            heap_push(nao_visitados, Node, Node->custo_total);
            printf("Custo total: %d  ", Node->custo_total);
        }
        printf("\n");
        vector_set(visitados, no_removido->valor_node, &visita);
        vector_destroy(vizinhos); 
        }
    }
    printf("4");
    vector_destroy(visitados);
    heap_destroy(nao_visitados);
    free(Node0);

    return caminhos;
}