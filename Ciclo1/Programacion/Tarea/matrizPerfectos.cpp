/*
    7.	Dado la siguiente matriz. Pase a un vector solo los números perfectos. 6=3+2+1
    A[3][3] = {{12, 6, 20}, {15, 13, 1}, {100, 15, 28}}
*/
#include<iostream>
using namespace std;

int main() {

    int A[3][3] = {
        {12, 6, 20}, 
        {15, 13, 1}, 
        {100, 15, 28}
    }, i=0, j, k, suma;
    int B[9], index=0; // Números perfectos

    cout << "La matriz 3x3 es: " << endl;
    while(i < 3) {
        j=0;

        while(j < 3) {
            suma=0;
            k=1;

            while(k < A[i][j]) {
                if(A[i][j] % k == 0) {
                    suma += k;
                }
                k++;
            }

            if(suma == A[i][j]) {
                B[index] = A[i][j];

                index++;
            }

            cout << A[i][j] << "\t";

            j++;
        }

        cout << endl;
        i++;
    }

    i=0;
    cout << "El vector de perfectos es:" << endl;
    while(i < index) {
        cout << B[i] << "\t";

        i++;
    }

    return 0;
}