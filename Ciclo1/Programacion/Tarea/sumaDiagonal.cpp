/*
    13.	Dado la siguiente matriz, sume los valores de la 
    diagonal principal de la matriz. Al final muestre la 
    matriz y la suma de la diagonal.
    A[4][4]={{12,13,14,15}, {27,36,48,63},{82,94,74,91}, {61,24,45,66} 
*/
#include<iostream>
using namespace std;

int main() {

    int A[4][4] = {
        {12, 13, 14, 15},
        {27, 36, 48, 63},
        {82, 94, 74, 91},
        {61, 24, 45, 66}
    }, i=0, j, suma=0;

    cout << "La matriz 4x4 es:" << endl;
    while(i < 4) {
        j=0;

        while(j < 4) {
            if(i == j) {
                suma += A[i][j]; // Suma de diagonal
            }

            cout << A[i][j] << "\t"; // Imprimimos

            j++;
        }

        cout << endl;
        i++;
    }

    cout << "La suma de la diagonal es: " << suma;

    return 0;
}