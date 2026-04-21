#include<iostream>
#include<iomanip>
using namespace std;

int main() {

    double h, p;

    cout << "Ingresa la altura inicial: "; cin >> h;
    cout << "Ingresa la perdida entre cada rebote: "; cin >> p;

    int rebotes=0;
    cout << endl<< setw(3) << "  Rebote |" << setw(12) << "Altura" << endl;
    cout << "--------------------------" << endl;

    while (h >= 0.000001) {
        h = h * (1-p);

        if (h < 0.000001) break;

        rebotes++;

        cout << "   " << setw(3) << rebotes << "   |   " << setw(12) << h << endl;
    }

    cout << "\nTotal de rebotes: " << rebotes << endl;

    system("pause");
    return 0;
}