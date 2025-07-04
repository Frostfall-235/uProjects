/*
    12.	Elabore un algoritmo que almacene las notas numéricas enteras de un 
    grupo de 5 estudiantes con 4 notas cada uno, el programa debe averiguar 
    el promedio de cada estudiante según sus notas, y el promedio final de 
    todos los estudiantes.
*/
#include<iostream>
using namespace std;

int main() {

    int notas[5][4], nota, i=0, j;
    float promedioEstudiante, promedioGeneral=0;

    // Pedimos y almacenamos
    while(i < 5) {
        j=0;
        promedioEstudiante=0;

        while(j < 4) {
            cout << "Ingresa la nota " << j+1 << " del estudiante " << i+1 << endl;
            cin >> nota;

            notas[i][j] = nota;
            promedioEstudiante += nota;

            j++;
        }

        promedioGeneral += promedioEstudiante/4;
        cout << "El promedio del estudiante " << i+1 << " es: " << promedioEstudiante/4 << endl;

        i++;
    }

    cout << "\nEl promedio general de los estudiantes es: " << promedioGeneral/5 << endl;

    // Imprimimos
    i=0, j=0;
    cout << "El arreglo de notas es:" << endl;
    while(i < 5) {
        j=0;

        while(j < 4) {
            cout << notas[i][j] << "\t";

            j++;
        }

        cout << endl;
        i++;
    }


    return 0;
}