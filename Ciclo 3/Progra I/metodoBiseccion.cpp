#include<iostream>
#include<cmath>
using namespace std;

double funcion(double x) {
    return pow((x+1), 3); // (x+1)^3
}

int main() {

    double a, b, c;
    double error = 0.000001; // Garantizamos una solución más precisa
    cout << "Se requieren los extremos del intervalo [a, b]" << endl;
    cout << "Ingrese el valor de a: "; cin >> a;
    cout << "Ingrese el valor de b: "; cin >> b;

    if(funcion(a) * funcion(b) >= 0) {

        /**
         * Si no hay cambio de signo, el teorema del valor
         * intermedio falla, entonces no es posible su
         * aplicación para el intervalo ingresado.
        */
        cout << funcion(a) << " " << funcion(b) << endl;
        cout << "No hay raices en el intervalo [" << a << ", " << b << "]" << endl;
        system("pause");
        return 1;
    }

    int i=0;

    while((b-a) > error) {
        c = (a + b) / 2;

        if (funcion(c) == 0.0) break; // Raíz encontrada
        else if (funcion(a) * funcion(c) < 0) b = c; // Solución en [a, c]
        else a = c; // Solución en [c, b]

        i++;
    }

    cout << "Raiz aproximada: " << (a + b) / 2 << endl;
    cout << "Iteraciones: " << i << endl;

    system("pause");
    return 0;
}