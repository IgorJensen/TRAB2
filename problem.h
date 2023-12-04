#ifndef _PROBLEM_H_
#define _PROBLEM_H_
#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

typedef struct Node_Mapa{
    int node_source;
    int custo;
    int custo_total;
    int valor_node;
}Node_Mapa;

typedef struct Vector_Mapa{
    Vector *nodes;
    int size;
}Vector_Mapa;


Node_Mapa *node_mapa_construct(int source, int valor, int custo);

Vector_Mapa *leitura_arquivo(FILE *fptr);

Vector_Mapa *vector_mapa_construct();

void leitura_arquivo_destroy(Vector_Mapa *v);

#endif