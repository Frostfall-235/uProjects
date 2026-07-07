#include "pacientes.h"

#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>

#include "../archivos.h"
#include "../utilidades.h"

using namespace std;

void imprimirEncabezadoPacientes() {
    cout << left;
    cout << setw(8) << "ID";
    cout << setw(25) << "Nombre";
    cout << setw(8) << "Edad";
    cout << setw(8) << "Sexo";
    cout << setw(16) << "Telefono";
    cout << setw(12) << "Estado" << endl;
    cout << "----------------------------------------------------------------------------" << endl;
}

void leerDatosPaciente(Paciente &paciente, bool leerId) {
    if (leerId) {
        paciente.idPaciente = leerEnteroMinimo("ID del paciente: ", 1);
    }

    leerTexto(paciente.nombre, 60, "Nombre: ");
    paciente.edad = leerEnteroRango("Edad: ", 0, 120);
    paciente.sexo = leerSexo("Sexo (M/F): ");
    leerTelefono(paciente.telefono, 15, "Telefono: ");
    leerTexto(paciente.direccion, 80, "Direccion: ");
}

const char *textoEstadoPaciente(char estado) {
    if (estado == 'A') {
        return "Activo";
    }

    if (estado == 'D') {
        return "Eliminado";
    }

    return "Desconocido";
}

void registrarPaciente() {
    Paciente paciente;

    limpiarPantalla();
    mostrarTitulo("Registrar Paciente");
    leerDatosPaciente(paciente, true);

    if (buscarPosicionPacientePorId(paciente.idPaciente) != -1) {
        mostrarError("Ya existe un paciente con ese ID.");
        pausar();
        return;
    }

    paciente.estado = 'A';

    fstream archivo(RUTA_PACIENTES, ios::out | ios::app | ios::binary);

    if (!archivo) {
        mostrarError("No se pudo abrir el archivo de pacientes.");
        pausar();
        return;
    }

    archivo.write(reinterpret_cast<char *>(&paciente), sizeof(Paciente));
    archivo.close();

    mostrarMensaje("Paciente registrado correctamente.");
    pausar();
}

void mostrarPacientes() {
    Paciente paciente;
    bool hayRegistros = false;

    limpiarPantalla();
    mostrarTitulo("Listado de Pacientes");

    fstream archivo(RUTA_PACIENTES, ios::in | ios::binary);

    if (!archivo) {
        mostrarError("No se pudo abrir el archivo de pacientes.");
        pausar();
        return;
    }

    imprimirEncabezadoPacientes();

    while (archivo.read(reinterpret_cast<char *>(&paciente), sizeof(Paciente))) {
        hayRegistros = true;
        cout << left;
        cout << setw(8) << paciente.idPaciente;
        cout << setw(25) << paciente.nombre;
        cout << setw(8) << paciente.edad;
        cout << setw(8) << paciente.sexo;
        cout << setw(16) << paciente.telefono;
        cout << setw(12) << textoEstadoPaciente(paciente.estado) << endl;
    }

    archivo.close();

    if (!hayRegistros) {
        mostrarMensaje("No hay pacientes registrados.");
    }

    pausar();
}

void buscarPacientePorId() {
    Paciente paciente;
    int idPaciente;
    int posicion;

    limpiarPantalla();
    mostrarTitulo("Buscar Paciente por ID");

    idPaciente = leerEntero("Ingrese el ID del paciente: ");
    posicion = buscarPosicionPacientePorId(idPaciente);

    if (posicion == -1) {
        mostrarError("Paciente no encontrado.");
        pausar();
        return;
    }

    fstream archivo(RUTA_PACIENTES, ios::in | ios::binary);
    archivo.seekg(posicion * sizeof(Paciente), ios::beg);
    archivo.read(reinterpret_cast<char *>(&paciente), sizeof(Paciente));
    archivo.close();

    mostrarDatosPaciente(paciente);
    pausar();
}

void modificarPaciente() {
    Paciente paciente;
    int idPaciente;
    int posicion;

    limpiarPantalla();
    mostrarTitulo("Modificar Paciente");

    idPaciente = leerEntero("Ingrese el ID del paciente: ");
    posicion = buscarPosicionPacientePorId(idPaciente);

    if (posicion == -1) {
        mostrarError("Paciente no encontrado.");
        pausar();
        return;
    }

    fstream archivo(RUTA_PACIENTES, ios::in | ios::out | ios::binary);
    archivo.seekg(posicion * sizeof(Paciente), ios::beg);
    archivo.read(reinterpret_cast<char *>(&paciente), sizeof(Paciente));

    if (paciente.estado == 'D') {
        archivo.close();
        mostrarError("No se puede modificar un paciente eliminado.");
        pausar();
        return;
    }

    mostrarDatosPaciente(paciente);
    cout << endl;
    mostrarMensaje("Ingrese los nuevos datos del paciente.");

    leerDatosPaciente(paciente, false);
    paciente.estado = 'A';

    archivo.seekp(posicion * sizeof(Paciente), ios::beg);
    archivo.write(reinterpret_cast<char *>(&paciente), sizeof(Paciente));
    archivo.close();

    mostrarMensaje("Paciente modificado correctamente.");
    pausar();
}

void eliminarPaciente() {
    Paciente paciente;
    int idPaciente;
    int posicion;

    limpiarPantalla();
    mostrarTitulo("Eliminar Paciente");

    idPaciente = leerEntero("Ingrese el ID del paciente: ");
    posicion = buscarPosicionPacientePorId(idPaciente);

    if (posicion == -1) {
        mostrarError("Paciente no encontrado.");
        pausar();
        return;
    }

    fstream archivo(RUTA_PACIENTES, ios::in | ios::out | ios::binary);
    archivo.seekg(posicion * sizeof(Paciente), ios::beg);
    archivo.read(reinterpret_cast<char *>(&paciente), sizeof(Paciente));

    if (paciente.estado == 'D') {
        archivo.close();
        mostrarError("El paciente ya se encuentra eliminado.");
        pausar();
        return;
    }

    paciente.estado = 'D';
    archivo.seekp(posicion * sizeof(Paciente), ios::beg);
    archivo.write(reinterpret_cast<char *>(&paciente), sizeof(Paciente));
    archivo.close();

    mostrarMensaje("Paciente eliminado logicamente.");
    pausar();
}

void buscarPacientePorPosicion() {
    Paciente paciente;
    int posicion;

    limpiarPantalla();
    mostrarTitulo("Buscar Paciente por Posicion");

    posicion = leerEntero("Ingrese la posicion del registro (desde 0): ");

    if (posicion < 0) {
        mostrarError("La posicion no puede ser negativa.");
        pausar();
        return;
    }

    fstream archivo(RUTA_PACIENTES, ios::in | ios::binary);

    if (!archivo) {
        mostrarError("No se pudo abrir el archivo de pacientes.");
        pausar();
        return;
    }

    archivo.seekg(posicion * sizeof(Paciente), ios::beg);

    if (!archivo.read(reinterpret_cast<char *>(&paciente), sizeof(Paciente))) {
        archivo.close();
        mostrarError("No existe un paciente en esa posicion.");
        pausar();
        return;
    }

    archivo.close();
    mostrarDatosPaciente(paciente);
    pausar();
}

bool existePaciente(int idPaciente) {
    Paciente paciente;
    fstream archivo(RUTA_PACIENTES, ios::in | ios::binary);

    if (!archivo) {
        return false;
    }

    while (archivo.read(reinterpret_cast<char *>(&paciente), sizeof(Paciente))) {
        if (paciente.idPaciente == idPaciente && paciente.estado == 'A') {
            archivo.close();
            return true;
        }
    }

    archivo.close();
    return false;
}

int buscarPosicionPacientePorId(int idPaciente) {
    Paciente paciente;
    int posicion = 0;
    fstream archivo(RUTA_PACIENTES, ios::in | ios::binary);

    if (!archivo) {
        return -1;
    }

    while (archivo.read(reinterpret_cast<char *>(&paciente), sizeof(Paciente))) {
        if (paciente.idPaciente == idPaciente) {
            archivo.close();
            return posicion;
        }

        posicion++;
    }

    archivo.close();
    return -1;
}

void mostrarDatosPaciente(const Paciente &paciente) {
    cout << endl;
    cout << "ID: " << paciente.idPaciente << endl;
    cout << "Nombre: " << paciente.nombre << endl;
    cout << "Edad: " << paciente.edad << endl;
    cout << "Sexo: " << paciente.sexo << endl;
    cout << "Telefono: " << paciente.telefono << endl;
    cout << "Direccion: " << paciente.direccion << endl;
    cout << "Estado: " << textoEstadoPaciente(paciente.estado) << endl;
}
