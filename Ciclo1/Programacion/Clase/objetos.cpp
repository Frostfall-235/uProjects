#include<iostream>
#include<string>
using namespace std;

/**
 * Programación Orientada a Objetos
 * Nivel básico, cómo construir un
 * vehículo con funciones básicas
 * como encenderse, abrir ventanas
 * o presionar el claxón o detenerse.
 */

class Car {

    public:
        bool estado = 1;
        string model;
        int year;
        float recorrido;

        Car(string x, int y, float z) {
            model = x;
            year = y;
            recorrido = z;
        }

        bool encendido() {
            bool value = 1;

            if(estado == 1) value = 0;
            return value;
        }

        bool ventanas(int numero) {

        }

        string desacelerar() {

        }
};

int main() {



    return 0;
}