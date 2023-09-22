#include "Grafo.h"
#include <iostream>

using namespace std;

int main() {
    try {
        Grafo grafo (5);


        grafo.imprimir();
        Aresta e(3, 4);
        grafo.inserir_arestas(e);

        grafo.inserir_arestas(Aresta(5, 2));
        grafo.imprimir();

    }
    catch (const exception &e) {
        cerr << "exception: " << e.what() << "\n";
    }

    return 0;
}
