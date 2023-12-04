#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#include "problem.h"
#include "path.h"
#include "dijkstra.h"


int main(){
    FILE *fptr = fopen("arquivo.txt", "r");
    Vector_Mapa *arquivo = leitura_arquivo(fptr); 
    dijkstra_solve(arquivo);
    printf("a");
/*
    Vector *caminhos = dijkstra_solve(arquivo);
    paths_print(caminhos);
    paths_destroy(caminhos);*/
    fclose(fptr);
    leitura_arquivo_destroy(arquivo);
    return 0;
}