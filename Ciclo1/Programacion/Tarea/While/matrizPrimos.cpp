/*
    10.	Dado la siguiente matriz de 4x4, llene la matriz solamente con el número 1, 
    excepto la diagonal principal que debe tener números primos. Al final imprima
    la matriz y la suma de toda la matriz. 
*/
#include<iostream>
using namespace std;

int main() {

    int A[4][4], i=0, j;
    int numero=2, k=2, suma=0;
    bool esPrimo;

    cout << "La matriz 3x3 es: " << endl;
    while(i < 4) {
        j=0;

        while(j < 4) {
            if (i == j) {
                A[i][j] = 1;
                suma += A[i][j];
                cout << A[i][j] << "\t";

                j++;
            } else {
                k=2;
                esPrimo = true;

                while(k < numero) {
                    if(numero % k == 0) {
                        esPrimo = false;
                    }
                    k++;
                }

                if(esPrimo) {
                    A[i][j] = numero;
                    suma += numero;
                    
                    cout << A[i][j] << "\t";
                    
                    j++;
                } 
                numero++;
            }
        }

        cout << endl;
        i++;
    }

    cout << "La suma de elementos es: " << suma;

    cout << endl;
    system("pause");

    return 0;
}
