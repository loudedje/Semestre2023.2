/*
 * Tarefa 01 - Grafo - Listas de Adjacencia
 *
 * GEN254 - Grafos - 2023/2
 *
 * Nome:      XXXX
 * Matricula: XXXX
 */

#ifndef GRAFO_H

#define GRAFO_H

#include "Aresta.h"
#include <vector>
#include<list>

class Grafo {
public:
    Grafo(int num_vertices);
    // ~Grafo(); // Se necessario
    int num_vertices();
    int num_arestas();
   /* int num_vertices__();
    int num_arestas__();*/
    void insere_aresta(Aresta e);
    void remove_aresta(Aresta e);
    void remover_vertice(int v);
    void imprime();
private:
    int num_vertices_;
    int num_arestas_;
    std::vector<std::list<int>> lista_adj_;

    void valida_vertice(int v);
    void valida_aresta(Aresta e);

};

#endif /* GRAFO_H */
