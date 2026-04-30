/**
 * Validar la opción de Menú
 */
#include<iostream>
using namespace std;

int main() {
    int opcion;

    cout << "Menu | Ejercicios 1-4" << endl;

    do {
        cout << "---------------------------------------------------------------" << endl;
        cout << "1. Convertir un entero positivo en decimal a base 2, 4 y 8" << endl;
        cout << "2. Hallar suma de cuadrados de las cifras de un entero positivo" << endl;
        cout << "3. Contar cuántos impares se ingresan antes de un negativo" << endl;
        cout << "4. Hallar el factorial de un numero usando do-while" << endl;
        cout << "5. Salir" << endl;
        cout << "---------------------------------------------------------------" << endl;

        cout << "Ingrese una opcion: "; cin >> opcion;

        switch (opcion) {

            case 1: {
                // Lit me falta el ejercicio 1
            }

            case 2: {
                int n, suma=0;
                cout << "Ingresa un numero entero positivo: "; cin >> n;

                if (n < 0) {
                    cout << "El numero debe ser igual o mayor a 0." << endl;
                    break;
                }

                while (n > 0) {
                    suma += (n % 10) * (n % 10);
                    n /= 10;
                } // Se detiene cuando n = 0.

                cout << suma << endl;
                break;
            }

            case 3: {
                int n, impares=0;

                do {
                    cout << "Ingresa un numero entero: "; cin >> n;
                    if (n % 2 != 0) impares++;
                } while (n >= 0);

                cout << "Cantidad de impares: " << impares << endl;
                break;
            }

            case 4: {
                int factorial=1;
                int n, i;

                cout << "Ingresa un numero: "; cin >> i;
                n = i;

                do {
                    factorial *= i;
                    i--;
                } while (i > 0);

                cout << "El factorial de " << n << " es: " << factorial << endl;
                break;
            }

            default: {
                cout << "Opcion invalida. Intente de nuevo." << endl;
                break;
            }
        }

    } while (opcion != 5);

    system("pause");
    return 0;
}