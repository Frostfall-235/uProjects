/*
    1.	Dado dos vectores A, B de 5 elementos enteros cada uno, y un vector
    C que contenga la suma de ambos vectores. Imprimir vector A, B, y C.
*/
#include<iostream>
using namespace std;

int main() {

    int A[5], B[5], C[5];
    int i=0;

    // Preguntamos por los elementos de los vectores
    while (i < 5) {
        cout << "Ingresa el elemento " << i+1 << " para el vector A: ";
        cin >> A[i];

        i++;
    }
    
    i=0;
    while (i < 5) {
        cout << "Ingresa el elemento " << i+1 << " para el vector B: ";
        cin >> B[i];

        i++;
    }

    i=0;
    // Imprimimos los vectores y el vector de la suma
    cout << "El vector A es:" << endl;
    while (i < 5) {
        cout << A[i] << "\t";
        
        i++;
    }

    i=0;
    cout << "\nEl vector B es:" << endl;
    while (i < 5) {
        cout << B[i] << "\t";
        
        i++;
    }

    i=0;
    cout << "\nEl vector C de la suma es:" << endl;
    while (i < 5) {
        C[i] = A[i] + B[i];
        cout << C[i] << "\t";

        i++;
    }

    return 0;
}