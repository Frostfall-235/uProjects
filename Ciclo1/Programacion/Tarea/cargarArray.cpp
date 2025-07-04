/*
    4.	Preparar un algoritmo que permita cargar un array bidimensional
    con los números del 1 al 15 y luego los imprima en la pantalla.
*/
#include<iostream>
using namespace std;

int main() {

    int A[3][5], i=0, j, n=1;

    cout <<  "El arreglo bidimensional es:" << endl;
    while(i < 3) {
        j=0;
        while(j < 5) {
            A[i][j] = n;
            cout << A[i][j] << "\t";

            n++;
            j++;
        }
        cout << endl;
        i++;
    }

    cout << endl;
    system("pause");

    return 0;
}