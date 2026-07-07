#ifndef PACIENTES_H
#define PACIENTES_H

struct Paciente {
    int idPaciente;
    char nombre[60];
    int edad;
    char sexo;
    char telefono[15];
    char direccion[80];
    char estado;
};

void registrarPaciente();
void mostrarPacientes();
void buscarPacientePorId();
void modificarPaciente();
void eliminarPaciente();
void buscarPacientePorPosicion();

bool existePaciente(int idPaciente);
int buscarPosicionPacientePorId(int idPaciente);
void mostrarDatosPaciente(const Paciente &paciente);

#endif
