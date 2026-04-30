/**
 * Hallar el factorial usando do-while
 */
#include<iostream>
using namespace std;

int main() {

    int factorial=1;
    int n, i;

    cout << "Ingresa un numero entero positivo: "; cin >> n;
    
    if (n <= 0) {
    	cout << "Debes ingresar un numero mayor que 0.";
    	return 1;
	}
	
	i = n; // Iniciamos el contador
    do {
        factorial *= i;
        i--;
    } while (i > 0);

    cout << "El factorial de " << n << " es: " << factorial << endl;

    system("pause");
    return 0;
}