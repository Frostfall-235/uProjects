#include"utils/Functions.h"
#include"models/Libro.h"
#include<vector>
#include<limits>
#include<iostream>

using namespace std;

Libro *Utils::getByIsbn(int isbn, vector<Libro>& catalogo) {
    for (auto it = catalogo.begin(); it != catalogo.end(); ++it) {
        if (it->getIsbn() == isbn) {
            return &(*it);
        }
    }
    return nullptr;
}

bool Utils::checkLibroExists(int isbn, vector<Libro>& catalogo) {
    for (auto it = catalogo.begin(); it != catalogo.end(); ++it) {
        if (it->getIsbn() == isbn) {
            return true;
        }
    }
    return false;
}

void Utils::clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}