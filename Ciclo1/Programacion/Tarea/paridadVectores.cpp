/*
    9.	Dado la siguiente matriz, almacene en un vector PAR 
    los números pares y en un vector IMPAR los números impares. 
    Luego imprima la matriz y los vectores. 
    A[3][3]={{12,6,20}, {15,13,1},{100,15,28}}
*/
#include<iostream>
using namespace std;

int main() {

    int A[3][3] = {
        {12, 6, 20},
        {15, 13, 1},
        {100, 15, 28}
    }, i=0, j;
    int PAR[9], IMPAR[9], m=0, n=0;

    cout << "La matriz 3x3 es:" << endl;
    while(i < 3) {
        j=0;

        while(j < 3) {
            if(A[i][j] % 2 == 0) {
                PAR[m] = A[i][j];

                m++;
            } else {
                IMPAR[n] = A[i][j];

                n++;
            }

            cout << A[i][j] << "\t";

            j++;
        }

        cout << endl;
        i++;
    }

    i=0;
    cout << "El vector de numeros pares es: " << endl;
    while(i < m) {
        cout << PAR[i] << "\t";

        i++;
    }

    i=0;
    cout << "\nEl vector de numeros impares es: " << endl;
    while(i < n) {
        cout << IMPAR[i] << "\t";

        i++;
    }

    return 0;
}