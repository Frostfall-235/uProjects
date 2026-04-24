#include<iostream>
#include<cmath>
using namespace std;

double funcion(double x) {
    return pow((x+1), 3);
}

int main() {
    double a, b, dx, suma;
    int n;

    cout << "Ingrese a: "; cin >> a;
    cout << "Ingrese b: "; cin >> b;
    cout << "Ingrese numero de subintervalos: "; cin >> n;

    dx = (b - a) / n;
    suma = funcion(a) + funcion(b);

    for(int i = 1; i < n; i++) {
        suma += 2 * funcion(a + i*dx);
    }

    double integral = (dx/2) * suma;

    cout << "Integral aproximada: " << integral << endl;

    system("pause");
    return 0;
}