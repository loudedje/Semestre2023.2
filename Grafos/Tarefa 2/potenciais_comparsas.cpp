#include "Grafo.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int main() {
    int P, L, X, Y, O;

    cin >> P >> L;
    cin.ignore();
    Grafo grafo(P);

    for (int i = 0; i < L; i++) {
        vector<string> operacao;
        string entrada;
        getline(cin, entrada);

        stringstream ss(entrada);

        while (ss >> entrada) {
            operacao.push_back(entrada);
        }
        if (operacao[2] == "W") {
            X = stoi(operacao[0]);
            Y = stoi(operacao[1]);
            Aresta e(X, Y);
            grafo.insere_aresta(e);
        }
    }

    cin >> O;
    for (int i = 0; i < O; i++) {
        int comparsa;
        cin >> comparsa;
        vector<int> comparsas = grafo.comparsas(comparsa);

        cout << comparsa << ":";
        for (int j = 0; j < comparsas.size(); j++) {
            cout << " " << comparsas[j];
        }
        cout << endl;
    }

    return 0;
}
