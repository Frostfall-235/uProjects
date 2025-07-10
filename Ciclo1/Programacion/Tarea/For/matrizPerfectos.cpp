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
    }, suma;
    int B[9], index=0; // Para el vector de números perfectos

    cout << "La matriz 3x3 es: " << endl;
    for(int i=0; i < 3; i++) {

        for(int j=0; j < 3; j++) {
            suma=0;

            for(int k=1; k < A[i][j]; k++) {
                if(A[i][j] % k == 0) {
                    suma += k;
                }
            }

            if(suma == A[i][j]) {
                B[index] = A[i][j];

                index++;
            }

            cout << A[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "El vector de perfectos es:" << endl;
    for(int i=0; i < index; i++) {
        cout << B[i] << "\t";
    }

    cout << endl;
    system("pause");

    return 0;
}