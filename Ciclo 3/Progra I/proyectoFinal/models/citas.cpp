#include "citas.h"

#include <fstream>
#include <iomanip>
#include <iostream>

#include "../archivos.h"
#include "../models/pacientes.h"
#include "../utilidades.h"

using namespace std;

void imprimirEncabezadoCitas() {
    cout << left;
    cout << setw(8) << "ID";
    cout << setw(12) << "Paciente";
    cout << setw(22) << "Medico";
    cout << setw(20) << "Especialidad";
    cout << setw(14) << "Fecha";
    cout << setw(10) << "Hora";
    cout << setw(12) << "Estado" << endl;
    cout << "------------------------------------------------------------------------------------------------" << endl;
}

const char *textoEstadoCita(char estado) {
    if (estado == 'P') {
        return "Pendiente";
    }

    if (estado == 'A') {
        return "Atendida";
    }

    if (estado == 'C') {
        return "Cancelada";
    }

    if (estado == 'D') {
        return "Eliminada";
    }

    return "Desconocido";
}

void leerDatosCita(Cita &cita, bool leerId) {
    if (leerId) {
        cita.idCita = leerEnteroMinimo("ID de la cita: ", 1);
    }

    cita.idPaciente = leerEnteroMinimo("ID del paciente: ", 1);
    leerTexto(cita.medico, 50, "Medico: ");
    leerTexto(cita.especialidad, 40, "Especialidad: ");
    leerFecha(cita.fecha, 11, "Fecha (dd/mm/aaaa): ");
    leerHora(cita.hora, 6, "Hora (hh:mm): ");
}

void mostrarFilaCita(const Cita &cita) {
    cout << left;
    cout << setw(8) << cita.idCita;
    cout << setw(12) << cita.idPaciente;
    cout << setw(22) << cita.medico;
    cout << setw(20) << cita.especialidad;
    cout << setw(14) << cita.fecha;
    cout << setw(10) << cita.hora;
    cout << setw(12) << textoEstadoCita(cita.estado) << endl;
}

void registrarCita() {
    Cita cita;

    limpiarPantalla();
    mostrarTitulo("Registrar Cita");

    // 1) Validar ID de cita primero (para no pedir datos extra si el ID ya existe).
    cita.idCita = leerEnteroMinimo("ID de la cita: ", 1);

    if (buscarPosicionCitaPorId(cita.idCita) != -1) {
        mostrarError("Ya existe una cita con ese ID.");
        pausar();
        return;
    }

    // 2) Validar ID de paciente antes de pedir medico/fecha/hora.
    cita.idPaciente = leerEnteroMinimo("ID del paciente: ", 1);

    if (!existePaciente(cita.idPaciente)) {
        mostrarError("No existe un paciente activo con ese ID.");
        pausar();
        return;
    }

    // 3) Recién ahora completar los demás datos.
    leerTexto(cita.medico, 50, "Medico: ");
    leerTexto(cita.especialidad, 40, "Especialidad: ");
    leerFecha(cita.fecha, 11, "Fecha (dd/mm/aaaa): ");
    leerHora(cita.hora, 6, "Hora (hh:mm): ");

    cita.estado = 'P';

    fstream archivo(RUTA_CITAS, ios::out | ios::app | ios::binary);

    if (!archivo) {
        mostrarError("No se pudo abrir el archivo de citas.");
        pausar();
        return;
    }

    archivo.write(reinterpret_cast<char *>(&cita), sizeof(Cita));
    archivo.close();

    mostrarMensaje("Cita registrada correctamente.");
    pausar();
}


void mostrarCitas() {
    Cita cita;
    bool hayRegistros = false;

    limpiarPantalla();
    mostrarTitulo("Listado de Citas");

    fstream archivo(RUTA_CITAS, ios::in | ios::binary);

    if (!archivo) {
        mostrarError("No se pudo abrir el archivo de citas.");
        pausar();
        return;
    }

    imprimirEncabezadoCitas();

    while (archivo.read(reinterpret_cast<char *>(&cita), sizeof(Cita))) {
        hayRegistros = true;
        mostrarFilaCita(cita);
    }

    archivo.close();

    if (!hayRegistros) {
        mostrarMensaje("No hay citas registradas.");
    }

    pausar();
}

void buscarCita() {
    Cita cita;
    int idCita;
    int posicion;

    limpiarPantalla();
    mostrarTitulo("Buscar Cita");

    idCita = leerEntero("Ingrese el ID de la cita: ");
    posicion = buscarPosicionCitaPorId(idCita);

    if (posicion == -1) {
        mostrarError("Cita no encontrada.");
        pausar();
        return;
    }

    fstream archivo(RUTA_CITAS, ios::in | ios::binary);
    archivo.seekg(posicion * sizeof(Cita), ios::beg);
    archivo.read(reinterpret_cast<char *>(&cita), sizeof(Cita));
    archivo.close();

    mostrarDatosCita(cita);
    pausar();
}

void modificarCita() {
    Cita cita;
    char estadoActual;
    int idCita;
    int posicion;

    limpiarPantalla();
    mostrarTitulo("Modificar Cita");

    idCita = leerEntero("Ingrese el ID de la cita: ");
    posicion = buscarPosicionCitaPorId(idCita);

    if (posicion == -1) {
        mostrarError("Cita no encontrada.");
        pausar();
        return;
    }

    fstream archivo(RUTA_CITAS, ios::in | ios::out | ios::binary);
    archivo.seekg(posicion * sizeof(Cita), ios::beg);
    archivo.read(reinterpret_cast<char *>(&cita), sizeof(Cita));

    if (cita.estado == 'D') {
        archivo.close();
        mostrarError("No se puede modificar una cita eliminada.");
        pausar();
        return;
    }

    mostrarDatosCita(cita);
    cout << endl;
    mostrarMensaje("Ingrese los nuevos datos de la cita.");

    estadoActual = cita.estado;
    leerDatosCita(cita, false);

    if (!existePaciente(cita.idPaciente)) {
        archivo.close();
        mostrarError("No existe un paciente activo con ese ID.");
        pausar();
        return;
    }

    cita.idCita = idCita;
    cita.estado = estadoActual;

    archivo.seekp(posicion * sizeof(Cita), ios::beg);
    archivo.write(reinterpret_cast<char *>(&cita), sizeof(Cita));
    archivo.close();

    mostrarMensaje("Cita modificada correctamente.");
    pausar();
}

void cancelarCita() {
    Cita cita;
    int idCita;
    int posicion;

    limpiarPantalla();
    mostrarTitulo("Cancelar Cita");

    idCita = leerEntero("Ingrese el ID de la cita: ");
    posicion = buscarPosicionCitaPorId(idCita);

    if (posicion == -1) {
        mostrarError("Cita no encontrada.");
        pausar();
        return;
    }

    fstream archivo(RUTA_CITAS, ios::in | ios::out | ios::binary);
    archivo.seekg(posicion * sizeof(Cita), ios::beg);
    archivo.read(reinterpret_cast<char *>(&cita), sizeof(Cita));

    if (cita.estado == 'D') {
        archivo.close();
        mostrarError("No se puede cancelar una cita eliminada.");
        pausar();
        return;
    }

    if (cita.estado == 'A') {
        archivo.close();
        mostrarError("No se puede cancelar una cita atendida.");
        pausar();
        return;
    }

    if (cita.estado == 'C') {
        archivo.close();
        mostrarError("La cita ya esta cancelada.");
        pausar();
        return;
    }

    cita.estado = 'C';
    archivo.seekp(posicion * sizeof(Cita), ios::beg);
    archivo.write(reinterpret_cast<char *>(&cita), sizeof(Cita));
    archivo.close();

    mostrarMensaje("Cita cancelada correctamente.");
    pausar();
}

void marcarCitaAtendida() {
    Cita cita;
    int idCita;
    int posicion;

    limpiarPantalla();
    mostrarTitulo("Marcar Cita como Atendida");

    idCita = leerEntero("Ingrese el ID de la cita: ");
    posicion = buscarPosicionCitaPorId(idCita);

    if (posicion == -1) {
        mostrarError("Cita no encontrada.");
        pausar();
        return;
    }

    fstream archivo(RUTA_CITAS, ios::in | ios::out | ios::binary);
    archivo.seekg(posicion * sizeof(Cita), ios::beg);
    archivo.read(reinterpret_cast<char *>(&cita), sizeof(Cita));

    if (cita.estado == 'D') {
        archivo.close();
        mostrarError("No se puede atender una cita eliminada.");
        pausar();
        return;
    }

    if (cita.estado == 'C') {
        archivo.close();
        mostrarError("No se puede atender una cita cancelada.");
        pausar();
        return;
    }

    if (cita.estado == 'A') {
        archivo.close();
        mostrarError("La cita ya esta atendida.");
        pausar();
        return;
    }

    cita.estado = 'A';
    archivo.seekp(posicion * sizeof(Cita), ios::beg);
    archivo.write(reinterpret_cast<char *>(&cita), sizeof(Cita));
    archivo.close();

    mostrarMensaje("Cita marcada como atendida correctamente.");
    pausar();
}

void buscarCitaPorPosicion() {
    Cita cita;
    int posicion;

    limpiarPantalla();
    mostrarTitulo("Buscar Cita por Posicion");

    posicion = leerEntero("Ingrese la posicion del registro (desde 0): ");

    if (posicion < 0) {
        mostrarError("La posicion no puede ser negativa.");
        pausar();
        return;
    }

    fstream archivo(RUTA_CITAS, ios::in | ios::binary);

    if (!archivo) {
        mostrarError("No se pudo abrir el archivo de citas.");
        pausar();
        return;
    }

    archivo.seekg(posicion * sizeof(Cita), ios::beg);

    if (!archivo.read(reinterpret_cast<char *>(&cita), sizeof(Cita))) {
        archivo.close();
        mostrarError("No existe una cita en esa posicion.");
        pausar();
        return;
    }

    archivo.close();
    mostrarDatosCita(cita);
    pausar();
}

bool existeCita(int idCita) {
    Cita cita;
    fstream archivo(RUTA_CITAS, ios::in | ios::binary);

    if (!archivo) {
        return false;
    }

    while (archivo.read(reinterpret_cast<char *>(&cita), sizeof(Cita))) {
        if (cita.idCita == idCita && cita.estado != 'D') {
            archivo.close();
            return true;
        }
    }

    archivo.close();
    return false;
}

int buscarPosicionCitaPorId(int idCita) {
    Cita cita;
    int posicion = 0;
    fstream archivo(RUTA_CITAS, ios::in | ios::binary);

    if (!archivo) {
        return -1;
    }

    while (archivo.read(reinterpret_cast<char *>(&cita), sizeof(Cita))) {
        if (cita.idCita == idCita) {
            archivo.close();
            return posicion;
        }

        posicion++;
    }

    archivo.close();
    return -1;
}

void mostrarDatosCita(const Cita &cita) {
    cout << endl;
    cout << "ID cita: " << cita.idCita << endl;
    cout << "ID paciente: " << cita.idPaciente << endl;
    cout << "Medico: " << cita.medico << endl;
    cout << "Especialidad: " << cita.especialidad << endl;
    cout << "Fecha: " << cita.fecha << endl;
    cout << "Hora: " << cita.hora << endl;
    cout << "Estado: " << textoEstadoCita(cita.estado) << endl;
}
