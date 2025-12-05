/*
    Dado la siguiente matriz que representa las 4 notas de 3 alumnos,
    calcule el promedio de notas y pregunta si el alumno entregó su
    trabajo final, si lo hizo, sume dos puntos al promedio, caso
    contrario no le sume nada. Al final imprima el promedio y la matriz
    de notas.
*/
#include<iostream>
using namespace std;

int main() {

    int N[3][4] = {
        {12, 13, 14, 15},
        {16, 0, 0, 19},
        {8, 11, 15, 17}
    }, respuesta;
    float promedioAlumno;

    for (int i=0; i < 3; i++) {
        promedioAlumno=0;

        for (int j=0; j < 4; j++) {
            promedioAlumno += N[i][j];
        }

        cout << "El alumno " << i + 1 << " entrego su trabajo final?" << endl;
        cout << "Escriba 0 y 1 para responder que si o no" << endl;
        cin >> respuesta;

        promedioAlumno /= 4;

        if (respuesta == 0) {
            promedioAlumno += 2;
        } else if (respuesta == 1) {
            cout << "El alumno " << i + 1 << " no entrego su trabajo final" << endl;
        } else {
            cout << "Respuesta invalida. Escriba solo 0 o 1" << endl;
            i--;
            continue;
        }

        cout << "El promedio del alumno " << i + 1 << " es: " << promedioAlumno << endl;
    }

    cout << "La matriz de notas es:" << endl;
    for (int i=0; i < 3; i++) {
        for (int j=0; j < 4; j++) {
            cout << N[i][j] << "\t";
        }
        cout << endl;
    }

    cout << endl;
    system("pause");

    return 0;
}