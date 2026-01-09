#ifndef LIBRO_H
#define LIBRO_H

#include<string>

class Libro {
    private:
        int isbn;
        int stock;
        int paginas;
        std::string titulo;
        std::string autor;
        std::string genero;

    public:
        Libro(int isbn, int paginas, 
            const std::string& titulo, 
            const std::string& autor, 
            const std::string& genero);

        // Getters
        int getIsbn() const;
        int getStock() const;
        int getPaginas() const;
        std::string getTitulo() const;
        std::string getAutor() const;
        std::string getGenero() const;

        // Setters
        void setStock(int stock);
        void setPaginas(int paginas);
        void setTitulo(const std::string& titulo);
        void setAutor(const std::string& autor);
        void setGenero(const std::string& genero);

        // Mostrar información del libro
        void mostrarInfo();
};

#endif