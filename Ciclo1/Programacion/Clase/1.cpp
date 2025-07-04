/*
    Dado la siguiente matriz, ingrese un numero por el teclado, luego busque 
    dicho número en la matriz dada, y al final imprima la matriz y la ubicación 
    de número ingresado. También imprima la suma total de la matriz.

    A[3][3] = {{12, 6, 20}, {15, 13, 1}, {100, 15, 28}}
*/
#include<iostream>
using namespace std;

int main() {

    int A[3][3] = {
        {12, 6, 20}, 
        {15, 13, 1}, 
        {100, 15, 28}
    }, i=0, j;
    int numero;
    bool found = false;

    cout << "La matriz 3x3 es:" << endl;
    while(i < 3) {
        j=0;

        while(j < 3) {
            cout << A[i][j] << "\t";

            j++;
        }
    
        cout << endl;
        i++;
    }  

    i=0;

    cout << "Ingrese un numero para buscarlo en la matriz: ";
    cin >> numero;

    while(i < 3) {
        j=0;

        while(j < 3) {
            if (A[i][j] == numero) {
                cout << "Numero encontrado en la posicion (" << i << ", " << j << ")" << endl;; 
                found = true;
            }

            j++;
        }

        i++;
    }

    if(!found) {
        cout << "Numero no encontrado en la matriz";
    }

    cout << endl;
    system("pause");

    return 0;
}