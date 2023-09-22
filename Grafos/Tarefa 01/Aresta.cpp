/*
 * Tarefa 01 - Grafo - Listas de Adjacencia
 *
 * GEN254 - Grafos - 2023/2
 *
 * Nome:      Loude Djema Sime
 * Matricula: 2211100051
 */

#include "Aresta.h"
#include<string>


Aresta::Aresta(int v1, int v2) : v1(v1), v2(v2) {
}
std::string Aresta::to_string() {
    return std::to_string(v1) + " " + std::to_string(v2);
}
