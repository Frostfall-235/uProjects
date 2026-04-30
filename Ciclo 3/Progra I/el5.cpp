/**
 * Sumar números ignorando los negativos (continue)
 */
#include<iostream>
using namespace std;

int main() {

    int n, suma=0;

    cout << "Contador de números ignorando negativos" << endl;

    do {
        cout << "Ingresa un numero (0 para salir): "; cin >> n;
        if (n < 0) continue;
        else if (n == 0) cout << "Suma final: " << suma << endl;
        else {
            suma += n;
            cout << "Entrada: " << n << " | Suma acumulada: " << suma << endl;
        }
    } while(n != 0);

    system("pause");
    return 0;
}