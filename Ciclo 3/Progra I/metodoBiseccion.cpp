#include<iostream>
#include<cmath>
using namespace std;

double funcion(double x) {
    return pow(x, 2) + 2*x + 1; // x^2 + 2x + 1
}

int main() {

    // Usar el teorema de Valor Intermedio
    double a, b, c;
    double error = 0.000001; // Garantizamos la raíz más exacto posible
    cout << "Se requieren los extremos del intervalo [a, b]" << endl;
    cout << "Ingrese el valor de a: "; cin >> a;
    cout << "Ingrese el valor de b: "; cin >> b;

    if(funcion(a) * funcion(b) >= 0) {
        cout << "No hay raíces en el intervalo [" << a << ", " << b << "]" << endl;
        return 1;
    }

    int i=0;

    while((b-a) > error) {
        c = (a + b) / 2;

        if(funcion(c) == 0.0) {
            break; // La raíz es exacta
        } else if(funcion(a) * funcion(c) < 0) {
            b = c;
        } else {
            a = c;
        }

        i++;
    }

    cout << "Raíz aproximada: " << (a + b) / 2 << endl;
    cout << "Iteraciones: " << i << endl;

    system("pause");
    return 0;
}