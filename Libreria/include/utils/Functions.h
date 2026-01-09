#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include"models/Libro.h"

#include<vector>

class Utils {
    public:
        static Libro *getByIsbn(int isbn, std::vector<Libro>& catalogo);
        static bool checkLibroExists(int isbn, std::vector<Libro>& catalogo);
        static void clearInputBuffer();
};

#endif