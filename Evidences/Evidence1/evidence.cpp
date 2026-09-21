#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "log.h"

using namespace std;

// convierte el mes a numero
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

// constructor vacio
Log::Log() {
    year = 0;
    month = "";
    day = 0;
    time = "";
    ip = "";
    message = "";
    key = "";
}

// constructor con los datos del log
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

// junta la fecha y la hora en una sola clave
string Log::createKey() {
    string numeroMes = obtenerNumeroMes(month);
    string numeroDia = to_string(day);

    // agrega un cero a los dias menores a 10
    if (day < 10) {
        numeroDia = "0" + numeroDia;
    }

    string clave = to_string(year);
    clave = clave + numeroMes;
    clave = clave + numeroDia;
    clave = clave + time;

    return clave;
}

// compara si un log es mayor que otro
bool Log::operator>(const Log& other) const {
    return key > other.key;
}

// compara si un log es menor que otro
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

// lee los registros del archivo
vector<Log> cargarLogs(string rutaArchivo) {
    vector<Log> lista;
    ifstream archivo(rutaArchivo);

    // revisa si el archivo se pudo abrir
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
    int year;

    // lee una linea y crea un log
    while (archivo >> month >> day >> year >> time >> ip) {
        getline(archivo, message);

        Log nuevoLog(year, month, day, time, ip, message);
        lista.push_back(nuevoLog);
    }

    archivo.close();
    return lista;
}

// ordena comparando cada elemento con los siguientes
void swapSort(vector<Log>& logs) {
    int n = logs.size();

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (logs[i] > logs[j]) {
                Log temporal = logs[i];
                logs[i] = logs[j];
                logs[j] = temporal;
            }
        }
    }
}

// busca el menor y lo coloca en su posicion
void selectionSort(vector<Log>& logs) {
    int n = logs.size();

    for (int i = 0; i < n - 1; i++) {
        int menor = i;

        for (int j = i + 1; j < n; j++) {
            if (logs[j] < logs[menor]) {
                menor = j;
            }
        }

        if (menor != i) {
            Log temporal = logs[i];
            logs[i] = logs[menor];
            logs[menor] = temporal;
        }
    }
}

// ordena los logs usando bubble sort
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

// toma cada log y lo coloca en su lugar
void insertionSort(vector<Log>& logs) {
    int n = logs.size();

    for (int i = 1; i < n; i++) {
        Log actual = logs[i];
        int j = i - 1;

        while (j >= 0 && logs[j] > actual) {
            logs[j + 1] = logs[j];
            j--;
        }

        logs[j + 1] = actual;
    }
}

// junta dos partes ordenadas
void merge(vector<Log>& logs, int inicio, int mitad, int fin) {
    vector<Log> temporal;

    int i = inicio;
    int j = mitad + 1;

    while (i <= mitad && j <= fin) {
        if (logs[i] <= logs[j]) {
            temporal.push_back(logs[i]);
            i++;
        }
        else {
            temporal.push_back(logs[j]);
            j++;
        }
    }

    // agrega los que faltan de la izquierda
    while (i <= mitad) {
        temporal.push_back(logs[i]);
        i++;
    }

    // agrega los que faltan de la derecha
    while (j <= fin) {
        temporal.push_back(logs[j]);
        j++;
    }

    // pasa los datos al vector original
    for (int k = 0; k < temporal.size(); k++) {
        logs[inicio + k] = temporal[k];
    }
}

// divide el vector y despues junta las partes
void mergeSort(vector<Log>& logs, int inicio, int fin) {
    if (inicio < fin) {
        int mitad = (inicio + fin) / 2;

        mergeSort(logs, inicio, mitad);
        mergeSort(logs, mitad + 1, fin);

        merge(logs, inicio, mitad, fin);
    }
}

// muestra un log en la consola
void mostrarLog(Log registro) {
    cout << registro.month << " "
         << registro.day << " "
         << registro.year << " "
         << registro.time << " "
         << registro.ip
         << registro.message << endl;
}

// guarda los logs ordenados en otro archivo
void guardarLogs(vector<Log>& logs, string nombreArchivo) {
    ofstream archivo(nombreArchivo);

    // revisa si el archivo se pudo crear
    if (!archivo.is_open()) {
        cout << "No se pudo crear el archivo de salida." << endl;
        return;
    }

    // guarda cada log con el formato original
    for (int i = 0; i < logs.size(); i++) {
        archivo << logs[i].month << " "
                << logs[i].day << " "
                << logs[i].year << " "
                << logs[i].time << " "
                << logs[i].ip
                << logs[i].message << endl;
    }

    archivo.close();

    cout << "Los registros se guardaron en ";
    cout << nombreArchivo << endl;
}

int main() {
    cout << "=== Evidencia 1: Ordenamiento de Logs ===" << endl;

    // por ahora se usa el primer archivo
    string archivo = "log607-1.txt";

    vector<Log> logs = cargarLogs(archivo);

    cout << "Registros leidos: ";
    cout << logs.size() << endl;

    if (logs.size() > 0) {
        int opcion;

        cout << endl;
        cout << "Elige un algoritmo:" << endl;
        cout << "1. Swap Sort" << endl;
        cout << "2. Selection Sort" << endl;
        cout << "3. Bubble Sort" << endl;
        cout << "4. Insertion Sort" << endl;
        cout << "5. Merge Sort" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            cout << "Ordenando con Swap Sort..." << endl;
            swapSort(logs);
        }
        else if (opcion == 2) {
            cout << "Ordenando con Selection Sort..." << endl;
            selectionSort(logs);
        }
        else if (opcion == 3) {
            cout << "Ordenando con Bubble Sort..." << endl;
            bubbleSort(logs);
        }
        else if (opcion == 4) {
            cout << "Ordenando con Insertion Sort..." << endl;
            insertionSort(logs);
        }
        else if (opcion == 5) {
            cout << "Ordenando con Merge Sort..." << endl;
            mergeSort(logs, 0, logs.size() - 1);
        }
        else {
            cout << "La opcion no es valida." << endl;
            return 0;
        }

        cout << "Los registros fueron ordenados." << endl;

        guardarLogs(logs, "output607.txt");

        cout << "Primer registro:" << endl;
        mostrarLog(logs[0]);

        int ultimaPosicion = logs.size() - 1;

        cout << "Ultimo registro:" << endl;
        mostrarLog(logs[ultimaPosicion]);
    }
    else {
        cout << "No hay registros para ordenar." << endl;
    }

    return 0;
}