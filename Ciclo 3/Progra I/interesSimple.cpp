/** 
 * Un inversionista quiere obtener 100% o más
 * de una inversión inicial. ¿Al cabo de cuántos
 * años lo logra y cuánto es su capital futuro?
 * Si le ofrecen una tasa anual de 7%.
 */

#include<iostream>
using namespace std;

int main() {

    double monto;
    int tiempo=1; // En años

    cout << "Ingresa el monto: "; cin >> monto;

    while(monto < monto * 2) {
        monto = monto * 1.07;
        tiempo++;
    }

    cout << "Monto doblado en " << tiempo << "años" << endl;
    cout << "Monto futuro: " << monto << endl;


    system("pause");
    return 0;
}