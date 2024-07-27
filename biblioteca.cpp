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

void agregarUsuario(string nombre, bool esAdmin){
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
    cout<<endl;
}

bool libroExiste(string titulo){
    for (int i = 0; i < numLibros; i++) {
        if (biblioteca[i].titulo == titulo) {
            return true;
        }
    }
    return false;
}

void agregarLibro(string titulo, string autor, int anio){
    bool puedeAgregar = true;

    if (numLibros >= maxLibros) {
        cout<<"No se puede agregar mas libros, la biblioteca esta llena"<<endl;
        puedeAgregar = false;
    }
    if (libroExiste(titulo) == true){
        cout<<"El libro '"<<titulo<<"' ya existe en la biblioteca"<<endl;
        puedeAgregar = false;
    }
    if(puedeAgregar == true){
        biblioteca[numLibros].titulo = titulo;
        biblioteca[numLibros].autor = autor;
        biblioteca[numLibros].anio = anio;
        biblioteca[numLibros].disponible = true;
        numLibros++;
        cout<<"Libro '"<<titulo<<"' agregado correctamente"<<endl;
    }
    cout<<endl;
}

void mostrarLibros(){
    if (numLibros == 0) {
        cout<<"No hay libros en la biblioteca"<<endl;
    }else{
        for (int i = 0; i < numLibros; i++) {
            cout<<"Titulo: "<<biblioteca[i].titulo<<endl;
            cout<<"Autor: "<<biblioteca[i].autor<<endl;
            cout<<"Anio: "<<biblioteca[i].anio<<endl;
            cout<<"Disponible: ";
            if (biblioteca[i].disponible == true) {
                cout<<"Si"<<endl;
            } else {
                cout<<"No"<<endl;
            }
            cout<<endl;
        }
    }
}