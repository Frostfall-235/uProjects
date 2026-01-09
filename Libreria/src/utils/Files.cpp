#include"utils/Files.h"
#include"models/Libro.h"

#include<vector>
#include<string>
#include<fstream>
#include<iostream>

using namespace std;

void Files::listarCatalogo(const vector<Libro>& catalogo) {
    int index=1;
    cout << "Generando archivo del catalogo..." << endl;

    std::ofstream archivoSalida("catalogo.txt");

    if (archivoSalida.is_open()) {
        archivoSalida << "Catalogo de libros:\n\n";
        archivoSalida << "--------------------------" << endl;

        for (const auto& libro : catalogo) {
            archivoSalida << "ISBN: " << libro.getIsbn() << endl;
            archivoSalida << "Titulo: " << libro.getTitulo() << endl;
            archivoSalida << "Autor: " << libro.getAutor() << endl;
            archivoSalida << "Genero: " << libro.getGenero() << endl;
            archivoSalida << "Paginas: " << libro.getPaginas() << endl;
            archivoSalida << "Stock: " << libro.getStock() << endl;
            archivoSalida << "--------------------------" << endl;
        }
        archivoSalida.close();
        cout << "Archivo generado exitosamente: catalogo.txt" << endl;
    } else {
        cout << "No se pudo crear un archivo para el catalogo!" << endl;   
    }
}

void Files::ticketPrestamo(const Libro* libroPrestado, const string& clienteNombre) {

    cout << "Generando ticket de prestamo..." << endl;

    std::ofstream archivoSalida("tickets/prestamo_" + clienteNombre + ".txt");

    if (archivoSalida.is_open()) {
        archivoSalida << "Ticket de Prestamo\n\n";
        archivoSalida << "Cliente: " << clienteNombre << "\n";
        archivoSalida << "Libro Prestado:\n";
        archivoSalida << "  Titulo: " << libroPrestado->getTitulo() << "\n";
        archivoSalida << "  Autor: " << libroPrestado->getAutor() << "\n";
        archivoSalida << "  ISBN: " << libroPrestado->getIsbn() << "\n";

        archivoSalida.close();
        cout << "Ticket generado exitosamente: prestamo_" + clienteNombre + ".txt" << endl;
    } else {
        cout << "No se pudo crear un archivo para el ticket de prestamo!" << endl;   
    }
}

void Files::ticketDevolucion(const Libro* libroDevuelto, const string& clienteNombre) {
    cout << "Generando ticket de devolucion..." << endl;

    std::ofstream archivoSalida("tickets/devolucion_" + clienteNombre + ".txt");

    if (archivoSalida.is_open()) {
        archivoSalida << "Ticket de Devolucion\n\n";
        archivoSalida << "Cliente: " << clienteNombre << "\n";
        archivoSalida << "Libro Devuelto:\n";
        archivoSalida << "  Titulo: " << libroDevuelto->getTitulo() << "\n";
        archivoSalida << "  Autor: " << libroDevuelto->getAutor() << "\n";
        archivoSalida << "  ISBN: " << libroDevuelto->getIsbn() << "\n";

        archivoSalida.close();
        cout << "Ticket generado exitosamente: devolucion_" + clienteNombre + ".txt" << endl;
    } else {
        cout << "No se pudo crear un archivo para el ticket de devolucion!" << endl;   
    }
}