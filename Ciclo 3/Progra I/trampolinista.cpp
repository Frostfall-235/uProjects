#include<iostream>
using namespace std;

int main() {
    double d, p, g;

    cout << "Ingrese distancia entre trampolines: "; cin >> d;
    cout << "Ingrese altura de primer salto: "; cin >> p;
    cout << "Ingrese ganancia entre salto salto: "; cin >> g;

    int nsalto=1;
    double h=p;

    cout << "nro salto     |     altura" << endl;
    while(h < d) {
        h = h*(1 + g);
        nsalto++;
        cout << "       " << nsalto << " |      " << h << endl;
    }

    system("pause");
    return 0;
}