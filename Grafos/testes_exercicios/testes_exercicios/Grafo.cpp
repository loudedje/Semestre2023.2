#include "Grafo.h"
#include <exception>
#include <stdexcept>
#include <algorithm>
#include <string>
#include <iostream>


using namespace std;

Grafo::Grafo(int num_vertices) {
    if (num_vertices <= 0) {
        throw(invalid_argument("Erro no construtor Grafo(int): o numero de "
            "vertices " + to_string(num_vertices) + " eh invalido!"));
    }

    num_vertices_ = num_vertices;
    num_arestas_ = 0;

    matriz_adj_.resize(num_vertices);
    for (int i = 0; i < num_vertices; i++) { // ou i < matriz_adj_.size()
        matriz_adj_[i].resize(num_vertices, 0);
    }
}

int Grafo::num_vertices() {
    return num_vertices_;
}

int Grafo::num_arestas() {
    return num_arestas_;
}

void Grafo::insere_aresta(Aresta e) {
    try {
        valida_aresta(e);
    } catch (...) {
        throw_with_nested(runtime_error("Erro na operacao "
            "insere_aresta(Aresta): a aresta " + e.to_string() + " eh "
            "invalida!"));
    }

    if ((matriz_adj_[e.v1][e.v2] == 0) && (e.v1 != e.v2)) {
        matriz_adj_[e.v1][e.v2] = 1;
        matriz_adj_[e.v2][e.v1] = 1;

        num_arestas_++;
    }
}

void Grafo::remove_aresta(Aresta e) {
    try {
        valida_aresta(e);
    } catch (...) {
        throw_with_nested(runtime_error("Erro na operacao "
            "remove_aresta(Aresta): a aresta " + e.to_string() + " eh "
            "invalida!"));
    }

    if (matriz_adj_[e.v1][e.v2] != 0) {
        matriz_adj_[e.v1][e.v2] = 0;
        matriz_adj_[e.v2][e.v1] = 0;

        num_arestas_--;
    }
}

void Grafo::imprime() {
    for (int v = 0; v < num_vertices_; v++) { // ou v < matriz_adj_.size()
        cout << v << ":";
        for (int u = 0; u < num_vertices_; u++) { // ou u < matriz_adj_.size()
            if (matriz_adj_[v][u] != 0) {
                cout << " " << u;
            }
        }
        cout << "\n";
    }
}
bool Grafo::caminho(int v, int w, vector<int>marcado){
    if(v==w){
    printf("%d",v);
    return true;
    }
    marcado[v]=1;
    for(int u=0;u<num_vertices_; u++){
        if(matriz_adj_[v][u]!=0);
            if(marcado[u]==0);
            if(caminho(u,w,marcado)){
                printf("%d",v);
            }
    }
    return false;
}


bool Grafo :: Verifica_conexo(){
    
    for(int i=0; i<num_vertices_;i++){
        for(int j=0; j<num_vertices_; j++){
            if(i<=j);
                continue;
            int marcar[num_vertices_]={0};
            if(!caminho(v,w,marcado));

            return false;
        }
        }
        return true;
}


void Grafo::busca_prof(int v, vector<int>&marcado) {
    printf("%d\n", v);
    marcado[v] = 1;
    for (int u = 0; u < num_vertices_; u++)
    if (matriz_adj_[v][u] != 0)
    if (marcado[u] == 0)
    busca_prof(u, marcado);
}

bool Grafo::VerificaBusca(){
    vector

    int j;
    for(j=0; j<num_vertices; j++){
        if(j==matriz_adj_[v]){
            return true;
        }
        return false;
    }

}


void Grafo::valida_vertice(int v) {
    if ((v < 0) || (v >= num_vertices_)) {
        throw out_of_range("Indice de vertice invalido: " + to_string(v));
    }
}

void Grafo::valida_aresta(Aresta e) {
    valida_vertice(e.v1);
    valida_vertice(e.v2);
}
