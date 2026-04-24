#include<iostream>
#include<cmath>
using namespace std;

double funcion(double x) {
    return pow((x+1), 3);
}

int main() {
    double x0, x1, x2;
    double error = 0.000001;

    cout << "Ingrese x0: "; cin >> x0;
    cout << "Ingrese x1: "; cin >> x1;

    int i = 0;

    do {
        x2 = x1 - (funcion(x1)*(x1 - x0)) / (funcion(x1) - funcion(x0));
        x0 = x1;
        x1 = x2;
        i++;
    } while(abs(funcion(x2)) > error);
    /*
        Mientras f(x2) se acerque a 0, la 
        raíz aproximada es aún más precisa
    */

    cout << "Raiz aproximada: " << x2 << endl;
    cout << "Iteraciones: " << i << endl;

    system("pause");
    return 0;
}