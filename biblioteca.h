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
    string usuario;
    string contrasena;
};

struct Estudiantes{
    string nombre;
    string carrera;
    string codigo;
    string usuario;
    int edad;
    char sexo;
    Libro librosPrestados[10];
    int numLibrosPrestados = 0;
};

void registrarEstudiante();
void registrarAdministrador();
void mostrarDatosEstudiante();
void mostrarDatosAdministrador();
void agregarLibro(string titulo, string autor, int anio);
bool libroExiste(string titulo);
void mostrarLibros();
void eliminarLibro(string titulo);
void inicializarLibros();
void cargarDatos();
void guardarDatos();
void solicitarLibro(string , string);
void devolverLibro(string , string );
#endif 
