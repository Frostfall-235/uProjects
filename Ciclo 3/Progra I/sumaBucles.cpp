// S = 1 - 1/2 + 1/3 - 1/4 ... n
#include<iostream>
using namespace std;

int main() {

    double suma=0;
    int n, i;
    cout << "Ingresa el valor de n: "; cin >> n;

    for (i=1; i <= n; i++) {
        if (i % 2 == 0) {
            suma -= 1.0 / i;
        } else {
            suma += 1.0 / i;
        }
    }

    cout << "FOR | El valor de la suma es: " << suma << endl;

    suma=0;
    i=1;

    while(i <= n) {
        if (i % 2 == 0) {
            suma -= 1.0 / i;
        } else {
            suma += 1.0 / i;
        }
        i++;
    }
    
    cout << "WHILE | El valor de la suma es: " << suma << endl;

    suma=0;
    i=1;

    do {
        if (i % 2 == 0) {
            suma -= 1.0 / i;
        } else {
            suma += 1.0 / i;
        }
        i++;
    } while (i <= n);

    cout << "DO WHILE | El valor de la suma es: " << suma << endl;

    system("pause");
    return 0;
}