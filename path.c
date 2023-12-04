#include <stdio.h>
#include <stdlib.h>
#include "path.h"
#include "vector.h"

Vector *paths_construct(int size){
    Vector *caminhos = vector_construct();

    for(int i = 0; i < size; i++){
        Node_Mapa *node = node_mapa_construct(0, i, 0);
        vector_push_back(caminhos, node);
    }
    return caminhos;
}

void paths_print(Vector *caminhos){
    Vector *caminho = caminhos;
    Vector *lista = vector_construct();

    for(int i = 1; i< vector_size(caminho); i++){
        Node_Mapa *aux = vector_get(caminho, i);
        int ct = aux->custo_total;

        while(aux->valor_node != 0){
            vector_push_back(lista, aux);
            aux = vector_get(caminho, aux->node_source);
        }
        printf("0->");
        for(int a = 0 ; a < vector_size(lista); a++){
            aux = vector_pop_back(lista);
            if(a == vector_size(lista)-1){
                printf("%d", aux->valor_node);
            }
            printf("%d->", aux->valor_node);
        }
        printf(":%d\n", ct);
    }
    vector_destroy(lista);
}

void paths_destroy(Vector *caminhos){
    for (int i = 0; i < vector_size(caminhos); i++)
    {
        Node_Mapa *node = vector_get(caminhos, i);
        free(node);
    }

    vector_destroy(caminhos);
}