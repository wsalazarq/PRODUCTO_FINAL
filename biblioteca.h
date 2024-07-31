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

struct Administradores{
    string nombre;
    string cargo;
    int edad;
    char sexo;
};

struct Estudiantes{
    string nombre;
    string carrera;
    string codigo;
    int edad;
    char sexo;
    int librosPrestados;
};

void agregarEstudiante(string, string, string, int, char);
void agregarAdministrador(string, string, int, char);
void agregarUsuario(string nombre, bool esAdmin);
void agregarLibro(string titulo, string autor, int anio);
bool libroExiste(string titulo);
void mostrarLibros();
void eliminarLibro(string titulo);
void inicializarLibros();
#endif 
