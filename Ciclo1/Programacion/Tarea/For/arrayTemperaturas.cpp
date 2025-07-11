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
    };
    int T_Normal[9], T_Elevado[9], m=0, n=0; // Vectores de temperaturas y marcadores de posición
    
    cout << "Las temperaturas registradas son:" << endl;
    for (int i=0; i < 3; i++) {
        for (int j=0; j < 3; j++) {

            if (V[i][j] <= 16) {
                T_Normal[m] = V[i][j]; // Si encontramos una temperatura normal en V, almacenamos en el vector T_Normal

                m++; // Cambiamos de posición a la siguiente en el vector para almacenar más temperaturas
            } else {

                // El mismo análisis que arriba pero para temperaturas elevadas (mayores que 16)
                T_Elevado[n] = V[i][j];

                n++;
            }

            cout << V[i][j] << "\t";
        }

        cout << endl;
    }

    /**
     * Como m y n representan la cantidad de elementos que tengo
     * en los vectores ya que se estuvieron sumando cada que se
     * encontraba una temperatura con su respectivo rango, entonces
     * i y j ahora no excederán tales valores pues solo quiero
     * imprimir solo los elementos que fueron almacenados en cada
     * vector y no todo el vector en sí.
     */
    cout << "Temperaturas normales registradas:" << endl;
    for (int i=0; i < m; i++) {
        cout << T_Normal[i] << "\t";
    }
    
    cout << "\nTemperaturas elevadas registradas:" << endl;
    for (int i=0; i < n; i++) {
        cout << T_Elevado[i] << "\t";
    }

    cout << endl;
    system("pause");

    return 0;
}