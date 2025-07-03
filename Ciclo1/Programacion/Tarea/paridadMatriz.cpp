/*
    5.	Dado la siguiente matriz, determine cuántos de ellos son pares 
    y cuántos son  impares. A[3][3]={{11,20,35}, {10,17,3},{18,48,43}};
*/
#include<iostream>
using namespace std;

int main() {

    int A[3][3] = {
        {11, 20, 35},
        {10, 17, 3},
        {18, 48, 43}
    }, i=0, j;
    int pares=0, impares=0; // Contadores

    cout << "La matriz 3x3 es:" << endl;
    while(i < 3) {
        j=0;

        while(j < 3) {
            // Contadores
            if (A[i][j] % 2 == 0) {
                pares++;
            } else {
                impares++;
            }

            cout << A[i][j] << "\t"; // Imprimimos

            j++;
        }
        cout << endl;
        i++;
    }

    cout << "La cantidad de elementos pares es: " << pares << endl;
    cout << "La cantidad de elementos impares es: " << impares;

    return 0;
}