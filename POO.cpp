#include<iostream>
#include<vector>
#include<limits>
#include<string>

using namespace std;

class Libro {
    public:
        // Constructor para cada libro
        Libro(int isbn, string t, string a, string g) {
            this->isbn = isbn;
            this->titulo = t;
            this->autor = a;
            this->genero = g;
            this->cantidad = 1;

            /**
             * Siempre que se llame al constructor será porque
             * se está agregando un nuevo libro al catálogo.
             * Por ello, eso garantiza la existencia de por
             * lo menos un libro de esa clase en la librería.
             */
        }

        // Getters
        string getTitle() {
           return this->titulo; 
        }


        int getIsbn() {
            return this->isbn;
        }

        // Setters
        void mostrarInfo() {
            cout << "{" << endl;
            cout << " Titulo: " << this->titulo << "," << endl;
            cout << " Autor: " << this->autor << "," << endl;
            cout << " Genero: " << this->genero << "," << endl;
            cout << " Cantidad: " << this->cantidad << endl;
            cout << "}" << endl;
        }

        void aumentarCantidad() {
            this->cantidad += 1;
        }


    private:
        string titulo;
        string autor;
        string genero;
        int isbn;
        int cantidad;
};

class Utils {
    public:
        static Libro *getByIsbn(int isbn, vector<Libro>& catalogo) {
            for (auto it = catalogo.begin(); it != catalogo.end(); ++it) {
                if (it->getIsbn() == isbn) {
                    return &(*it);
                }
            }
            return nullptr;
        }

        static bool checkLibroExists(int isbn, vector<Libro>& catalogo) {
            for (auto it = catalogo.begin(); it != catalogo.end(); ++it) {
                if (it->getIsbn() == isbn) {
                    return true;
                }
            }
            return false;
        }

        static void clearInputBuffer() {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
};

class Libreria {
    public:
        void execute() {
            
            int option;
            vector<Libro> catalogo;

            // Inicio de la interfaz
            cout << "Hola! Bienvenido a VICTORTECA" << endl;

            do {
                int isbn;
                string titulo;
                string autor;
                string genero;

                this->Menu();

                /**
                 * Que 'option' sea válido lo garantiza
                 * el valor 'default' dentro del switch.
                 * ya que si no se identifica algún caso
                 * válido, solo enviará esa advertencia.
                 */
                cin >> option;

                switch(option) {
                    case 1: {
                        // Limpiar el buffer de entrada
                        Utils::clearInputBuffer();

                        try {
                            string str;
                            cout << "Ingresa el codigo ISBN del libro: "; getline(cin, str);
                                // Validamos el input como entero
                                isbn = stoi(str);

                            // Si ya existe, solo agregamos un ejemplar más
                            if (Utils::checkLibroExists(isbn, catalogo)) {
                                Libro* libro = Utils::getByIsbn(isbn, catalogo);
                                libro->aumentarCantidad();

                                cout << "Aumentas en una unidad a \"" << libro->getTitle() << "\""<< endl;
                                break;
                            }

                            cout << "Ingresa el titulo del libro: ";  getline(cin, titulo);
                            cout << "Ingresa el nombre del autor del libro: "; getline(cin, autor);
                            cout << "Ingresa el genero del libro: "; getline(cin, genero);

                            Libro nuevoLibro(isbn, titulo, autor, genero);
                            catalogo.push_back(nuevoLibro);
                            cout << "Libro agregado exitosamente!" << endl;
                        } catch (...) {
                            cout << "Hubo un error mientras agregabas un libro!" << endl;
                        }

                        break;
                    }

                    case 2: {
                        // Limpiar el buffer de entrada
                        Utils::clearInputBuffer();

                        try {
                            // Por defecto no ha sido encontrado
                            bool find = false;

                            string str;
                            cout << "Escribe el ISBN del libro que desees eliminar: "; getline(cin, str);
                                // Validamos el input como entero
                                isbn = stoi(str);

                            // Iniciamos la busqueda
                            for (auto it = catalogo.begin(); it != catalogo.end(); ++it) {
                                if (it->getIsbn() == isbn) {
                                    catalogo.erase(it);
                                    cout << "Libro eliminado exitosamente!" << endl;
                                    find = true;
                                    break;
                                }
                            }

                            if (!find) {
                                cout << "No se pudo encontrar un libro con ese ISBN!" << endl;
                            }
                        } catch(...) {
                            cout << "Hubo un error mientras eliminabas un libro!" << endl;
                        }

                        break;
                    }

                    case 5: {
                        // Limpiar el buffer de entrada
                        Utils::clearInputBuffer();
                        
                        try {
                            // Por defecto no ha sido encontrado
                            bool find = false;

                            string str;
                            cout << "Escribe el ISBN del libro que desees buscar: "; getline(cin, str);
                                // Validamos el input como entero
                                isbn = stoi(str);

                            // Iniciamos la busqueda
                            for (auto it = catalogo.begin(); it != catalogo.end(); ++it) {
                                if (it->getIsbn() == isbn) {
                                    it->mostrarInfo();
                                    find = true;
                                    break;
                                }
                            }

                            if (!find) {
                                cout << "No se pudo encontrar el libro que buscabas!" << endl;
                            }
                        } catch(...) {
                            cout << "Hubo un error mientras buscabas el libro!" << endl;
                        }

                        break;
                    }

                    case 8: 
                        cout << "Saliendo de la libreria... Vuelva pronto!" << endl;
                        break;

                    default: 
                        cout << "Lo siento, no pudimos encontrar esa funcion en la libreria." << endl;
                        break;
                }
            } while(option != 8);
        }

    private:
        void Menu() {
            cout << "---------------------------------" << endl;
            cout << "   1. Agregar libro" << endl; // 1
            cout << "   2. Eliminar libro" << endl; // 1
            cout << "   3. Actualizar libro" << endl;
            cout << "   4. Listar catalogo" << endl;
            cout << "   5. Buscar libro" << endl; // 1
            cout << "   6. Prestar libro" << endl;
            cout << "   7. Devolver libro" << endl;
            cout << "   8. Salir" << endl;
            cout << "---------------------------------" << endl;
        }
};

int main() {

    Libreria app;
    app.execute();

    system("pause");
    return 0;
}