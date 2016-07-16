

//
// Created by Jeff Goes on 3/21/16.
//

#include <stdlib.h>
#include <stdio.h>
#include "grafo.h"

int main() {

    Grafo *G;
    G = Cria_Grafo(10, 7);
    InsereAresta(G, 0, 1, 1);
    InsereAresta(G, 1, 3, 1);
    InsereAresta(G, 2, 4, 1);
    InsereAresta(G, 3, 0, 1);
    InsereAresta(G, 1, 2, 1);
    InsereAresta(G, 3, 4, 1);
    InsereAresta(G, 4, 1, 1);

    int vis[10];
    BuscaProfundidade_Grafo_Recursao(G, 2, vis);
    for(int i = 0; i<10; i++){
        printf("%d ", vis[i]);
    }
    printf("\n\n");


    ImprimirGrafo(G);
    LiberaGrafo(G);
    return 0;

}