#include "Grafo.h"
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    int V, O;
    cin >> V >> O;

    Grafo grafo(V);

    for (int i = 0; i < O; i++) {
        char operacao;
        cin >> operacao;

        if (operacao == 'I') {
            int X, Y;
            cin >> X >> Y;
            Aresta e(X, Y);
            grafo.insere_aresta(e);
        } else if (operacao == 'R') {
            int X, Y;
            cin >> X >> Y;
            Aresta e(X, Y);
            grafo.remove_aresta(e);
        } else if (operacao == 'E') {
            cout << grafo.num_arestas() << endl;
        } else if (operacao == 'Q'){
            int X;
            cin >> X;
            grafo.remover_vertice(X);
        }else if (operacao == 'N') {
            cout << grafo.num_vertices() << endl;
        } else if (operacao == 'P') {
            grafo.imprime();
        }
    }

    return 0;
}
