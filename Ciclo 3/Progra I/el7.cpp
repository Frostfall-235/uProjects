/**
 * Simular el retiro bancario hasta saldo insuficiente
 */
#include<iostream>
using namespace std;

int main() {
    double saldo, retiro;
    cout << "Ingresa el saldo: "; cin >> saldo;

    while (saldo >= 0 ) {
        cout << "Ingresa el retiro: "; cin >> retiro;
        saldo -= retiro;
        if (saldo < 0) cout << "Saldo insuficiente." << endl;
    }

    system("pause");
    return 0;
}