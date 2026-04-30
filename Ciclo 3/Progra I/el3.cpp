/**
 * Contar cuántos impares se ingresan antes de un negativo.
 */
#include<iostream>
using namespace std;

int main() {

    int n, impares=0;

    do {
        cout << "Ingresa un numero entero: "; cin >> n;
        if (n % 2 != 0) impares++;
    } while (n >= 0);

    cout << "Cantidad de impares: " << impares << endl;

    system("pause");
    return 0;
}