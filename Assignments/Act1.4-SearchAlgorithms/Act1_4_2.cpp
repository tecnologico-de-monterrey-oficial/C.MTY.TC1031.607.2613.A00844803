// Cesar Cardenas - A00844803

#include <iostream>
#include <string>

using namespace std;

void resolverSecuencial(const string& s) {
    int comparaciones = 0;
    int n = s.length();

    for (int i = 0; i < n; i += 2) {
        if (i == n - 1) {
            cout << s[i] << " " << comparaciones << " ";
            return;
        }

        comparaciones++;

        if (s[i] != s[i + 1]) {
            cout << s[i] << " " << comparaciones << " ";
            return;
        }
    }
}

void resolverBinaria(const string& s) {
    int comparaciones = 0;
    int inicio = 0;
    int fin = (s.length() - 1) / 2;

    while (inicio <= fin) {
        int medio = (inicio + fin) / 2;
        int posicion = medio * 2;

        if (posicion == s.length() - 1) {
            cout << s[posicion] << " " << comparaciones << endl;
            return;
        }

        comparaciones++;

        if (s[posicion] == s[posicion + 1]) {
            inicio = medio + 1;
        }
        else {
            cout << s[posicion] << " " << comparaciones << endl;
            return;
        }
    }

    cout << s[s.length() - 1] << " " << comparaciones << endl;
}

int main() {
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;

        cin >> s;

        resolverSecuencial(s);
        resolverBinaria(s);
    }

    return 0;
}