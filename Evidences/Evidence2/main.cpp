//Cesar Cardenas - A00844803
#include <iostream>
#include <limits>
#include <string>

#include "LogRecord.h"
#include "LogLoader.h"
#include "LogSort.h"
#include "LogReports.h"
#include "DoublyLinkedList.h"

using namespace std;

bool askDate(int& year, int& month, int& day) {
    string monthText;
    int enteredYear, enteredMonth, enteredDay;

    cout << "Mes (Jan-Dec): ";
    cin >> monthText;
    enteredMonth = monthNumber(monthText);

    cout << "Dia: ";
    cin >> enteredDay;

    cout << "Year: ";
    cin >> enteredYear;

    if (!cin || enteredMonth == 0 || enteredYear < 1 ||
        enteredDay < 1 || enteredDay > daysInMonth(enteredMonth, enteredYear)) {
        cin.clear();
        cin.ignore(
            numeric_limits<streamsize>::max(), '\n'
        );
        cout << "Fecha invalida.\n";
        return false;
    }

    year = enteredYear;
    month = enteredMonth;
    day = enteredDay;
    return true;
}

int main() {
    string fileName;

    cout << "Archivo (log607-1.txt o log607-2.txt): ";
    cin >> fileName;

    if (fileName != "log607-1.txt" && fileName != "log607-2.txt") {
        cout << "Nombre de archivo invalido.\n";
        return 1;
    }

    DoublyLinkedList<LogRecord> logs;
    int omitted = 0;

    if (!loadLogs(fileName, logs, omitted)) {
        cout << "No se pudo abrir el archivo.\n";
        return 1;
    }

    bool sorted = false;
    bool hasSearch = false;
    int lastYear = 0;
    int lastMonth = 0;
    int lastDay = 0;

    while (true) {
        cout << "\n1. Ordenar"
                  << "\n2. Buscar por dia"
                  << "\n3. Mostrar busqueda al reves"
                  << "\n4. Estadisticas"
                  << "\n5. Salir"
                  << "\nOpcion: ";

        int option;

        if (!(cin >> option)) {
            if (cin.eof()) break;
            cin.clear();
            cin.ignore(
                numeric_limits<streamsize>::max(), '\n'
            );
            cout << "Opcion invalida.\n";
            continue;
        }

        if (option == 1) {
            if (sorted) {
                cout << "La lista ya esta ordenada.\n";
                continue;
            }

            cout << "Algoritmo: 1) Merge Sort  2) Quick Sort: ";
            int algorithm;
            if (!(cin >> algorithm) || (algorithm != 1 && algorithm != 2)) {
                if (cin.eof()) break;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Opcion invalida.\n";
                continue;
            }

            if (sortLogs(logs, fileName, algorithm)) {
                sorted = true;
            }
        } else if (option == 2) {
            if (!sorted) {
                cout << "Primero ordena el archivo.\n";
                continue;
            }

            if (!askDate(lastYear, lastMonth, lastDay)) {
                continue;
            }

            int found = searchDay(logs, lastYear, lastMonth, lastDay);

            if (found == 0) {
                cout << "No hay registros para ese dia.\n";
            } else {
                cout << "Coincidencias: " << found << "\n";
            }

            hasSearch = true;
        } else if (option == 3) {
            if (!sorted) {
                cout << "Primero ordena el archivo.\n";
                continue;
            }

            if (!hasSearch && !askDate(lastYear, lastMonth, lastDay)) {
                continue;
            }

            int found = showDayReverse(logs, lastYear, lastMonth, lastDay);
            if (found == 0) {
                cout << "No hay registros para ese dia.\n";
            } else {
                cout << "Coincidencias mostradas al reves: " << found << "\n";
            }
            hasSearch = true;
        } else if (option == 4) {
            showStatistics(logs);
        } else if (option == 5) {
            break;
        } else {
            cout << "Opcion invalida.\n";
        }
    }

    return 0;
}
