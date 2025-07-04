/*
    14.	Los premios para jugar un bingo se obtienen a formar letras con la cartilla. 
    Ud es un fanático y siempre que asiste a un casino tiene que formar la letra L, 
    la letra O, la letra M, y el apagón es el cartón lleno. En esta oportunidad anuncian 
    que se debe formar la letra N, es decir dada la matriz cuadrada debe formar un 
    vector con la letra N, tal como se muestra en la salida. (sumar los elementos del 
    vector resultante y encontrar el mayor de dicho vector).
    La matriz ingresada:
    12	13	14	15
    27	36	48	63
    82	94	74	91
    61	24	45	66 
    Vector de la letra N
    12	15	27	36	63	82	74	91	61	66
*/
#include<iostream>
using namespace std;

int main() {

    int Bingo[4][4] = {
        {12, 13, 14, 15},
        {27, 36, 48, 63},
        {82, 94, 74, 91},
        {61, 24, 45, 66}
    }, i=0, j, k=0;
    int N[10], mayor=0, suma=0;

    cout << "La cartilla del Bingo es: " << endl;
    while(i < 4) {
        j=0;

        while(j < 4) {

            /*
                Almacenamos en el vector y
                buscamos el mayor de los
                elementos encontrados.
            */
            if(j == 0 || i == j || j == 3) {
                N[k] = Bingo[i][j];
                suma += N[k];

                if(N[k] > mayor) {
                    mayor = N[k];
                }
                
                k++;
            }

            cout << Bingo[i][j] << "\t";
            
            j++;
        }

        cout << endl;
        i++;
    }

    k=0;
    cout << "El vector de la letra N es: " << endl;
    while(k < 10) {
        cout << N[k] << "\t";

        k++;
    }
    
    cout << "\nLa suma de sus elementos es: " << suma;
    cout << "\nEl mayor de sus elementos es: " << mayor;

    return 0;
}