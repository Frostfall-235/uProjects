/*
    15.	Diseñe un programa que lea dos vectores A y B de 20 
    elementos cada uno y multiplique el primer elemento de A 
    con el último elemento de B y luego el segundo elemento 
    de A por el diecinueveavo elemento de B y así sucesivamente 
    hasta llegar al veinteavo elemento de A por el primer 
    elemento de B. El resultado de la multiplicación 
    en un vector C
*/
#include<iostream>
using namespace std;

int main() {

    int A[20], B[20], C[20], i=0;

    while(i < 20) {
        cout << "Ingrese el elemento " << i+1 << " para el vector A: ";
        cin >> A[i];

        i++;
    }

    i=0;
    cout << endl;
    while(i < 20) {
        cout << "Ingrese el elemento " << i+1 << " para el vector B: ";
        cin >> B[i];

        i++;
    }

    i=0;
    cout << "Los vectores A, B y C son:" << endl << "A: ";
    while(i < 20) {
        C[i] = A[i] * B[19-i]; // Establecemos para el vector C

        cout << A[i] << "  "; // Imprimimos el vector A

        i++;
    }

    i=0;
    cout << "\nB: ";
    while (i < 20) {
        cout << B[i] << " "; // Imprimimos el vector B

        i++;
    }

    i=0;
    cout << "\nC: ";
    while (i < 20) {
        cout << C[i] << " "; // Imprimimos el vector C

        i++;
    }

    cout << endl;
    system("pause");

    return 0;
}