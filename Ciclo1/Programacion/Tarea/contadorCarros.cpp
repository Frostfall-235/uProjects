/*
    8.	Una mecánica atiende varios carros y finaliza la atención cuando llega 
    un carro con la placa 99567. Imprima la cantidad de carros que atendio
*/
#include<iostream>
using namespace std;

int main() {

    int carros=1;

    while(carros < 99567) {
        carros++;
    }

    cout << "Se atendieron " << carros << " carros en total.";

    return 0;
}