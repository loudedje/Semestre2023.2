/* Tarefa 01 - Grafo - Listas de Adjacencia
 *
 * GEN254 - Grafos - 2023/2
 *
 * Nome:      XXXX
 * Matricula: XXXX
 */

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
    lista_adj_.resize(num_vertices);
}


int Grafo::num_vertices(){
    return num_vertices_;
}

int Grafo::num_arestas() {
    return num_arestas_;
}

bool Grafo::aresta_existe(Aresta e) {
    for (int v : lista_adj_[e.v1]) {
        if (v == e.v2) {
            return true;
        }
    }
    return false;
}

void Grafo::insere_aresta(Aresta e) {
    if (e.v1 == e.v2 || aresta_existe(e)) {
        return;
    }
    for (int vizinho : lista_adj_[e.v1]) {
        if (vizinho == e.v2) {
            return;
        }
    }
    lista_adj_[e.v1].push_front(e.v2);
    lista_adj_[e.v2].push_front(e.v1);
    num_arestas_++;
}

void Grafo::remove_aresta(Aresta e){
    if(aresta_existe(e)){
        lista_adj_[e.v1].remove(e.v2);
        lista_adj_[e.v2].remove(e.v1);

        num_arestas_--;
    }
}

void Grafo::imprime() {
    for (auto i = 0; i < num_vertices_; i++) {
        cout << i << ":";
        for (auto j : lista_adj_[i]) {
            cout << " " << j;
        }
        cout << "\n";
    }
}

void Grafo::remover_vertice(int v){
    if(v < 0 || v>num_vertices_){
        return;
    }
    for(int j =0;j < lista_adj_.size();j++){
        if(j == v){
        for(auto x: lista_adj_[j]){
            Aresta e(v,x);
            remove_aresta(e);
            break;
            }
        }
    }
    
    for(int i = 0;i < lista_adj_.size();i++){
        for(int& nvert: lista_adj_[i]){
            if(nvert > v){
                nvert -=1;
            }
        }
    }

    for(int i =0;i< lista_adj_.size()-1;i++){
        if(i >=v){
            lista_adj_[i] = lista_adj_[i+1];
        }
    }
    num_vertices_--;
    lista_adj_.resize(num_vertices_);
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
