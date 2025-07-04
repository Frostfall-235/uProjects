/*
    Dado la siguiente matriz N, con las notas de 3 alumnos, se desea preguntar 
    si el alumno entregó trabajo para subir su promedio, caso contrario queda 
    igual. Al final debe imprimir la matriz con el promedio de cada alumno.

    N[3][4] = {{12, 6, 14, 5}, {7, 0, 11, 10}, {18, 19, 3, 8}}
*/
#include<iostream>
#include<string>
using namespace std;

int main() {

    int N[3][4] = {
        {12, 6, 14, 5}, 
        {7, 0, 11, 10}, 
        {18, 19, 3, 8}
    }, i=0, j;
    float promedio;
    string respuesta;

    cout << "La matriz de notas es: " << endl;
    while(i < 3) {
        j=0;

        while(j < 4) {
            cout << N[i][j] << "\t";

            j++;
        }

        cout << endl;
        i++;
    }

    i=0;

    while(i < 3) {
        j=0;
        promedio=0;

        cout << "El alumno " << i+1 << " entregó su trabajo? (si/no)" << endl;
        cin >> respuesta;

        while(j < 4) {

            promedio += N[i][j];

            j++;
        }

        promedio /= 4;

        if(respuesta.compare("si") == 0) {
            promedio += 2;
        }

        cout << "El promedio del estudiante " << i+1 << " es igual a " << promedio << endl;

        i++;
    }

    cout << endl;
    system("pause");

    return 0;
}