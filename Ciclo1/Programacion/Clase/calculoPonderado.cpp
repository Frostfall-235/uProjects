#include<iostream>
#include<string>
#include <map>
#include <vector>

using namespace std;

int main() {

    float pf, pp;
    int nota;
    string curso;

    map<string, vector<int>> cursos;

    // Agregar cursos con sus notas
    cursos["Calculo"] = {17.5, 18.0, 19.2};
    cursos["Algebra"]    = {16.0, 15.5, 14.8};
    cursos["Biologia"]    = {13.0, 14.2, 12.5};
    cursos["Redaccion"]      = {18.5, 19.0, 17.0};
    cursos["Medio ambiente"]     = {15.5, 16.0, 14.7};
    cursos["Metodos de estudio"]    = {17.2, 18.1, 16.9};
    cursos[""]      = {14.0, 13.5, 12.0};
    cursos["Arte"]        = {19.0, 18.7, 20.0};

    for(int i=1; i<=8; i++) {
        pf=0;

        cout << "Ingresa el nombre del curso" << endl;
        getline(cin, curso);
        

        cout << "Ingresa la nota de EC de " << curso << endl;
        cin >> nota;

        pf = nota*0.4;

        cout << "Ingresa la nota de EP de " << curso << endl;
        cin >> nota;

        pf += nota*0.3;

        cout << "Ingresa la nota de EF de " << curso << endl;
        cin >> nota;

        pf += nota*0.3;
    }

    cout << endl;
    system("pause");

    return 0;
}