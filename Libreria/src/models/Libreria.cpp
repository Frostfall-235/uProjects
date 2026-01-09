#include"models/Libreria.h"
#include"models/Libro.h"
#include"utils/Functions.h"
#include"utils/Services.h"

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void Libreria::Menu() {
    cout << "---------------------------------" << endl;
    cout << "   1. Agregar libro" << endl;
    cout << "   2. Eliminar libro" << endl;
    cout << "   3. Actualizar libro" << endl;
    cout << "   4. Listar catalogo" << endl;
    cout << "   5. Buscar libro" << endl;
    cout << "   6. Prestar libro" << endl;
    cout << "   7. Devolver libro" << endl;
    cout << "   8. Salir" << endl;
    cout << "---------------------------------" << endl;
}

void Libreria::execute() {

    int option;
    vector<Libro> catalogo;

    // Inicio de la interfaz
    cout << "Hola! Bienvenido a VICTORTECA" << endl;

    do {
        this->Menu();

        cout << "Selecciona una opcion: "; cin >> option;

        switch(option) {
            case 1: {
                Utils::clearInputBuffer();

                Libro libro = Services::agregarLibro(catalogo);

                // Verificamos si el libro fue creado correctamente
                if (libro.getIsbn() != 0) {
                    catalogo.push_back(libro);
                    cout << "Libro agregado exitosamente!" << endl;
                }

                break;
            }

            case 2: {
                Utils::clearInputBuffer();

                Libro* libro = Services::buscarLibro(catalogo);

                if (libro != nullptr) {
                    // Lógica para eliminar el libro del catálogo
                    auto it = std::remove_if(catalogo.begin(), catalogo.end(),
                        [libro](const Libro& l) { return l.getIsbn() == libro->getIsbn(); });
                    catalogo.erase(it, catalogo.end());

                    cout << "Libro eliminado exitosamente!" << endl;
                } else {
                    cout << "No se pudo encontrar el libro que deseabas eliminar!" << endl;
                }

                break;
            }

            case 3: {
                Utils::clearInputBuffer();

                Services::actualizarLibro(catalogo);

                break;
            }
            
            case 4: {
                Utils::clearInputBuffer();

                Services::listarCatalogo(catalogo);

                break;
            }

            case 5: {
                Utils::clearInputBuffer();

                Libro* libro = Services::buscarLibro(catalogo);

                if (libro != nullptr) {
                    libro->mostrarInfo();
                } else {
                    cout << "No se pudo encontrar el libro que buscabas!" << endl;
                }
                
                break;
            }

            case 6: {
                Utils::clearInputBuffer();

                Services::prestarLibro(catalogo);
                break;
            }

            case 7: {
                Utils::clearInputBuffer();

                Services::devolverLibro(catalogo);
                break;
            }

            case 8: {
                cout << "Saliendo de la libreria... Vuelva pronto!" << endl;
                break;
            }

            default: {
                cout << "Lo siento, no pudimos encontrar esa funcion en la libreria." << endl;
                break;
            }
        }

    } while(option != 8);
}