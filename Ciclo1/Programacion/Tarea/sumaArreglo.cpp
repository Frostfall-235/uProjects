/*
    2.	Dado el siguiente arreglo unidimensional obtener la suma de los
    valores de dicho arreglo e imprima el arreglo. X[1,2,...6],
*/

#include<iostream>
using namespace std;

int main() {

    int X[6] = {1, 2, 3, 4, 5, 6}, i=0, suma=0;

    cout << "El arreglo es:" << endl;
    while (i < 6) {
        cout << X[i] << "\t";
        suma += X[i];

        i++;
    }

    cout << "\nLa suma de los elementos es: " << suma;

    cout << endl;
    system("pause");

    return 0;
}