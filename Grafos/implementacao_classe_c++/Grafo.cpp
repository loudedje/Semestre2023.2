#include "Grafo.h"
#include <iostream>

using namespace std;

Grafo::Grafo(int  num_vertices) {
   num_vertices=num_vertices;
   num_arestas=0;
   matriz_adj_.resize(num_vertices);
/* bout la pou devwa */


   for(int i=0; i<num_vertices; i++){
     matriz_adj_[i].resize(num_vertices,0);
   }
}

void Grafo::inserir_arestas(Aresta e){
    if(matriz_adj_[e.v1][e.v2]==0){
        matriz_adj_[e.v1][e.v2]==1;
        matriz_adj_[e.v2][e.v1]==1;
    }
    num_arestas ++;
}

void Grafo::remover_arestas(Aresta e){
    if(matriz_adj_[e.v1][e.v2]!=0){
        matriz_adj_[e.v1][e.v2]==0;
        matriz_adj_[e.v2][e.v1]==0;
    }
    num_arestas--;

}

void Grafo ::imprimir(Aresta e){
    for(int i=0; i<num_vertices ; i++){
        cout<<i<<":";
        for(int j=0; j<num_vertices; j++){
            if(matriz_adj[i][j] !=0){
                cout << " "<<j;
            }
        }
        cout << "\n";
    }
}