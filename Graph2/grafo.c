//
// Created by Jeff Goes on 3/21/16.
//

#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

#define BRANCO 0


Grafo* Cria_Grafo (int NV, int grau_max){
    Grafo *G = (Grafo *)malloc(sizeof(Grafo));
    if (G != NULL){
        int i;
        G->NV = NV;                                 //Allocating the number of vertices of my Graph
        G->grau_max = grau_max;                      //Stipulating a max number of vertices
        G->grau = (int*)calloc(NV, sizeof(int));     //Allocating a grau array that will show each vertices' number of connections
        G->arestas=(int**)malloc(NV*sizeof(int));   //Allocating a matrix to represent the graph
        for (i=0; i< NV; i++){
            if (G != NULL) {
                G->arestas[i] = (int *) malloc(grau_max * sizeof(int));      // Adding linked lists
            }
            else {
                printf("Nao foi possível alocar seu Grafo. Erro de Memoria");  //Exception
            }
        }
        if (G->eh_digrafo){                         //If it's directed, create also a matrix to represent its weight
            G->pesos=(float**)malloc(NV*sizeof(float*));
            for (i=0; i<NV; i++){
                G->pesos[i] =(float*) malloc(grau_max*sizeof(float));
            }
        }
    }
    return G;

}

void LiberaGrafo (Grafo* G){
    if (G != NULL){
        int i;
        for (i=0; i<G->NV; i++) {
            free(G->arestas[i]);    //Go over every position and free their respective linked lists
        }
        free(G->arestas);           //Free the array
        if (G->eh_digrafo){
            for (i=0; i<G->NV; i++){
                free(G->pesos[i]);   //Do pretty much same thing with its weights
            }
            free(G->pesos);
        }
        free(G->grau);
            free(G);
    }
}

void InsereAresta (Grafo* G, int v, int u, int eh_digrafo){
    if (G == NULL){
        printf("Grafo invalido");                        ///***CONDITIONS***////
    }                                                   ///***CONDITIONS***////
    if (v < 0 || u >= G->NV || u < 0 || u >= G->NV){    ///***CONDITIONS***////
        printf("Arestas Invalidas");                    ///***CONDITIONS***////
    }
    if (G->grau[v]+1 > G->grau_max){                    ///***CONDITIONS***////
        printf("Voce colocou vertices demais");         ///***CONDITIONS***////
    }

    G->arestas[v][G->grau[v]] = u;          // Insert edge in the last position of the array
    G->grau[v]++;                           //Increment number of connections
    if (eh_digrafo == 0)
        InsereAresta(G, u, v, 1);           //If it' double directed do it again, with the numbers inverted
}

void RemoverAresta (Grafo* G, int v, int u, int eh_digrafo) {
    if (G == NULL) {                        ///***CONDITIONS***////
        printf("Grafo Invalido");           ///***CONDITIONS***////
    }
    if (v < 0 || u >= G->NV) {              ///***CONDITIONS***////
        printf("Arestas Invalidas");        ///***CONDITIONS***////
    }
    if (u < 0 || u >= G->NV) {              ///***CONDITIONS***////
        printf("Arestas Invalidas");        ///***CONDITIONS***////
    }

    int i = 0;
    while (i < G->grau[v] && G->arestas[v][i] != u)         //Go over the array and while it looks for a match
        i++;                                                //Increment variable i;
    if (i == G->grau[v])                                    // if I is equal to the max number of connections then
        printf("aresta inexistente");                       // there are no such edge

    G->grau[v]--;                                           //If there is, connections are lowered by one
    G->arestas[v][i] = G->arestas[v][G->grau[v]];           // Arrange the array
    if (eh_digrafo == 0) {
        RemoverAresta(G, u, v, 1);
    }
}

void ImprimirGrafo (Grafo *G) {
    int i=0, j=0;
    for (i=0; i<G->NV; i++){
        if (G->grau[i] != 0)
            printf("%d", i);
        for (j=0; j<G->grau[i]; j++){
          printf(" %d", G->arestas[i][j]);
        }
        printf("\n");
    }
}

void BuscaProfundidade (Grafo *G, int ini, int *visitado, int cont){
    int i;
    visitado[ini] = cont;
    for (i=0; i<G->grau[ini]; i++){
        if (!visitado[G->arestas[ini][i]])
            BuscaProfundidade(G, G->arestas[ini][i], visitado, cont+1);
    }
}

void BuscaProfundidade_Grafo_Recursao (Grafo* G, int ini, int *visitado){
    int i, cont=1;
    for (i=0; i<G->NV; i++){
        visitado[i] = BRANCO;
        BuscaProfundidade(G, ini, visitado, cont);
    }
}

void BuscaLargura (Grafo *G, int ini, int *visitado){
    int i, vert, NV, cont = 1, *fila, IF = 0, FF=0;
    for (i=0; i<G->NV; i++){
        visitado[i] = 0;
    }
    NV = G->NV;
    fila = (int*)malloc(NV* sizeof(int));
    FF++;
    fila[FF] = ini;
    visitado[ini] = cont;

    while (IF != FF){
        IF = (IF + 1) % NV;
        vert= fila[IF];
        cont++;
        for (i=0; i<G->grau[vert]; i++){
            if (!visitado[G->arestas[vert][i]]){
                FF = (FF + 1) % NV;
                fila[FF] = G->arestas[vert][i];
                visitado[G->arestas[vert][i]] = cont;
            }
        }
    }
    free (fila);
}
