#ifndef LOGSORT_H
#define LOGSORT_H

#include <ctime>
#include <fstream>
#include <iostream>
#include <string>

#include "LogRecord.h"
#include "DoublyLinkedList.h"

inline bool sortLogs(DoublyLinkedList<LogRecord>& logs,
                     const std::string& fileName) {
    bool alreadyOrdered = logs.isSorted();
    long long comparisons = 0;
    int maxDepth = 0;
    double elapsed = 0;
    int prediction = 1;

    if (!alreadyOrdered) {
        std::cout << "Prediccion de crecimiento: "
                  << "1) n log n  2) n^2: ";

        if (!(std::cin >> prediction) ||
            (prediction != 1 && prediction != 2)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Prediccion invalida.\n";
            return false;
        }

        clock_t start = clock();
        logs.mergeSort(comparisons, maxDepth);
        elapsed = 1000.0 * (clock() - start) / CLOCKS_PER_SEC;
    }

    std::ofstream output("output607.out");

    if (!output) {
        std::cout << "No se pudo crear output607.out.\n";
        return false;
    }

    const NodeD<LogRecord>* current = logs.getHead();

    while (current != nullptr) {
        output << current->data.original << "\n";
        current = current->next;
    }

    output.close();

    std::cout << "Algoritmo: "
              << (alreadyOrdered ? "la lista ya estaba ordenada" : "Merge Sort")
              << " | Archivo: " << fileName
              << " | N: " << logs.getSize()
              << " | Tiempo (ms): " << elapsed
              << " | Comparaciones: " << comparisons
              << " | Profundidad maxima: " << maxDepth << "\n";

    if (!alreadyOrdered) {
        std::cout << "Prediccion n log n: "
                  << (prediction == 1 ? "coincide" : "no coincide")
                  << ".\n";
    }

    std::cout << "Merge Sort conserva el orden de las fechas empatadas.\n"
              << "Salida: output607.out\n";

    return true;
}

#endif