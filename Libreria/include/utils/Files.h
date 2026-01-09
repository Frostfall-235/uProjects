#ifndef FILES_H
#define FILES_H

#include"models/Libro.h"

#include<vector>
#include<string>

class Files {
    public:
        static void listarCatalogo(const std::vector<Libro>& catalogo);
        static void ticketPrestamo(const Libro* libroPrestado, const std::string& clienteNombre);
        static void ticketDevolucion(const Libro* libroDevuelto, const std::string& clienteNombre);
};

#endif