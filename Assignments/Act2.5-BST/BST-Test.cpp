// Cesar Cardenas - A00844803
#include <iostream>
#include <limits>
using namespace std;

#include "BST.h"

int main() {
    BST<int> bst;
    int option;
    int value;

    while (true) {
        cout << "\n Selecciona una opcion del BST: " << endl;
        cout << "1. Insertar valor" << endl;
        cout << "2. Mostrar recorrido" << endl;
        cout << "3. Buscar valor" << endl;
        cout << "4. Mostrar altura" << endl;
        cout << "5. Mostrar ancestros" << endl;
        cout << "6. Consultar nivel de un nodo" << endl;
        cout << "0. Salir" << endl;
        cout << "Elige una opcion: ";

        if (!(cin >> option)) {
            cout << "Entrada invalida." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (option == 0) {
            cout << "Programa finalizado" << endl;
            break;
        }

        switch (option) {
            case 1:
                cout << "Valor a insertar: ";
                if (cin >> value) {
                    bst.insert(value);
                    cout << "Valor insertado." << endl;
                } else {
                    cout << "Entrada invalida." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                break;

            case 2: {
                int traversal;

                cout << "\n1. Preorder" << endl;
                cout << "2. Inorder" << endl;
                cout << "3. Postorder" << endl;
                cout << "4. Por niveles" << endl;
                cout << "Elige un recorrido: ";

                if (cin >> traversal) {
                    bst.visit(traversal);
                } else {
                    cout << "Entrada invalida." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                break;
            }

            case 3:
                cout << "Valor a buscar: ";
                if (cin >> value) {
                    if (bst.find(value)) {
                        cout << "El valor si esta en el arbol." << endl;
                    } else {
                        cout << "El valor no esta en el arbol." << endl;
                    }
                } else {
                    cout << "Entrada invalida." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                break;

            case 4:
                cout << "Altura del arbol: " << bst.height() << endl;
                break;

            case 5:
                cout << "Valor para consultar sus ancestros: ";
                if (cin >> value) {
                    bst.ancestors(value);
                } else {
                    cout << "Entrada invalida." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                break;

            case 6:
                cout << "Valor para consultar su nivel: ";
                if (cin >> value) {
                    int level = bst.whatLevelAmI(value);

                    if (level == -1) {
                        cout << "El valor no esta en el arbol." << endl;
                    } else {
                        cout << "Nivel del nodo: " << level << endl;
                    }
                } else {
                    cout << "Entrada invalida." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                break;

            default:
                cout << "Opcion invalida." << endl;
        }
    }

    return 0;
}