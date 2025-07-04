/*
    11.	Se tiene la siguiente matriz V, con diferentes niveles de temperatura 
    de una erupción volcánica, se desea verificar si la temperatura es menor 
    igual a 16° se guardara este datos en un vector llamado T_Normal, caso 
    contrario se guardara en un vector llamado T_Elevado. Al final se desea 
    imprimir cada uno de los vectores y la matriz.
    V[3][3]={{12,21,45}, {11,16,4},{18,41,43}}; 
*/
#include<iostream>
using namespace std;

int main() {

    int V[3][3] = {
        {12, 21, 46},
        {11, 16, 4},
        {18,41, 43}
    }, i=0, j;
    int T_Normal[9], T_Elevado[9], m=0, n=0;
    
    cout << "Las temperaturas registradas son:" << endl;
    while(i < 3) {
        j=0;

        while(j < 3) {
            if (V[i][j] <= 16) {
                T_Normal[m] = V[i][j];

                m++;
            } else {
                T_Elevado[n] = V[i][j];

                n++;
            }

            cout << V[i][j] << "\t";

            j++;
        }

        cout << endl;
        i++;
    }

    i=0;
    cout << "Temperaturas normales registradas:" << endl;
    while(i < m) {
        cout << T_Normal[i] << "\t";

        i++;
    }
    
    i=0;
    cout << "\nTemperaturas elevadas registradas:" << endl;
    while(i < n) {
        cout << T_Elevado[i] << "\t";

        i++;
    }

    return 0;
}