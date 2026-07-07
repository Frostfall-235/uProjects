#include "menus.h"

#include <iostream>

#include "models/citas.h"
#include "models/pacientes.h"
#include "reportes/reportes.h"
#include "utilidades.h"

using namespace std;

void mostrarMenuPrincipal() {
    int opcion;

    do {
        limpiarPantalla();
        mostrarTitulo("Sistema de Gestion Hospitalaria");
        cout << "1. Gestion de pacientes" << endl;
        cout << "2. Gestion de citas" << endl;
        cout << "3. Reportes" << endl;
        cout << "4. Salir" << endl;
        cout << endl;

        opcion = leerOpcion("Seleccione una opcion: ");

        switch (opcion) {
            case 1:
                mostrarMenuPacientes();
                break;
            case 2:
                mostrarMenuCitas();
                break;
            case 3:
                mostrarMenuReportes();
                break;
            case 4:
                mostrarMensaje("Saliendo del sistema...");
                break;
            default:
                mostrarError("Opcion invalida.");
                pausar();
                break;
        }
    } while (opcion != 4);
}

void mostrarMenuPacientes() {
    int opcion;

    do {
        limpiarPantalla();
        mostrarTitulo("Gestion de Pacientes");
        cout << "1. Registrar paciente" << endl;
        cout << "2. Mostrar pacientes" << endl;
        cout << "3. Buscar paciente por ID" << endl;
        cout << "4. Modificar paciente" << endl;
        cout << "5. Eliminar paciente" << endl;
        cout << "6. Buscar paciente por posicion" << endl;
        cout << "7. Volver" << endl;
        cout << endl;

        opcion = leerOpcion("Seleccione una opcion: ");

        switch (opcion) {
            case 1:
                registrarPaciente();
                break;
            case 2:
                mostrarPacientes();
                break;
            case 3:
                buscarPacientePorId();
                break;
            case 4:
                modificarPaciente();
                break;
            case 5:
                eliminarPaciente();
                break;
            case 6:
                buscarPacientePorPosicion();
                break;
            case 7:
                break;
            default:
                mostrarError("Opcion invalida.");
                pausar();
                break;
        }
    } while (opcion != 7);
}

void mostrarMenuCitas() {
    int opcion;

    do {
        limpiarPantalla();
        mostrarTitulo("Gestion de Citas");
        cout << "1. Registrar cita" << endl;
        cout << "2. Mostrar citas" << endl;
        cout << "3. Buscar cita" << endl;
        cout << "4. Modificar cita" << endl;
        cout << "5. Cancelar cita" << endl;
        cout << "6. Marcar cita como atendida" << endl;
        cout << "7. Buscar cita por posicion" << endl;
        cout << "8. Volver" << endl;
        cout << endl;

        opcion = leerOpcion("Seleccione una opcion: ");

        switch (opcion) {
            case 1:
                registrarCita();
                break;
            case 2:
                mostrarCitas();
                break;
            case 3:
                buscarCita();
                break;
            case 4:
                modificarCita();
                break;
            case 5:
                cancelarCita();
                break;
            case 6:
                marcarCitaAtendida();
                break;
            case 7:
                buscarCitaPorPosicion();
                break;
            case 8:
                break;
            default:
                mostrarError("Opcion invalida.");
                pausar();
                break;
        }
    } while (opcion != 8);
}

void mostrarMenuReportes() {
    int opcion;

    do {
        limpiarPantalla();
        mostrarTitulo("Reportes");
        cout << "1. Total de pacientes" << endl;
        cout << "2. Pacientes activos" << endl;
        cout << "3. Pacientes eliminados" << endl;
        cout << "4. Total de citas" << endl;
        cout << "5. Citas pendientes" << endl;
        cout << "6. Citas atendidas" << endl;
        cout << "7. Citas canceladas" << endl;
        cout << "8. Cantidad de citas por medico" << endl;
        cout << "9. Cantidad de citas por especialidad" << endl;
        cout << "10. Volver" << endl;
        cout << endl;

        opcion = leerOpcion("Seleccione una opcion: ");

        switch (opcion) {
            case 1:
                reporteTotalPacientes();
                break;
            case 2:
                reportePacientesActivos();
                break;
            case 3:
                reportePacientesEliminados();
                break;
            case 4:
                reporteTotalCitas();
                break;
            case 5:
                reporteCitasPendientes();
                break;
            case 6:
                reporteCitasAtendidas();
                break;
            case 7:
                reporteCitasCanceladas();
                break;
            case 8:
                reporteCitasPorMedico();
                break;
            case 9:
                reporteCitasPorEspecialidad();
                break;
            case 10:
                break;
            default:
                mostrarError("Opcion invalida.");
                pausar();
                break;
        }
    } while (opcion != 10);
}
