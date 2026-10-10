// Cesar Cardenas - A00844803
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "DoublyLinkedList.h"
using namespace std;

int main() {
    DoublyLinkedList<int> list;

    int mode;
    int amount;
    int data;
    int newData;
    int index;
    int option;

    srand(static_cast<unsigned int>(time(nullptr)));

    cout << "Cesar Cardenas - A00844803" << endl;

    cout << "1. Crear con datos capturados" << endl;
    cout << "2. Crear con datos aleatorios" << endl;
    cout << "Opcion: ";

    if (!(cin >> mode)) {
        return 0;
    }

    if (mode != 1 && mode != 2) {
        cout << "Opcion invalida" << endl;
        return 0;
    }

    cout << "Cantidad de elementos: ";

    if (!(cin >> amount)) {
        return 0;
    }

    if (amount < 0) {
        cout << "La cantidad no puede ser negativa" << endl;
        return 0;
    }

    for (int i = 0; i < amount; i++) {
        if (mode == 1) {
            cout << "Dato: ";

            if (!(cin >> data)) {
                return 0;
            }
        } else {
            data = rand() % 100;
        }

        list.addLast(data);
    }

    cout << "Lista creada: ";
    list.print();

    do {
        cout << "\n1. Agregar al principio" << endl;
        cout << "2. Agregar al final" << endl;
        cout << "3. Insertar a la derecha de un indice" << endl;
        cout << "4. Borrar por dato" << endl;
        cout << "5. Borrar por posicion" << endl;
        cout << "6. Obtener por posicion" << endl;
        cout << "7. Actualizar por dato" << endl;
        cout << "8. Actualizar por posicion" << endl;
        cout << "9. Buscar dato" << endl;
        cout << "10. Leer usando []" << endl;
        cout << "11. Actualizar usando []" << endl;
        cout << "12. Copiar la lista usando =" << endl;
        cout << "13. Limpiar la lista" << endl;
        cout << "14. Ordenar la lista" << endl;
        cout << "15. Duplicar cada elemento" << endl;
        cout << "16. Remover duplicados" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";

        if (!(cin >> option)) {
            return 0;
        }

        try {
            switch (option) {
            case 1:
                cout << "Dato: ";
                if (!(cin >> data)) return 0;
                list.addFirst(data);
                break;

            case 2:
                cout << "Dato: ";
                if (!(cin >> data)) return 0;
                list.addLast(data);
                break;

            case 3:
                cout << "Indice: ";
                if (!(cin >> index)) return 0;

                cout << "Dato: ";
                if (!(cin >> data)) return 0;

                list.insert(index, data);
                break;

            case 4:
                cout << "Dato a borrar: ";
                if (!(cin >> data)) return 0;

                cout << boolalpha << list.deleteData(data) << endl;
                break;

            case 5:
                cout << "Posicion: ";
                if (!(cin >> index)) return 0;

                cout << boolalpha << list.deleteAt(index) << endl;
                break;

            case 6:
                cout << "Posicion: ";
                if (!(cin >> index)) return 0;

                data = list.getData(index);
                cout << "Dato: " << data << endl;
                break;

            case 7:
                cout << "Dato a buscar: ";
                if (!(cin >> data)) return 0;

                cout << "Dato nuevo: ";
                if (!(cin >> newData)) return 0;

                list.updateData(data, newData);
                break;

            case 8:
                cout << "Posicion: ";
                if (!(cin >> index)) return 0;

                cout << "Dato nuevo: ";
                if (!(cin >> data)) return 0;

                list.updateAt(index, data);
                break;

            case 9:
                cout << "Dato a buscar: ";
                if (!(cin >> data)) return 0;

                cout << "Posicion: " << list.findData(data) << endl;
                break;

            case 10:
                cout << "Posicion: ";
                if (!(cin >> index)) return 0;

                data = list[index];
                cout << "Dato: " << data << endl;
                break;

            case 11:
                cout << "Posicion: ";
                if (!(cin >> index)) return 0;

                cout << "Dato nuevo: ";
                if (!(cin >> data)) return 0;

                list[index] = data;
                break;

            case 12: {
                DoublyLinkedList<int> copy;
                copy = list;

                cout << "Copia de la lista: ";
                copy.print();
                break;
            }

            case 13:
                list.clear();
                break;

            case 14:
                list.sort();
                break;

            case 15:
                list.duplicate();
                break;

            case 16:
                list.removeDuplicates();
                break;

            case 0:
                cout << "Programa terminado" << endl;
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

    return 0;
}