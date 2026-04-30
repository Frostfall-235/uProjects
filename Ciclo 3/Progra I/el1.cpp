/**
 * Convertir a base 2, base 4 y base 8 a un número positivo de base 10.
 */
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string convertirBase(int n, int base) {
    
    if  (n == 0) return 0;
    
    string res = "";

    while (n > 0) {
        res = to_string(n % base);
        n /= base;
    }

    reverse(res.begin(), res.end());
    return res;
}

int main() {

    int numero;

    cout << "Ingresa un numero para convertirlo a otra base: "; cin >> numero;

    cout << "Base 2: " << convertirBase(numero, 2) << endl;
    cout << "Base 4: " << convertirBase(numero, 4) << endl;
    cout << "Base 8: " << convertirBase(numero, 8) << endl;

    // Tdv me falta XD

    system("pause");
    return 0;
}












