#include<iostream>
#include<iomanip> // Ajustar el ancho del campo

using namespace std;

int main() {

    cout << "Tabla de multiplicar " << endl;
    cout << "-----------------------------------------------------------------" << endl;
    cout << "    | ";
    for (int i = 1; i <= 10; i++) {
        cout << setw(3) << i << " | ";
    }
    cout << endl;
    cout << "-----------------------------------------------------------------" << endl;

    for (int i = 1; i <= 10; i++) {
        cout << setw(3) << i << " | ";
        for (int j = 1; j <= 10; j++) {
            cout << setw(3) << i * j << " | ";
        }
        cout << endl << "-----------------------------------------------------------------" << endl;
    }

    system("pause");
    return 0;
}