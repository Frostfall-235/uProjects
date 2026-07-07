#ifndef UTILIDADES_H
#define UTILIDADES_H

void limpiarPantalla();
void pausar();
void mostrarTitulo(const char titulo[]);
void mostrarMensaje(const char mensaje[]);
void mostrarError(const char mensaje[]);
int leerOpcion(const char mensaje[]);
int leerEntero(const char mensaje[]);
int leerEnteroMinimo(const char mensaje[], int minimo);
int leerEnteroRango(const char mensaje[], int minimo, int maximo);
char leerCaracter(const char mensaje[]);
char leerSexo(const char mensaje[]);
void leerTexto(char destino[], int tamano, const char mensaje[]);
void leerTelefono(char destino[], int tamano, const char mensaje[]);
void leerFecha(char destino[], int tamano, const char mensaje[]);
void leerHora(char destino[], int tamano, const char mensaje[]);

#endif
