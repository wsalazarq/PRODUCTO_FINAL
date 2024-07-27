#include "biblioteca.h"
#include <iostream>
using namespace std;

const int maxLibros = 100;
const int maxUsuarios = 100;

Usuario estudiantes[maxUsuarios];
Usuario administradores[maxUsuarios];
Libro biblioteca[maxLibros];

int numLibros = 0;
int numEstudiantes = 0;
int numAdministradores = 0;

void agregarUsuario(string nombre, bool esAdmin) {
    if (esAdmin == true) {
        if (numAdministradores < maxUsuarios) {
            administradores[numAdministradores].nombre = nombre;
            administradores[numAdministradores].esAdmin = esAdmin;
            numAdministradores++;
            cout<<"Administrador '"<<nombre<<"' agregado correctamente"<<endl;
        } else {
            cout<<"No se puede agregar mas administradores"<<endl;
        }
    }else{
        if (numEstudiantes < maxUsuarios) {
            estudiantes[numEstudiantes].nombre = nombre;
            estudiantes[numEstudiantes].esAdmin = esAdmin;
            numEstudiantes++;
            cout<<"Estudiante '"<<nombre<<"' agregado correctamente"<<endl;
        } else {
            cout<<"No se puede agregar mas estudiantes"<<endl;
        }
    }
    system("pause");
}

void agregarLibro(string titulo, string autor, int anio){

    if (numLibros >= maxLibros) {
        cout<<"No se puede agregar mas libros, la biblioteca está llena"<<endl;
    }else{
        biblioteca[numLibros].titulo = titulo;
        biblioteca[numLibros].autor = autor;
        biblioteca[numLibros].anio = anio;
        biblioteca[numLibros].disponible = true;
        numLibros++;
        cout<<"Libro '"<<titulo<<"' agregado correctamente"<<endl;
    }
    system("pause"); 
}