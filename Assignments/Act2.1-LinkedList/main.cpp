// Cesar Cardenas - A00844803

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include "LinkedList.h"

using namespace std;

// Este menu funciona con enteros y decimales
template <typename T>
void menu() {
    LinkedList<T> list;

    int mode;
    int amount;
    int option;
    int index;
    T data;
    T newData;

    cout << "\n1. Crear con datos capturados" << endl;
    cout << "2. Crear con datos aleatorios" << endl;
    cout << "Opcion: ";
    cin >> mode;

    if (mode != 1 && mode != 2) {
        cout << "Opcion invalida" << endl;
        return;
    }

    cout << "Cantidad de elementos: ";
    cin >> amount;

    if (amount < 0) {
        cout << "La cantidad no puede ser negativa" << endl;
        return;
    }

    for (int i = 0; i < amount; i++) {
        if (mode == 1) {
            cout << "Dato: ";
            cin >> data;
        } else {
            data = static_cast<T>((rand() % 1000) / 10.0);
        }

        list.addLast(data);
    }

    cout << "Lista creada: ";
    list.print();

    do {
        cout << "\n1. Agregar al principio" << endl;
        cout << "2. Agregar al final" << endl;
        cout << "3. Insertar despues de un indice" << endl;
        cout << "4. Borrar por dato" << endl;
        cout << "5. Borrar por posicion" << endl;
        cout << "6. Obtener por posicion" << endl;
        cout << "7. Actualizar por dato" << endl;
        cout << "8. Actualizar por posicion" << endl;
        cout << "9. Buscar dato" << endl;
        cout << "10. Leer usando []" << endl;
        cout << "11. Actualizar usando []" << endl;
        cout << "12. Duplicar usando =" << endl;
        cout << "0. Volver" << endl;
        cout << "Opcion: ";

        if (!(cin >> option)) {
            return;
        }

        try {
            switch (option) {
            case 1:
                cout << "Dato: ";
                cin >> data;
                list.addFirst(data);
                break;

            case 2:
                cout << "Dato: ";
                cin >> data;
                list.addLast(data);
                break;

            case 3:
                cout << "Indice: ";
                cin >> index;
                cout << "Dato: ";
                cin >> data;
                list.insert(index, data);
                break;

            case 4:
                cout << "Dato a borrar: ";
                cin >> data;

                if (list.deleteData(data)) {
                    cout << "Dato borrado" << endl;
                } else {
                    cout << "El dato no existe" << endl;
                }
                break;

            case 5:
                cout << "Posicion: ";
                cin >> index;

                if (list.deleteAt(index)) {
                    cout << "Dato borrado" << endl;
                } else {
                    cout << "La posicion no existe" << endl;
                }
                break;

            case 6:
                cout << "Posicion: ";
                cin >> index;
                data = list.getData(index);
                cout << "Dato: " << data << endl;
                break;

            case 7:
                cout << "Dato a buscar: ";
                cin >> data;
                cout << "Dato nuevo: ";
                cin >> newData;
                list.updateData(data, newData);
                break;

            case 8:
                cout << "Posicion: ";
                cin >> index;
                cout << "Dato nuevo: ";
                cin >> data;
                list.updateAt(index, data);
                break;

            case 9:
                cout << "Dato a buscar: ";
                cin >> data;
                index = list.findData(data);
                cout << "Posicion: " << index << endl;
                break;

            case 10:
                cout << "Posicion: ";
                cin >> index;
                data = list[index];
                cout << "Dato: " << data << endl;
                break;

            case 11:
                cout << "Posicion: ";
                cin >> index;
                cout << "Dato nuevo: ";
                cin >> data;
                list[index] = data;
                break;

            case 12: {
                LinkedList<T> copy;
                copy = list;

                cout << "Lista duplicada: ";
                copy.print();
                break;
            }

            case 0:
                break;

            default:
                cout << "Opcion invalida" << endl;
            }
        } catch (const out_of_range& error) {
            cout << "Error: " << error.what() << endl;
        }

        if (option != 0) {
            cout << "Lista actual: ";
            list.print();
        }

    } while (option != 0);
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    int type;

    cout << "Cesar Cardenas - A00844803" << endl;

    do {
        cout << "\nTipo de lista:" << endl;
        cout << "1. Enteros" << endl;
        cout << "2. Decimales" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";

        if (!(cin >> type)) {
            return 0;
        }

        switch (type) {
        case 1:
            menu<int>();
            break;

        case 2:
            menu<double>();
            break;

        case 0:
            break;

        default:
            cout << "Opcion invalida" << endl;
        }

    } while (type != 0);

    return 0;
}
