//
// Created by Jeff Goes on 3/21/16.
//

#ifndef GRAPH2_GRAFO_H
#define GRAPH2_GRAFO_H

typedef struct{
    int peso;
    int eh_digrafo;
    int  NV;
    int grau_max;
    int **arestas;
    float **pesos;
    int *grau;
}Grafo;


Grafo* Cria_Grafo (int NV, int grau_max);
void LiberaGrafo (Grafo*);
void InsereAresta (Grafo*, int v, int u, int eh_digrafo);
void RemoverAresta (Grafo*, int v, int u, int eh_digrafo);
void ImprimirGrafo (Grafo*);
void BuscaProfundidade (Grafo* , int ini, int *visitado, int cont);
void BuscaProfundidade_Grafo_Recursao (Grafo* , int ini, int *visitado);
//void BuscaLargura (Grafo *, int, int *);
#endif //GRAPH2_GRAFO_H
