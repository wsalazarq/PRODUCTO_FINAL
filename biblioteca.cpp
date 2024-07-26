#include "biblioteca.h"
#include <iostream>
using namespace std;

const int maxUsuarios = 100;
Usuario estudiantes[maxUsuarios];
Usuario administradores[maxUsuarios];

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