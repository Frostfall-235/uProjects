#include"utils/Functions.h"
#include"models/Libro.h"
#include"utils/Services.h"
#include"utils/Files.h"

#include<iostream>

using namespace std;

Libro Services::agregarLibro(vector<Libro>& catalogo) {
    
    int isbn, paginas;
    string titulo, autor, genero;

    try {
        string str;
        cout << "Ingresa el codigo ISBN del libro: "; getline(cin, str);
            // Validamos el input como entero
            isbn = stoi(str);

        // Aumentamos el stock si el libro ya existe
        if (Utils::checkLibroExists(isbn, catalogo)) {
            Libro* libro = Utils::getByIsbn(isbn, catalogo);
            libro->setStock(libro->getStock() + 1);

            cout << "Aumentas en una unidad a \"" << libro->getTitulo() << "\""<< endl;
            return *libro;
        }

        cout << "Ingresa el titulo del libro: "; getline(cin, titulo);
        cout << "Ingresa el autor del libro: "; getline(cin, autor);
        cout << "Ingresa el genero del libro: "; getline(cin, genero);
        cout << "Ingresa el numero de paginas del libro: "; getline(cin, str);
            // Validamos el input como entero
            paginas = stoi(str);

        Libro nuevoLibro(isbn, paginas, titulo, autor, genero);
        
        return nuevoLibro;
    } catch (...) {
        cout << "Hubo un error mientras agregabas un libro!" << endl;

        return Libro(0,0,"","","");
    }
}

Libro* Services::buscarLibro(vector<Libro>& catalogo) {
    int isbn;

    try {
        string str;
        cout << "Escribe el ISBN del libro que desees buscar: "; getline(cin, str);
            // Validamos el input como entero
            isbn = stoi(str);

        // Iniciamos la busqueda
        for (auto it = catalogo.begin(); it != catalogo.end(); ++it) {
            if (it->getIsbn() == isbn) {
                return &(*it);
            }
        }
    } catch (...) {
        cout << "Hubo un error mientras se buscaba el libro!" << endl;

        return nullptr;
    }

    return nullptr;
}

void Services::actualizarLibro(vector<Libro>& catalogo) {
    
    int isbn;
    string titulo, autor, genero;
    
    try {
        Libro* libro = buscarLibro(catalogo);

        if (libro == nullptr) {
            cout << "No se pudo encontrar un libro con ese ISBN!" << endl;
            return;
        }

        cout << "Ingresa el nuevo titulo del libro (actual: " << libro->getTitulo() << "): "; getline(cin, titulo);
        cout << "Ingresa el nuevo autor del libro (actual: " << libro->getAutor() << "): "; getline(cin, autor);
        cout << "Ingresa el nuevo genero del libro (actual: " << libro->getGenero() << "): "; getline(cin, genero);

        libro->setTitulo(titulo);
        libro->setAutor(autor);
        libro->setGenero(genero);

        cout << "Libro actualizado exitosamente!" << endl;
    } catch (...) {
        cout << "Hubo un error mientras se actualizaba el libro!" << endl;
    }
}

void Services::listarCatalogo(vector<Libro>& catalogo) {
    try {
        Files::listarCatalogo(catalogo);
    } catch (...) {
        cout << "Hubo un error mientras se listaba el catalogo!" << endl;
    }
}

void Services::prestarLibro(vector<Libro>& catalogo) {
    
    int isbn;
    string clienteNombre;

    try {
        Libro* libro = buscarLibro(catalogo);

        if (libro == nullptr) {
            cout << "No se pudo encontrar un libro con ese ISBN!" << endl;
            return;
        }

        if (libro->getStock() <= 0) {
            cout << "No hay stock disponible para prestar este libro!" << endl;
            return;
        }

        cout << "Ingresa el nombre del cliente: "; getline(cin, clienteNombre);

        Files::ticketPrestamo(libro, clienteNombre);
        libro->setStock(libro->getStock() - 1);
        cout << "Libro prestado exitosamente!" << endl;
    } catch (...) {
        cout << "Hubo un error mientras se prestaba el libro!" << endl;
    }
}

void Services::devolverLibro(vector<Libro>& catalogo) {
    
    int isbn;
    string clienteNombre;

    try {
        Libro* libro = buscarLibro(catalogo);

        if (libro == nullptr) {
            cout << "No se pudo encontrar un libro con ese ISBN!" << endl;
            return;
        }

        cout << "Ingresa el nombre del cliente: "; getline(cin, clienteNombre);

        Files::ticketDevolucion(libro, clienteNombre);
        libro->setStock(libro->getStock() + 1);
        cout << "Libro devuelto exitosamente!" << endl;
    } catch (...) {
        cout << "Hubo un error mientras se devolvia el libro!" << endl;
    }
}