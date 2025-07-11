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
    }, k=0;
    int N[10], mayor=0, suma=0;

    cout << "La cartilla del Bingo es: " << endl;
    for (int i=0; i < 4; i++) {

        for (int j=0; j < 4; j++) {

            /**
             * Para encontrar los elementos de la letra
             * N en la cartilla del Bingo, analicemos la
             * posición de dichos elementos:
             * (0,0) (0,3)
             * (1,0) (1,1) (1,3)
             * (2,0) (2,2) (2,3)
             * (3,0) (3,3)
             * 
             * Como vemos, cuando j=0; i==j o j=3
             * 
             * Ahora, para encontrar el mayor solo debemos
             * comparar con un primer elemento, como al inicio
             * 'mayor' es 0, entonces el primer elemento siempre,
             * lo que quiero es que con los que sigan, compare
             * y si son mayores entonces se actualice el numero
             * mayor, así hasta el último elemento, y el valor final
             * de 'mayor' será el elemento más grande comparado.
             */
            if(j == 0 || i == j || j == 3) {
                N[k] = Bingo[i][j]; // Almacenamos cada elemento de la letra N
                suma += N[k]; // Sumamos cada elemento de la letra N

                if(N[k] > mayor) {
                    mayor = N[k];
                }
                
                k++; // Cambiamos de posición en el vector para almacenar más valores de la letra N
            }

            cout << Bingo[i][j] << "\t";
        }

        cout << endl;
    }

    cout << "El vector de la letra N es: " << endl;
    for (k=0; k < 10; k++) {
        cout << N[k] << "\t";
    }
    
    cout << "\nLa suma de sus elementos es: " << suma;
    cout << "\nEl mayor de sus elementos es: " << mayor;

    cout << endl;
    system("pause");

    return 0;
}