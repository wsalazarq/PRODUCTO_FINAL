#include "biblioteca.h"
#include <iostream>
using namespace std;

const int maxLibros = 100;
const int maxUsuarios = 100;

Estudiantes EST[maxUsuarios];
Libro biblioteca[maxLibros];

int numLibros = 0;
int numEstudiantes = 0;
int numAdministradores = 0;

void agregarEstudiante(string nombre, string carrera, string codigo, int edad, char sexo){
    if (numEstudiantes < maxUsuarios){
        if (edad <= 0){
            cout<<"La edad tiene que ser un valor positivo"<<endl;
        }else if(sexo == 'M' || sexo == 'm' || sexo == 'F' || sexo == 'f'){
            EST[numEstudiantes].nombre = nombre;
            EST[numEstudiantes].carrera = carrera;
            EST[numEstudiantes].codigo = codigo;
            EST[numEstudiantes].edad = edad;
            EST[numEstudiantes].sexo = sexo;
            numEstudiantes++;
            cout<<"Estudiante agregado correctamente"<<endl;
        }else{
            cout<<"Ingrese un valor correcto en el sexo"<<endl;
        }
    }else {
        cout<<"No se puede agregar mas estudiantes"<<endl;
    } 
}

void inicializarLibros(){
    biblioteca[numLibros++] = {"Cien anios de Soledad", "Gabriel Garcia Marquez", 1967, true};
    biblioteca[numLibros++] = {"Don Quijote de la Mancha", "Miguel de Cervantes", 1994, true};
    biblioteca[numLibros++] = {"Orgullo y Prejuicio", "Jane Austen", 2017, true};
    biblioteca[numLibros++] = {"Leyendas de Herbozonia", "Alberto Prieto Riquelme", 2024, true};
    biblioteca[numLibros++] = {"La ciudad gris y otros relatos", "Carlos de Tomas", 2011, true};
    biblioteca[numLibros++] = {"Cronicas de Ciudad Feliz", "Carlos Almira", 2011, true};
    biblioteca[numLibros++] = {"La utilidad de los deseos", "Esther Aparicio", 2015, true};
    biblioteca[numLibros++] = {"Los Fantasmas del Nuevo Mundo", "David Aramburo", 2014, true};
    biblioteca[numLibros++] = {"El Principito", "Antoine de Saint-Exupery", 1943, true};
    biblioteca[numLibros++] = {"Veinte poemas de amor y una canción desesperada", "Pablo Neruda", 1924, true};
    biblioteca[numLibros++] = {"Cien sonetos de amor", "Pablo Neruda", 1959, true};    
    biblioteca[numLibros++] = {"La metamorfosis", "Franz Kafka", 1915, true};
    biblioteca[numLibros++] = {"El castillo", "Franz Kafka", 1926, true};
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
        cout<<endl;
    }else{
        cout<<"En la biblioteca hay: "<<numLibros<<" libros"<<endl;
        cout<<"============================================="<<endl;
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

void eliminarLibro(string titulo){
    bool encontrado = false;

    for (int i = 0; i < numLibros; i++) {
        if (biblioteca[i].titulo == titulo) {
            for (int j = i; j < numLibros - 1; j++) {
                biblioteca[j] = biblioteca[j + 1];
            }
            numLibros--;
            encontrado = true;
            cout<<"Libro eliminado correctamente"<<endl;
            
        }
    }
    if (encontrado == false) {
        cout<<"Libro no encontrado"<<endl;
    }
    cout<<endl;
}