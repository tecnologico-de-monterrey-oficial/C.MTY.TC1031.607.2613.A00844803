#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "log.h"

using namespace std;

// Convierte el nombre del mes a numero
string obtenerNumeroMes(string month) {
    if (month == "Jan") {
        return "01";
    }
    else if (month == "Feb") {
        return "02";
    }
    else if (month == "Mar") {
        return "03";
    }
    else if (month == "Apr") {
        return "04";
    }
    else if (month == "May") {
        return "05";
    }
    else if (month == "Jun") {
        return "06";
    }
    else if (month == "Jul") {
        return "07";
    }
    else if (month == "Aug") {
        return "08";
    }
    else if (month == "Sep") {
        return "09";
    }
    else if (month == "Oct") {
        return "10";
    }
    else if (month == "Nov") {
        return "11";
    }
    else if (month == "Dec") {
        return "12";
    }

    return "00";
}

// Constructor vacio
Log::Log() {
    year = 2026;
    month = "";
    day = 0;
    time = "";
    ip = "";
    message = "";
    key = "";
}

// Constructor con datos
Log::Log(int year, string month, int day, string time,
         string ip, string message) {
    this->year = year;
    this->month = month;
    this->day = day;
    this->time = time;
    this->ip = ip;
    this->message = message;
    this->key = createKey();
}

// Crea una clave para comparar las fechas
string Log::createKey() {
    string numeroMes = obtenerNumeroMes(month);
    string numeroDia = to_string(day);

    if (day < 10) {
        numeroDia = "0" + numeroDia;
    }

    string clave = to_string(year);
    clave = clave + numeroMes;
    clave = clave + numeroDia;
    clave = clave + time;

    return clave;
}

// Operadores para comparar logs
bool Log::operator>(const Log& other) const {
    return key > other.key;
}

bool Log::operator<(const Log& other) const {
    return key < other.key;
}

bool Log::operator==(const Log& other) const {
    return key == other.key;
}

bool Log::operator!=(const Log& other) const {
    return key != other.key;
}

bool Log::operator>=(const Log& other) const {
    return key >= other.key;
}

bool Log::operator<=(const Log& other) const {
    return key <= other.key;
}

// Carga los registros desde un archivo
vector<Log> cargarLogs(string rutaArchivo) {
    vector<Log> lista;
    ifstream archivo(rutaArchivo);

    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo: ";
        cout << rutaArchivo << endl;
        return lista;
    }

    string month;
    string time;
    string ip;
    string message;
    int day;
    int year = 2026;

    while (archivo >> month >> day >> time >> ip) {
        getline(archivo, message);

        Log nuevoLog(year, month, day, time, ip, message);
        lista.push_back(nuevoLog);
    }

    archivo.close();
    return lista;
}

void bubbleSort(vector<Log>& logs) {
    int n = logs.size();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (logs[j] > logs[j + 1]) {
                Log temporal = logs[j];
                logs[j] = logs[j + 1];
                logs[j + 1] = temporal;
            }
        }
    }
}

int main() {
    cout << "=== Evidencia 1: Ordenamiento de Logs ===" << endl;

    string archivo = "data/log607-1.txt";
    vector<Log> logs = cargarLogs(archivo);

    cout << "Registros leidos: " << logs.size() << endl;

    if (logs.size() > 0) {
        cout << "Ordenando los registros con Bubble Sort..." << endl;

        bubbleSort(logs);

        cout << "Los registros fueron ordenados." << endl;

        cout << "Primer registro:" << endl;
        cout << logs[0].month << " "
             << logs[0].day << " "
             << logs[0].time << " "
             << logs[0].ip
             << logs[0].message << endl;

        int ultimaPosicion = logs.size() - 1;

        cout << "Ultimo registro:" << endl;
        cout << logs[ultimaPosicion].month << " "
             << logs[ultimaPosicion].day << " "
             << logs[ultimaPosicion].time << " "
             << logs[ultimaPosicion].ip
             << logs[ultimaPosicion].message << endl;
    }
    else {
        cout << "No hay registros para ordenar." << endl;
    }

    return 0;
}