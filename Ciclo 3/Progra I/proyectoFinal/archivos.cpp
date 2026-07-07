#include "archivos.h"

#include <fstream>

using namespace std;

void inicializarArchivos() {
    crearArchivoSiNoExiste(RUTA_PACIENTES);
    crearArchivoSiNoExiste(RUTA_CITAS);
}

bool existeArchivo(const char ruta[]) {
    fstream archivo(ruta, ios::in | ios::binary);
    return archivo.good();
}

void crearArchivoSiNoExiste(const char ruta[]) {
    if (!existeArchivo(ruta)) {
        fstream archivo(ruta, ios::out | ios::binary);
        archivo.close();
    }
}
