// Cesar Cardenas - A00844803
#include <iostream>
#include <limits>
#include <string>

#include "LogRecord.h"
#include "LogLoader.h"
#include "LogSort.h"
#include "LogReports.h"
#include "DoublyLinkedList.h"

bool askDate(int& year, int& month, int& day) {
    std::string monthText;

    std::cout << "Mes (Jan-Dec): ";
    std::cin >> monthText;
    month = monthNumber(monthText);

    std::cout << "Dia: ";
    std::cin >> day;

    std::cout << "Anio: ";
    std::cin >> year;

    if (!std::cin || month == 0 || year < 1 ||
        day < 1 || day > daysInMonth(month, year)) {
        std::cin.clear();
        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(), '\n'
        );
        std::cout << "Fecha invalida.\n";
        return false;
    }

    return true;
}

int main() {
    std::string fileName;

    std::cout << "Archivo (log607-1.txt o log607-2.txt): ";
    std::cin >> fileName;

    if (fileName != "log607-1.txt" && fileName != "log607-2.txt") {
        std::cout << "Nombre de archivo invalido.\n";
        return 1;
    }

    DoublyLinkedList<LogRecord> logs;
    int omitted = 0;

    if (!loadLogs(fileName, logs, omitted)) {
        std::cout << "No se pudo abrir el archivo.\n";
        return 1;
    }

    bool sorted = false;
    bool hasSearch = false;
    int lastYear = 0;
    int lastMonth = 0;
    int lastDay = 0;

    while (true) {
        std::cout << "\n1. Ordenar"
                  << "\n2. Buscar por dia"
                  << "\n3. Mostrar busqueda al reves"
                  << "\n4. Estadisticas"
                  << "\n5. Salir"
                  << "\nOpcion: ";

        int option;

        if (!(std::cin >> option)) {
            std::cin.clear();
            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(), '\n'
            );
            std::cout << "Opcion invalida.\n";
            continue;
        }

        if (option == 1) {
            if (sorted) {
                std::cout << "La lista ya esta ordenada.\n";
                continue;
            }

            if (sortLogs(logs, fileName)) {
                sorted = true;
            }
        } else if (option == 2) {
            if (!sorted) {
                std::cout << "Primero ordena el archivo.\n";
                continue;
            }

            if (!askDate(lastYear, lastMonth, lastDay)) {
                continue;
            }

            int found = searchDay(logs, lastYear, lastMonth, lastDay);

            if (found == 0) {
                std::cout << "No hay registros para ese dia.\n";
            } else {
                std::cout << "Coincidencias: " << found << "\n";
            }

            hasSearch = true;
        } else if (option == 3) {
            if (!sorted) {
                std::cout << "Primero ordena el archivo.\n";
                continue;
            }

            if (!hasSearch && !askDate(lastYear, lastMonth, lastDay)) {
                continue;
            }

            showDayReverse(logs, lastYear, lastMonth, lastDay);
            hasSearch = true;
        } else if (option == 4) {
            showStatistics(logs);
        } else if (option == 5) {
            break;
        } else {
            std::cout << "Opcion invalida.\n";
        }
    }

    return 0;
}