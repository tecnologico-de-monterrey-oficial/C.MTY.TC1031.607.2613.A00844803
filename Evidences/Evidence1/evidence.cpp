#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "log.h"

using namespace std;

// Implementación de constructores de log.h
Log::Log() {
    year = 2026;
    month = "";
    day = 0;
    time = "";
    ip = "";
    message = "";
    key = "";
}

Log::Log(int year, string month, int day, string time, string ip, string message) {
    this->year = year;
    this->month = month;
    this->day = day;
    this->time = time;
    this->ip = ip;
    this->message = message;
    this->key = createKey();
}

string Log::createKey() {
    // Genera una clave para facilitar ordenamientos y comparaciones
    return to_string(year) + month + to_string(day) + time;
}

// Función para cargar los logs desde el archivo
vector<Log> cargarLogs(string rutaArchivo) {
    vector<Log> lista;
    ifstream archivo(rutaArchivo);

    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo: " << rutaArchivo << endl;
        return lista;
    }

    string month, time, ip, message;
    int day;
    int year = 2026;

    while (archivo >> month >> day >> time >> ip) {
        getline(archivo, message);
        lista.push_back(Log(year, month, day, time, ip, message));
    }

    archivo.close();
    return lista;
}

int main() {
    cout << "=== Evidencia 1: Carga de Datos ===" << endl;

    string archivo = "data/log607-1.txt";
    vector<Log> logs = cargarLogs(archivo);

    cout << "Registros leidos exitosamente: " << logs.size() << endl;

    return 0;
}