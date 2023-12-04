#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#include "problem.h"
#include "path.h"
#include "dijkstra.h"


int main(){
    Vector_Mapa *arquivo = leitura_arquivo(); 
    dijkstra_solve(arquivo);
    printf("a");
/*
    Vector *caminhos = dijkstra_solve(arquivo);
    paths_print(caminhos);
    paths_destroy(caminhos);*/
    leitura_arquivo_destroy(arquivo);
    return 0;
}