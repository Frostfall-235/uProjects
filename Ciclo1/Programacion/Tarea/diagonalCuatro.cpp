/*
    6.	Dada una matriz cuadrada de 4x4, prepare un algoritmo que llena 
    de 0 dicha matriz excepto la diagonal principal donde debe asignar 1.
*/
#include<iostream>
using namespace std;

int main() {

    int A[4][4], i=0, j;

    cout << "La matriz 4x4 es:" << endl;
    while(i < 4) {
        j=0;

        while(j < 4) {
            // Diagonal principal
            if (i == j) {
                A[i][j] = 1;
            } else {
                A[i][j] = 0;
            }

            cout << A[i][j] << "\t"; // Imprimimos

            j++;
        }
        cout << endl;
        i++;
    }

    return 0;
}