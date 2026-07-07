#include "utilidades.h"

#include <cctype>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <limits>

using namespace std;

void limpiarPantalla() {
    system("cls");
}

void pausar() {
    cout << endl;
    cout << "Presione ENTER para continuar...";
    cin.get();
}

void mostrarTitulo(const char titulo[]) {
    cout << "\033[36m";
    cout << "========================================" << endl;
    cout << " " << titulo << endl;
    cout << "========================================" << endl;
    cout << "\033[0m" << endl;
}

void mostrarMensaje(const char mensaje[]) {
    cout << "\033[32m" << mensaje << "\033[0m" << endl;
}

void mostrarError(const char mensaje[]) {
    cout << "\033[31m" << mensaje << "\033[0m" << endl;
}

int leerOpcion(const char mensaje[]) {
    return leerEntero(mensaje);
}

int leerEntero(const char mensaje[]) {
    int opcion;

    cout << mensaje;
    cin >> opcion;

    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        mostrarError("Debe ingresar un numero.");
        cout << mensaje;
        cin >> opcion;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return opcion;
}

int leerEnteroMinimo(const char mensaje[], int minimo) {
    int numero;

    do {
        numero = leerEntero(mensaje);
        if (numero < minimo) {
            mostrarError("El numero ingresado esta fuera del rango permitido.");
        }
    } while (numero < minimo);

    return numero;
}

int leerEnteroRango(const char mensaje[], int minimo, int maximo) {
    int numero;

    do {
        numero = leerEntero(mensaje);
        if (numero < minimo || numero > maximo) {
            mostrarError("El numero ingresado esta fuera del rango permitido.");
        }
    } while (numero < minimo || numero > maximo);

    return numero;
}

char leerCaracter(const char mensaje[]) {
    char texto[10];

    do {
        leerTexto(texto, 10, mensaje);
        if (strlen(texto) == 0) {
            mostrarError("Debe ingresar un caracter.");
        }
    } while (strlen(texto) == 0);

    return static_cast<char>(toupper(texto[0]));
}

char leerSexo(const char mensaje[]) {
    char sexo;

    do {
        sexo = leerCaracter(mensaje);
        if (sexo != 'M' && sexo != 'F') {
            mostrarError("Debe ingresar M o F.");
        }
    } while (sexo != 'M' && sexo != 'F');

    return sexo;
}

void leerTexto(char destino[], int tamano, const char mensaje[]) {
    bool entradaValida;

    do {
        entradaValida = true;
        cout << mensaje;
        cin.getline(destino, tamano);

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            mostrarError("El texto ingresado supera el limite permitido.");
            entradaValida = false;
        } else if (destino[0] == '\0') {
            mostrarError("Este campo no puede quedar vacio.");
            entradaValida = false;
        }
    } while (!entradaValida);
}

bool contieneSoloDigitos(const char texto[]) {
    int longitud = static_cast<int>(strlen(texto));

    if (longitud == 0) {
        return false;
    }

    for (int i = 0; i < longitud; i++) {
        if (!isdigit(static_cast<unsigned char>(texto[i]))) {
            return false;
        }
    }

    return true;
}

int convertirDosDigitos(const char texto[], int inicio) {
    return (texto[inicio] - '0') * 10 + (texto[inicio + 1] - '0');
}

int convertirCuatroDigitos(const char texto[], int inicio) {
    return (texto[inicio] - '0') * 1000
        + (texto[inicio + 1] - '0') * 100
        + (texto[inicio + 2] - '0') * 10
        + (texto[inicio + 3] - '0');
}

bool esAnioBisiesto(int anio) {
    return (anio % 400 == 0) || (anio % 4 == 0 && anio % 100 != 0);
}

bool esFechaValida(const char fecha[]) {
    int diasPorMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (strlen(fecha) != 10 || fecha[2] != '/' || fecha[5] != '/') {
        return false;
    }

    if (!isdigit(static_cast<unsigned char>(fecha[0]))
        || !isdigit(static_cast<unsigned char>(fecha[1]))
        || !isdigit(static_cast<unsigned char>(fecha[3]))
        || !isdigit(static_cast<unsigned char>(fecha[4]))
        || !isdigit(static_cast<unsigned char>(fecha[6]))
        || !isdigit(static_cast<unsigned char>(fecha[7]))
        || !isdigit(static_cast<unsigned char>(fecha[8]))
        || !isdigit(static_cast<unsigned char>(fecha[9]))) {
        return false;
    }

    int dia = convertirDosDigitos(fecha, 0);
    int mes = convertirDosDigitos(fecha, 3);
    int anio = convertirCuatroDigitos(fecha, 6);

    if (anio < 1900 || mes < 1 || mes > 12 || dia < 1) {
        return false;
    }

    if (mes == 2 && esAnioBisiesto(anio)) {
        diasPorMes[1] = 29;
    }

    return dia <= diasPorMes[mes - 1];
}

bool esHoraValida(const char hora[]) {
    if (strlen(hora) != 5 || hora[2] != ':') {
        return false;
    }

    if (!isdigit(static_cast<unsigned char>(hora[0]))
        || !isdigit(static_cast<unsigned char>(hora[1]))
        || !isdigit(static_cast<unsigned char>(hora[3]))
        || !isdigit(static_cast<unsigned char>(hora[4]))) {
        return false;
    }

    int horas = convertirDosDigitos(hora, 0);
    int minutos = convertirDosDigitos(hora, 3);

    return horas >= 0 && horas <= 23 && minutos >= 0 && minutos <= 59;
}

void leerTelefono(char destino[], int tamano, const char mensaje[]) {
    bool telefonoValido;

    do {
        leerTexto(destino, tamano, mensaje);
        telefonoValido = contieneSoloDigitos(destino) && strlen(destino) >= 7;

        if (!telefonoValido) {
            mostrarError("El telefono debe tener solo digitos y al menos 7 caracteres.");
        }
    } while (!telefonoValido);
}

void leerFecha(char destino[], int tamano, const char mensaje[]) {
    bool fechaValida;

    do {
        leerTexto(destino, tamano, mensaje);
        fechaValida = esFechaValida(destino);

        if (!fechaValida) {
            mostrarError("La fecha debe tener formato dd/mm/aaaa y ser valida.");
        }
    } while (!fechaValida);
}

void leerHora(char destino[], int tamano, const char mensaje[]) {
    bool horaValida;

    do {
        leerTexto(destino, tamano, mensaje);
        horaValida = esHoraValida(destino);

        if (!horaValida) {
            mostrarError("La hora debe tener formato hh:mm entre 00:00 y 23:59.");
        }
    } while (!horaValida);
}
