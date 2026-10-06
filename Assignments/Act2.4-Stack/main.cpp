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

    cout << "Titulo: ";
    getline(cin, pagina.titulo);

    cout << "URL: ";
    getline(cin, pagina.url);

    historial.push(pagina);

    cout << "Pagina agregada al historial" << endl;

    return 0;
}