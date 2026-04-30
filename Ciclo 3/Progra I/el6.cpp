/**
 * Determinar si el número es primo usando divisor decreciente
 */
#include<iostream>
using namespace std;

int main() {

    int n, i;
    bool esPrimo = true;
    cout << "Ingresa un numero entero positivo: "; cin >> n;

    if (n <= 0) {
    	cout << "El numero debe ser mayor que 0." << endl;
        return 1;
	} 	

    n == 1 ? // ¿El número es igual a 1?
		(i = n) : // Si lo es, 1/1 es exacto. n % i = 0
			(i = n - 1); // Si no lo es, iniciamos el contador.
    do {
        if (n % i == 0) {
            cout << n << " no es primo." << endl;
            esPrimo = false;
            break;
        }

        i--;
    } while (i > 1);

    if (esPrimo) cout << n << " es primo." << endl;

    system("pause");
    return 0;
}