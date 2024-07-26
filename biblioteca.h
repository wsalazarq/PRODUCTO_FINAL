#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <iostream>
using namespace std;

struct Usuario {
    string nombre;
    bool esAdmin; 
    // true si es administrador y false si es estudiante
};

void agregarUsuario(string nombre, bool esAdmin);

#endif 
