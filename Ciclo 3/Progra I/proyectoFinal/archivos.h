#ifndef ARCHIVOS_H
#define ARCHIVOS_H

const char RUTA_PACIENTES[] = "data/pacientes.bin";
const char RUTA_CITAS[] = "data/citas.bin";

void inicializarArchivos();
bool existeArchivo(const char ruta[]);
void crearArchivoSiNoExiste(const char ruta[]);

#endif
