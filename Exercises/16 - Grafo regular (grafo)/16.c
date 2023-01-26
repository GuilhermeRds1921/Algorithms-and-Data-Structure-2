#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct GrafoMA{
   int V;
   int A;
   int **mat;
};
typedef struct GrafoMA GrafoMA;
static int** iniciar_MA(int n){
    int i, j;
    int **mat = (int**) malloc(n * sizeof(int*));
    for (i = 0; i < n; i++)
        mat[i] = (int*) malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            mat[i][j] = 0;
    return mat;
}
static int valida_vertice(GrafoMA* G, int v){
    return (v >= 0) && (v < G->V);
}
GrafoMA* iniciar_grafoMA(int v){
    GrafoMA* G = (GrafoMA*) malloc(sizeof(GrafoMA));

    G->V = v;
    G->A = 0;
    G->mat = iniciar_MA(G->V);

    return G;
}
int aresta_existe(GrafoMA* G, int v1, int v2){
    return (G != NULL) && valida_vertice(G, v1) && valida_vertice(G, v2) && (G->mat[v1][v2] == 1);
}
void inserir_aresta(GrafoMA* G, int v1, int v2){
    if ((G != NULL) && (valida_vertice(G, v1)) && (valida_vertice(G, v2)) && (!aresta_existe(G, v1, v2))){
        G->mat[v1][v2] = G->mat[v2][v1] = 1;
        G->A++;
    }
}
void regular(GrafoMA* graf){
    int i, j, countA = 0, countB = 0;

    for(i=0; i<graf->V;i++){
        for(j=0; j<graf->V; j++){
            if(graf->mat[i][j]==1)
                countA++;
        }
        if(i==0)
            countB = countA;
        if(countA != countB)
            countB = -1;
         countA = 0;
    }

    if(countB != -1)
        printf("sim");
    else
        printf("nao");
}

int main() {
    int i, j, n, val;
    GrafoMA* graf;

    scanf("%d", &n);
    graf = iniciar_grafoMA(n);

    for(i=0; i<n; i++)
        for(j=0; j<n; j++){
            scanf("%d", &val);
            if(val != 0)
                inserir_aresta(graf, i, j);
        }
    regular(graf);
    return 0;
}
