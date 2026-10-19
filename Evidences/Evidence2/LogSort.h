//Cesar Cardenas - A00844803
#ifndef LOGSORT_H
#define LOGSORT_H

#include <ctime>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>

#include "LogRecord.h"
#include "DoublyLinkedList.h"

using namespace std;

inline bool sortLogs(DoublyLinkedList<LogRecord>& logs,
                     const string& fileName, int algorithm) {
    bool alreadyOrdered = logs.isSorted();
    long long comparisons = 0;
    int maxDepth = 0;
    double elapsed = 0;
    int prediction = 1;

    if (!alreadyOrdered) {
        cout << "Predice el crecimiento antes de ordenar: "
                  << "1) n log n  2) n^2: ";

        if (!(cin >> prediction) ||
            (prediction != 1 && prediction != 2)) {
            if (cin.eof()) return false;
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Prediccion invalida.\n";
            return false;
        }

        clock_t start = clock();
        if (algorithm == 1) logs.mergeSort(comparisons, maxDepth);
        else logs.quickSort(comparisons, maxDepth);
        elapsed = 1000.0 * (clock() - start) / CLOCKS_PER_SEC;
    }

    ofstream output("output607.out");

    if (!output) {
        cout << "No se pudo crear output607.out.\n";
        return false;
    }

    const NodeD<LogRecord>* current = logs.getHead();

    while (current != nullptr) {
        output << current->data.original << "\n";
        current = current->next;
    }

    output.close();

    cout << "Algoritmo: "
              << (alreadyOrdered ? "la lista ya estaba ordenada" :
                  (algorithm == 1 ? "Merge Sort" : "Quick Sort"))
              << " | Archivo: " << fileName
              << " | N: " << logs.getSize()
              << " | Tiempo (ms): " << elapsed
              << " | Comparaciones: " << comparisons
              << " | Profundidad maxima: " << maxDepth << "\n";

    if (!alreadyOrdered) {
        cout << "Prediccion: " << (prediction == 1 ? "n log n" : "n^2") << ".\n";
        if (algorithm == 1) {
            cout << "Crecimiento esperado: n log n.\n";
            cout << "La prediccion " << (prediction == 1 ? "coincide" : "no coincide")
                      << " con Merge Sort.\n";
        } else {
            cout << "Quick Sort usa el ultimo elemento como pivote; su caso peor es n^2.\n";
            double nLogN = logs.getSize() * log(static_cast<double>(logs.getSize())) / log(2.0);
            bool looksQuadratic = comparisons > 10 * nLogN;
            cout << "Crecimiento observado aproximado: "
                      << (looksQuadratic ? "n^2" : "n log n") << ".\n";
            cout << "La prediccion "
                      << ((prediction == 2) == looksQuadratic ? "coincide" : "no coincide")
                      << " con las comparaciones de esta ejecucion.\n";
        }
    }

    if (!alreadyOrdered && algorithm == 1) cout << "Merge Sort conserva el orden de fechas empatadas.\n";
    else if (!alreadyOrdered) cout << "Quick Sort puede cambiar el orden de fechas empatadas.\n";
    cout << "Salida: output607.out\n";

    return true;
}

#endif
