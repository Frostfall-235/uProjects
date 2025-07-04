/*
    3.	Elabore un programa que cargue un array de enteros con los números del 1 al 10.
*/
#include<iostream>
using namespace std;

int main() {

    int A[10], i=0;

    cout << "El arreglo unidimensional es:" << endl;
    while(i < 10) {
        A[i] = i+1;
        cout << A[i] << "\t";

        i++;
    }

    cout << endl;
    system("pause");   
    
    return 0;
}