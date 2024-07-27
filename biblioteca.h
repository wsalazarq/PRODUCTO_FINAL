#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <iostream>
using namespace std;

struct Libro {
    string titulo;
    string autor;
    int anio;
    bool disponible;
};

struct Usuario {
    string nombre;
    bool esAdmin; 
    // true si es administrador y false si es estudiante
};

void agregarUsuario(string nombre, bool esAdmin);
void agregarLibro(string titulo, string autor, int anio);

#endif 
