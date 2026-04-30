/**
 * Hallar la suma de los cuadrados de 
 * las cifras de un entero positivo.
 */
#include<iostream>
using namespace std;

int main() {

    int n, suma=0;

    cout << "Ingresa un numero: "; cin >> n;

    if (n < 0) {
        cout << "El numero debe ser igual o mayor a 0." << endl;
        return 1;
    }

    while (n > 0) {
        suma += (n % 10) * (n % 10);
        n /= 10;
    } // Se detiene cuando n = 0.

    cout << suma << endl;

    system("pause");
    return 0;
}