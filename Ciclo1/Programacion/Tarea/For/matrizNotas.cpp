/*
    12.	Elabore un algoritmo que almacene las notas numéricas enteras de un 
    grupo de 5 estudiantes con 4 notas cada uno, el programa debe averiguar 
    el promedio de cada estudiante según sus notas, y el promedio final de 
    todos los estudiantes.
*/
#include<iostream>
using namespace std;

int main() {

    int notas[5][4], nota;
    float promedioEstudiante, promedioGeneral=0;

    // Pedimos y almacenamos
    for (int i=0; i < 5; i++) {
        promedioEstudiante=0;

        for (int j=0; j < 4; j++) {
            cout << "Ingresa la nota " << j+1 << " del estudiante " << i+1 << endl;
            cin >> nota;

            notas[i][j] = nota;
            promedioEstudiante += nota;
        }

        promedioGeneral += promedioEstudiante/4;
        cout << "El promedio del estudiante " << i+1 << " es: " << promedioEstudiante/4 << endl;
    }

    cout << "\nEl promedio general de los estudiantes es: " << promedioGeneral/5 << endl;

    // Imprimimos
    cout << "El arreglo de notas es:" << endl;
    for (int i=0; i < 5; i++) {
        for (int j=0; j < 4; j++) {
            cout << notas[i][j] << "\t";
        }

        cout << endl;
    }

    cout << endl;
    system("pause");

    return 0;
}