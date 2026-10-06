// Cesar Cardenas - A00844803
#include <iostream>
#include <string>
#include "Queue.h"
using namespace std;

struct Cliente {
    string nombre;
    int boletos;
};

int main() {
    Queue<Cliente> fila;
    Cliente cliente;
    int opcion;

    cout << "Cesar Cardenas - A00844803" << endl;

    do {
        cout << "\n1. Llegada de un nuevo cliente" << endl;
        cout << "2. Atender al siguiente cliente" << endl;
        cout << "3. Ver al siguiente cliente" << endl;
        cout << "4. Mostrar cuantas personas hay en la fila" << endl;
        cout << "5. Salir" << endl;
        cout << "Opcion: ";

        if (!(cin >> opcion)) {
            return 0;
        }

        try {
            switch (opcion) {
            case 1:
                cout << "Nombre: ";
                getline(cin >> ws, cliente.nombre);

                cout << "Cantidad de boletos: ";

                if (!(cin >> cliente.boletos)) {
                    return 0;
                }

                if (cliente.boletos <= 0) {
                    cout << "La cantidad debe ser mayor que cero" << endl;
                    break;
                }

                fila.push(cliente);
                cout << "Cliente agregado a la fila" << endl;
                break;

            case 2:
                cliente = fila.pop();

                cout << "Cliente atendido: " << cliente.nombre << endl;
                cout << "Boletos solicitados: " << cliente.boletos << endl;
                break;

            case 3:
                cliente = fila.front();

                cout << "Siguiente cliente: " << cliente.nombre << endl;
                cout << "Boletos solicitados: " << cliente.boletos << endl;
                break;

            case 4:
                cout << "Personas en la fila: " << fila.getSize() << endl;
                break;

            case 5:
                cout << "Programa terminado" << endl;
                break;

            default:
                cout << "Opcion invalida" << endl;
            }
        } catch (const out_of_range& error) {
            cout << "Error: " << error.what() << endl;
        }

    } while (opcion != 5);

    return 0;
}