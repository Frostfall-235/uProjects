#ifndef CITAS_H
#define CITAS_H

struct Cita {
    int idCita;
    int idPaciente;
    char medico[50];
    char especialidad[40];
    char fecha[11];
    char hora[6];
    char estado;
};

void registrarCita();
void mostrarCitas();
void buscarCita();
void modificarCita();
void cancelarCita();
void marcarCitaAtendida();
void buscarCitaPorPosicion();

bool existeCita(int idCita);
int buscarPosicionCitaPorId(int idCita);
void mostrarDatosCita(const Cita &cita);

#endif
