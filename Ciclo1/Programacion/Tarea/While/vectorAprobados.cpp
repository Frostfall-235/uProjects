/*
    16.	Dado la siguiente matriz N, almacene en un vector APROBADOS 
    los alumnos aprobados y en un vector DESAPROBADO los alumnos 
    desaprobado, sabiendo que la nota aprobatoria es mayor igual que 10.5.
    N[3][3] = {{12, 6, 20}, {3, 17, 1}, {10, 8, 19}}
*/
#include<iostream>
using namespace std;

int main() {

    int N[3][3] = {
        {12, 6, 20},
        {3, 17, 1},
        {10, 8, 19}
    }, i=0, j;
    int APROBADOS[9], DESAPROBADOS[9], m=0, n=0;

    cout << "La matriz de notas es:" << endl;
    while(i < 3) {
        j=0;

        while(j < 3) {
            cout << N[i][j] << "\t";

            if(N[i][j] >= 10.5) {
                APROBADOS[m] = N[i][j];
                
                m++;
            } else {
                DESAPROBADOS[n] = N[i][j];

                n++;
            }

            j++;
        }

        cout << endl;
        i++;
    }

    i=0;
    cout << "Las notas aprobatorias son:" << endl;
    while(i < m) {
        cout << APROBADOS[i] << "\t";

        i++;
    }

    i=0;
    cout << "\nLas notas desaprobatorias son:" << endl;
    while(i < n) {
        cout << DESAPROBADOS[i] << "\t";

        i++;
    }

    cout << endl;
    system("pause");
    
    return 0;
}