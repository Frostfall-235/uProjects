#include"models/Libro.h"
#include<iostream>

using namespace std;

Libro::Libro(int isbn, int paginas,
            const string& titulo,
            const string& autor,
            const string& genero) 
    :   isbn(isbn),
        paginas(paginas),
        titulo(titulo),
        autor(autor),
        genero(genero),
        stock(1) // Inicializamos el stock en 1 
{}

// Getters
int Libro::getIsbn() const {
    return isbn;
}

int Libro::getStock() const {
    return stock;
}

int Libro::getPaginas() const {
    return paginas;
}

string Libro::getTitulo() const {
    return titulo;
}

string Libro::getAutor() const {
    return autor;
}

string Libro::getGenero() const {
    return genero;
}

// Setters
void Libro::setStock(int stock) {
    this->stock = stock;
}

void Libro::setPaginas(int paginas) {
    this->paginas = paginas;
}

void Libro::setTitulo(const string& titulo) {
    this->titulo = titulo;
}

void Libro::setAutor(const string& autor) {
    this->autor = autor;
}

void Libro::setGenero(const string& genero) {
    this->genero = genero;
}

// Mostrar información del libro
void Libro::mostrarInfo() {
    cout << "{" << endl;
    cout << "   ISBN: " << isbn << endl;
    cout << "   Titulo: " << titulo << endl;
    cout << "   Autor: " << autor << endl;
    cout << "   Genero: " << genero << endl;
    cout << "   Paginas: " << paginas << endl;
    cout << "   Stock: " << stock << endl;
    cout << "}" << endl;
}