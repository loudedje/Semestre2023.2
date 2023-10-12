#ifndef GRAFO_H

#define GRAFO_H

#include "Aresta.h"
#include <vector>
#include<list>

class Grafo {
public:
    Grafo(int num_vertices);
    bool aresta_existe(Aresta e);
    void insere_aresta(Aresta e);    
    std::vector<int>busca_larg(int v);
    std::vector<int> comparsas(int v);
    

private:
    int num_vertices_;
    int num_arestas_;
    std::vector<std::list<int>> lista_adj_;
};

#endif /* GRAFO_H */
