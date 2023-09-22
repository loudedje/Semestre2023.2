/*
 * Tarefa 01 - Grafo - Listas de Adjacencia
 *
 * GEN254 - Grafos - 2023/2
 *
 * Nome:      XXXX
 * Matricula: XXXX
 


#include "Aresta.h"
#include "Grafo.h"
#include <iostream>

using namespace std;

int main() {
    try {
        Grafo grafo(5);

        Aresta e(3, 4);

        grafo.insere_aresta(e);
        grafo.imprime();
        
        grafo.insere_aresta(Aresta(4, 2));
        grafo.imprime();
        grafo.insere_aresta(Aresta(3, 4));
        grafo.imprime();

        grafo.remove_aresta(Aresta(4, 2));
        grafo.imprime();
        
        
        int num_arest= grafo.num_arestas__();
       /*std:: cout<<"Há : " <<num_arest<<std::endl; 
        
        grafo.remove_vertice(3);
        grafo.imprime();
       
       std::cout << "Olá, mundo!" << std::endl;  
        grafo.remove_vertice(4);
        grafo.imprime();
       
    }
    catch (const exception &e) {
        cerr << "exception: " << e.what() << "\n";
    }

    return 0;
}
*/