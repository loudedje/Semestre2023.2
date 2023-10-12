/*Nome: Loude Djema Sime

Matricula: 22111000051

*/


#include "Grafo.h"
#include <exception>
#include <stdexcept>
#include <algorithm>
#include <string>
#include <iostream>
#include <queue>  

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

std::vector<int> Grafo::busca_larg(int v) {
    std::vector<int> dist(num_vertices_, 0);
    std::vector<int> marcado(num_vertices_, 0);
    std::vector<int> pai(num_vertices_, 0);

    std::queue<int> fila;
    dist[v] = 0;
    marcado[v] = 1;
    fila.push(v);

    while (!fila.empty()) {
        int w = fila.front();
        fila.pop();

        for (int u = 0; u < num_vertices_; u++) {
            if (aresta_existe(Aresta(w, u)) && marcado[u] == 0) {
                marcado[u] = 1;
                pai[u] = w;
                dist[u] = dist[w] + 1;
                fila.push(u);
            }
        }
    }

    return dist;
}

std::vector<int> Grafo::comparsas(int v) {
    std::vector<int> distancias = busca_larg(v);
    std::vector<int> comparsa;

    for (int i = 0; i < distancias.size(); i++) {
        if (distancias[i] <= 3 && distancias[i] != 0) {
            comparsa.push_back(i);
        }
    }

    return comparsa;
}



