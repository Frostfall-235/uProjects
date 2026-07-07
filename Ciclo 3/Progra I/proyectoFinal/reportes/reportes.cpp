#include "reportes.h"

#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>

#include "../archivos.h"
#include "../models/citas.h"
#include "../models/pacientes.h"
#include "../utilidades.h"

using namespace std;

const int MAX_GRUPOS_REPORTE = 100;

struct ConteoTexto {
    char texto[50];
    int cantidad;
};

int contarPacientesPorEstado(char estadoBuscado) {
    Paciente paciente;
    int contador = 0;
    fstream archivo(RUTA_PACIENTES, ios::in | ios::binary);

    if (!archivo) {
        return 0;
    }

    while (archivo.read(reinterpret_cast<char *>(&paciente), sizeof(Paciente))) {
        if (paciente.estado == estadoBuscado) {
            contador++;
        }
    }

    archivo.close();
    return contador;
}

int contarTotalPacientes() {
    Paciente paciente;
    int contador = 0;
    fstream archivo(RUTA_PACIENTES, ios::in | ios::binary);

    if (!archivo) {
        return 0;
    }

    while (archivo.read(reinterpret_cast<char *>(&paciente), sizeof(Paciente))) {
        contador++;
    }

    archivo.close();
    return contador;
}

int contarCitasPorEstado(char estadoBuscado) {
    Cita cita;
    int contador = 0;
    fstream archivo(RUTA_CITAS, ios::in | ios::binary);

    if (!archivo) {
        return 0;
    }

    while (archivo.read(reinterpret_cast<char *>(&cita), sizeof(Cita))) {
        if (cita.estado == estadoBuscado) {
            contador++;
        }
    }

    archivo.close();
    return contador;
}

int contarTotalCitas() {
    Cita cita;
    int contador = 0;
    fstream archivo(RUTA_CITAS, ios::in | ios::binary);

    if (!archivo) {
        return 0;
    }

    while (archivo.read(reinterpret_cast<char *>(&cita), sizeof(Cita))) {
        contador++;
    }

    archivo.close();
    return contador;
}

int buscarGrupo(ConteoTexto grupos[], int totalGrupos, const char texto[]) {
    for (int i = 0; i < totalGrupos; i++) {
        if (strcmp(grupos[i].texto, texto) == 0) {
            return i;
        }
    }

    return -1;
}

void agregarConteo(ConteoTexto grupos[], int &totalGrupos, const char texto[]) {
    int posicion = buscarGrupo(grupos, totalGrupos, texto);

    if (posicion != -1) {
        grupos[posicion].cantidad++;
        return;
    }

    if (totalGrupos < MAX_GRUPOS_REPORTE) {
        strcpy(grupos[totalGrupos].texto, texto);
        grupos[totalGrupos].cantidad = 1;
        totalGrupos++;
    }
}

void mostrarConteosAgrupados(ConteoTexto grupos[], int totalGrupos, const char encabezado[]) {
    if (totalGrupos == 0) {
        mostrarMensaje("No hay datos para mostrar.");
        return;
    }

    cout << left;
    cout << setw(35) << encabezado;
    cout << setw(10) << "Cantidad" << endl;
    cout << "---------------------------------------------" << endl;

    for (int i = 0; i < totalGrupos; i++) {
        cout << left;
        cout << setw(35) << grupos[i].texto;
        cout << setw(10) << grupos[i].cantidad << endl;
    }
}

void reporteTotalPacientes() {
    limpiarPantalla();
    mostrarTitulo("Reporte Total de Pacientes");
    cout << "Total de pacientes registrados: " << contarTotalPacientes() << endl;
    pausar();
}

void reportePacientesActivos() {
    limpiarPantalla();
    mostrarTitulo("Reporte Pacientes Activos");
    cout << "Pacientes activos: " << contarPacientesPorEstado('A') << endl;
    pausar();
}

void reportePacientesEliminados() {
    limpiarPantalla();
    mostrarTitulo("Reporte Pacientes Eliminados");
    cout << "Pacientes eliminados: " << contarPacientesPorEstado('D') << endl;
    pausar();
}

void reporteTotalCitas() {
    limpiarPantalla();
    mostrarTitulo("Reporte Total de Citas");
    cout << "Total de citas registradas: " << contarTotalCitas() << endl;
    pausar();
}

void reporteCitasPendientes() {
    limpiarPantalla();
    mostrarTitulo("Reporte Citas Pendientes");
    cout << "Citas pendientes: " << contarCitasPorEstado('P') << endl;
    pausar();
}

void reporteCitasAtendidas() {
    limpiarPantalla();
    mostrarTitulo("Reporte Citas Atendidas");
    cout << "Citas atendidas: " << contarCitasPorEstado('A') << endl;
    pausar();
}

void reporteCitasCanceladas() {
    limpiarPantalla();
    mostrarTitulo("Reporte Citas Canceladas");
    cout << "Citas canceladas: " << contarCitasPorEstado('C') << endl;
    pausar();
}

void reporteCitasPorMedico() {
    Cita cita;
    ConteoTexto grupos[MAX_GRUPOS_REPORTE];
    int totalGrupos = 0;

    limpiarPantalla();
    mostrarTitulo("Reporte Citas por Medico");

    fstream archivo(RUTA_CITAS, ios::in | ios::binary);

    if (!archivo) {
        mostrarError("No se pudo abrir el archivo de citas.");
        pausar();
        return;
    }

    while (archivo.read(reinterpret_cast<char *>(&cita), sizeof(Cita))) {
        if (cita.estado != 'D') {
            agregarConteo(grupos, totalGrupos, cita.medico);
        }
    }

    archivo.close();
    mostrarConteosAgrupados(grupos, totalGrupos, "Medico");
    pausar();
}

void reporteCitasPorEspecialidad() {
    Cita cita;
    ConteoTexto grupos[MAX_GRUPOS_REPORTE];
    int totalGrupos = 0;

    limpiarPantalla();
    mostrarTitulo("Reporte Citas por Especialidad");

    fstream archivo(RUTA_CITAS, ios::in | ios::binary);

    if (!archivo) {
        mostrarError("No se pudo abrir el archivo de citas.");
        pausar();
        return;
    }

    while (archivo.read(reinterpret_cast<char *>(&cita), sizeof(Cita))) {
        if (cita.estado != 'D') {
            agregarConteo(grupos, totalGrupos, cita.especialidad);
        }
    }

    archivo.close();
    mostrarConteosAgrupados(grupos, totalGrupos, "Especialidad");
    pausar();
}
