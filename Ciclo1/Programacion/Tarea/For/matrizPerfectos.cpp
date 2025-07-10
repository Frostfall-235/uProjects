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

            /**
             * Por definición de números perfectos,
             * son aquellos en los que la suma de sus
             * divisores incluyendo el 1, da el mismo
             * número. Ejemplo: 6 = 3 + 2 + 1
             * 
             * Entonces lo que hace el siguiente bucle
             * será sumar todos los divisores del elemento
             * en la matriz a partir del 1.
             */
            for(int k=1; k < A[i][j]; k++) {
                if(A[i][j] % k == 0) {
                    suma += k; // Si k es divisor, sumamos.
                }
            }

            if(suma == A[i][j]) {
                B[index] = A[i][j]; // Si es número perfecto, guardamos

                index++; // Cambiamos de posición en el vector para almacenar más números perfectos
            }

            cout << A[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "El vector de perfectos es:" << endl;
    for(int i=0; i < index; i++) {
        cout << B[i] << "\t"; // Se usa index como guia para imprimir solo la cantidad de elementos guardados y no todo el vector
    }

    cout << endl;
    system("pause");

    return 0;
}