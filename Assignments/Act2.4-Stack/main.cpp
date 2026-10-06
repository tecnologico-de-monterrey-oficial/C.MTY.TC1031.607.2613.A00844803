// Cesar Cardenas - A00844803
#include <iostream>
#include <string>
#include "Stack.h"
using namespace std;

struct PaginaWeb {
    string titulo;
    string url;
};

int main() {
    Stack<PaginaWeb> historial;
    PaginaWeb pagina;
    int opcion;
 
    do {
        cout << "\n1. Visitar una nueva pagina" << endl;
        cout << "2. Retroceder a la pagina anterior" << endl;
        cout << "3. Ver la pagina actual" << endl;
        cout << "4. Mostrar cuantas paginas hay en el historial" << endl;
        cout << "5. Salir" << endl;
        cout << "Opcion: ";

        if (!(cin >> opcion)) {
            return 0;
        }

        try {
            switch (opcion) {
            case 1:
                cout << "Titulo: ";
                getline(cin >> ws, pagina.titulo);

                cout << "URL: ";
                getline(cin, pagina.url);

                historial.push(pagina);
                cout << "Pagina agregada al historial" << endl;
                break;

            case 2:
                pagina = historial.pop();

                cout << "Pagina cerrada: " << pagina.titulo << endl;
                cout << "URL: " << pagina.url << endl;
                break;

            case 3:
                pagina = historial.top();

                cout << "Pagina actual: " << pagina.titulo << endl;
                cout << "URL: " << pagina.url << endl;
                break;

            case 4:
                cout << "Paginas en el historial: "
                     << historial.getSize() << endl;
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