#ifndef SERVICES_H
#define SERVICES_H

#include"models/Libro.h"

#include<vector>

class Services {
    public:
        static Libro agregarLibro(std::vector<Libro>& catalogo); 
        static Libro* buscarLibro(std::vector<Libro>& catalogo);
        static void actualizarLibro(std::vector<Libro>& catalogo);
        static void listarCatalogo(std::vector<Libro>& catalogo);
        static void prestarLibro(std::vector<Libro>& catalogo);
        static void devolverLibro(std::vector<Libro>& catalogo);
};

#endif