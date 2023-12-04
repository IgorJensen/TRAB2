#include <stdio.h>
#include <stdlib.h>
#include "problem.h"

Node_Mapa *node_mapa_construct(int source, int valor, int custo){
    Node_Mapa *m = (Node_Mapa *)calloc(1, sizeof(Node_Mapa));
    m->node_source = source; 
    m->custo = custo; //custo para nó alvo
    m->custo_total = 0;
    m->valor_node = valor; // nó alvo
    return m;
};

Vector_Mapa *vector_mapa_construct(){
    Vector_Mapa *v = (Vector_Mapa *)calloc(1, sizeof(Vector_Mapa));
    v->nodes = vector_construct();
    v->size = 0;
    return v;
};

Vector_Mapa *leitura_arquivo(FILE *fptr){
    Vector_Mapa *v = vector_mapa_construct();
    int node_count;
    int valor, custo;
    char last_char;

// Open a file in read mode
    fscanf(fptr, "%d\n", &node_count); // reads 1 line
    v->size = node_count; // + 1; // nodes vector size

    for (int i = 0; i < node_count; i++){
        while (1){
            fscanf(fptr, "%d%d%c", &valor, &custo, &last_char); // reads by pairs the file

            Node_Mapa *m = node_mapa_construct(i, valor, custo); // creates a node to store the infos 
            vector_push_back(v->nodes, m); 
            printf("Origem: %d, Nó alvo: %d, custo: %d \n", i, valor, custo);
            if (last_char == '\n'){ // checks if the line has no more characters
                break;
            }   
        }
    }
    return v;
}

void leitura_arquivo_destroy(Vector_Mapa *v){
    for(int i = 0 ; i < v->size ; i++){
        Node_Mapa *m = vector_get(v->nodes, i);
        free(m);
    } 
    vector_destroy(v->nodes);
    free(v);
}