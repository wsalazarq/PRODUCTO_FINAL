#include "biblioteca.h"
#include <fstream>
#include <iostream>
using namespace std;

const int maxLibros = 100;
const int maxUsuarios = 100;

Administradores ADM[maxUsuarios];
Estudiantes EST[maxUsuarios];
Libro biblioteca[maxLibros];

int numLibros = 0;
int numEstudiantes = 0;
int numAdministradores = 0;

void registrarEstudiante(){
    if (numEstudiantes >= maxUsuarios){
        cout<<"No se pueden agregar mas estudiantes"<<endl;
    }else{
        cin.ignore(); 
        cout<<"Ingrese su nombre: "; getline(cin, EST[numEstudiantes].nombre); 
        cout<<"Ingrese su carrera: ";getline(cin, EST[numEstudiantes].carrera);
        do{
            cout<<"Ingrese su edad: ";cin>>EST[numEstudiantes].edad;
        } while (EST[numEstudiantes].edad <= 0);
        do{
            cout<<"Ingrese su sexo (M)(F): ";cin>>EST[numEstudiantes].sexo;
            EST[numEstudiantes].sexo = toupper(EST[numEstudiantes].sexo);
        } while (EST[numEstudiantes].sexo != 'M' && EST[numEstudiantes].sexo != 'F');

        cout<<"Ingrese un usuario: ";cin>>EST[numEstudiantes].usuario;
        cout<<"Ingrese su codigo universitario : ";cin>>EST[numEstudiantes].codigo;
        numEstudiantes++;
        cout<<"Estudiante registrado con exito"<<endl;
    }   
}

void registrarAdministrador(){
    if (numAdministradores >= maxUsuarios){
        cout<<"No se pueden agregar mas administradores"<<endl;
    }else{
        cin.ignore(); 
        cout<<"Ingrese su nombre: "; getline(cin, ADM[numAdministradores].nombre); 
        cout<<"Ingrese su cargo: ";getline(cin, ADM[numAdministradores].cargo);
        do{
            cout<<"Ingrese su edad: ";cin>>ADM[numAdministradores].edad;
        } while (ADM[numAdministradores].edad <= 0);
        do{
            cout<<"Ingrese su sexo (M)(F): ";cin>>ADM[numAdministradores].sexo;
            ADM[numAdministradores].sexo = toupper(ADM[numAdministradores].sexo);
        } while (ADM[numAdministradores].sexo != 'M' && ADM[numAdministradores].sexo != 'F');

        cout<<"Ingrese un usuario: ";cin>>ADM[numAdministradores].usuario;
        cout<<"Ingrese una contrasenia : ";cin>>ADM[numAdministradores].contrasena;
        numAdministradores++;
        cout<<"Administrador registrado con exito"<<endl;
    }   
}

bool iniciarSesionAdministrador(){
    string usuario, contrasena;
    cout<<"Ingrese el nombre de usuario: ";cin>>usuario;
    cout<<"Ingrese la contraseña: ";cin>>contrasena;

    for (int i = 0; i < numAdministradores; ++i) {
        if (ADM[i].usuario == usuario && ADM[i].contrasena == contrasena) {
            cout<<"Inicio de sesion como administrador exitoso"<<endl;
            return true;
        }
    }
    cout<<"Usuario o contrasenia incorrectos"<<endl;
    return false;
}

void mostrarDatosEstudiante(){
    if (numEstudiantes == 0){
        cout<<"No hay estudiantes"<<endl;
        cout<<endl;
    }else{
        cout<<"============================================="<<endl;
        cout<<"Lista de Estudiantes:"<<endl;
        cout<<"============================================="<<endl;
        for (int i = 0; i < numEstudiantes; i++) {
            cout<<"Estudiante "<<i + 1<<endl;
            cout<<"Nombre: "<<EST[i].nombre<<endl;
            cout<<"Carrera: "<<EST[i].carrera<<endl;
            cout<<"Codigo: "<<EST[i].codigo<<endl;
            cout<<"Edad: "<<EST[i].edad<<endl;
            cout<<"Sexo: "<<EST[i].sexo<<endl;
            cout<<"---------------------------------------------"<<endl;
        }
    }
    
}

void mostrarDatosAdministrador(){
    if (numAdministradores == 0){
        cout<<"No hay administradores"<<endl;
        cout<<endl;
    }else{
        cout<<"============================================="<<endl;
        cout<<"Lista de Administradores:"<<endl;
        cout<<"============================================="<<endl;
            for (int i = 0; i < numAdministradores; i++) {
            cout<<"Administrador "<<i + 1 << ":"<<endl;
            cout<<"Nombre: "<<ADM[i].nombre<<endl;
            cout<<"Cargo: "<<ADM[i].cargo<<endl;
            cout<<"Edad: "<<ADM[i].edad<<endl;
            cout<<"Sexo: "<<ADM[i].sexo<<endl;
            cout<<"---------------------------------------------" << endl;
        }
    }
    
}

void inicializarLibros(){
    if (numLibros == 0){
        biblioteca[numLibros++] = {"Cien anios de Soledad", "Gabriel Garcia Marquez", 1967, true};
        biblioteca[numLibros++] = {"Don Quijote de la Mancha", "Miguel de Cervantes", 1994, true};
        biblioteca[numLibros++] = {"Orgullo y Prejuicio", "Jane Austen", 2017, true};
        biblioteca[numLibros++] = {"Leyendas de Herbozonia", "Alberto Prieto Riquelme", 2024, true};
        biblioteca[numLibros++] = {"La ciudad gris y otros relatos", "Carlos de Tomas", 2011, true};
        biblioteca[numLibros++] = {"Cronicas de Ciudad Feliz", "Carlos Almira", 2011, true};
        biblioteca[numLibros++] = {"La utilidad de los deseos", "Esther Aparicio", 2015, true};
        biblioteca[numLibros++] = {"Los Fantasmas del Nuevo Mundo", "David Aramburo", 2014, true};
        biblioteca[numLibros++] = {"El Principito", "Antoine de Saint-Exupery", 1943, true};
        biblioteca[numLibros++] = {"Veinte poemas de amor y una cancion desesperada", "Pablo Neruda", 1924, true};
        biblioteca[numLibros++] = {"Cien sonetos de amor", "Pablo Neruda", 1959, true};    
        biblioteca[numLibros++] = {"La metamorfosis", "Franz Kafka", 1915, true};
        biblioteca[numLibros++] = {"El castillo", "Franz Kafka", 1926, true};
    }
    
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
            cout<<"---------------------------------------------"<<endl;
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

void cargarDatos(){
    ifstream archivoEstudiantes("estudiantes.txt");
    ifstream archivoAdministradores("administradores.txt");
    ifstream archivoLibros("libros.txt");

    if (archivoEstudiantes.is_open()) {
        while (archivoEstudiantes) {
            getline(archivoEstudiantes, EST[numEstudiantes].nombre);
            getline(archivoEstudiantes, EST[numEstudiantes].carrera);
            getline(archivoEstudiantes, EST[numEstudiantes].codigo);
            archivoEstudiantes>>EST[numEstudiantes].edad;
            archivoEstudiantes>>EST[numEstudiantes].sexo;
            archivoEstudiantes>>EST[numEstudiantes].numLibrosPrestados;
            archivoEstudiantes.ignore();

            for (int j = 0; j < EST[numEstudiantes].numLibrosPrestados; j++) {
                getline(archivoEstudiantes, EST[numEstudiantes].librosPrestados[j].titulo);
                getline(archivoEstudiantes, EST[numEstudiantes].librosPrestados[j].autor);
                archivoEstudiantes>>EST[numEstudiantes].librosPrestados[j].anio;
                archivoEstudiantes>>EST[numEstudiantes].librosPrestados[j].disponible;
                archivoEstudiantes.ignore();
            }

            if (archivoEstudiantes) {
                numEstudiantes++;
            }
        }
        archivoEstudiantes.close();
    }

    if (archivoAdministradores.is_open()) {
        while (archivoAdministradores){
            getline(archivoAdministradores, ADM[numAdministradores].nombre);
            getline(archivoAdministradores, ADM[numAdministradores].cargo);
            archivoAdministradores >> ADM[numAdministradores].edad;
            archivoAdministradores >> ADM[numAdministradores].sexo;
            archivoAdministradores.ignore();
            if (archivoAdministradores){
                numAdministradores++;
            }
        }
        archivoAdministradores.close();
    }

    if (archivoLibros.is_open()) {
        while (archivoLibros){
            getline(archivoLibros, biblioteca[numLibros].titulo);
            getline(archivoLibros, biblioteca[numLibros].autor);
            archivoLibros>>biblioteca[numLibros].anio;
            archivoLibros>>biblioteca[numLibros].disponible;
            archivoLibros.ignore();
            if (archivoLibros){
                numLibros++;
            }
        }
        archivoLibros.close();
    }
}

void guardarDatos(){
    ofstream archivoEstudiantes("estudiantes.txt");
    ofstream archivoAdministradores("administradores.txt");
    ofstream archivoLibros("libros.txt");
    
    if (archivoEstudiantes.is_open()) {
        for (int i = 0; i < numEstudiantes; i++) {
            archivoEstudiantes << EST[i].nombre << endl
                               << EST[i].carrera << endl
                               << EST[i].codigo << endl
                               << EST[i].edad << endl
                               << EST[i].sexo << endl
                               << EST[i].numLibrosPrestados << endl;

            for (int j = 0; j < EST[i].numLibrosPrestados; j++) {
                archivoEstudiantes << EST[i].librosPrestados[j].titulo << endl
                                   << EST[i].librosPrestados[j].autor << endl
                                   << EST[i].librosPrestados[j].anio << endl
                                   << EST[i].librosPrestados[j].disponible << endl;
            }
        }
        archivoEstudiantes.close();
    }

    if (archivoAdministradores.is_open()) {
        for (int i = 0; i < numAdministradores; i++) {
            archivoAdministradores<<ADM[i].nombre<<endl
                                   <<ADM[i].cargo<<endl
                                   <<ADM[i].edad<<endl
                                   <<ADM[i].sexo<<endl;
        }
        archivoAdministradores.close();
    }

    if (archivoLibros.is_open()) {
        for (int i = 0; i < numLibros; i++) {
            archivoLibros<<biblioteca[i].titulo<<endl
                          <<biblioteca[i].autor<<endl
                          <<biblioteca[i].anio<<endl
                          <<biblioteca[i].disponible<<endl;
        }
        archivoLibros.close();
    }
}
void solicitarLibro(string codigoEstudiante, string titulo) {
    for (int i = 0; i < numEstudiantes; i++) {
        if (EST[i].codigo == codigoEstudiante) {
            if (EST[i].numLibrosPrestados >= 10) {
                cout<<"El estudiante ya tiene el maximo de 10 libros prestados"<<endl;
            }else{
                for (int j = 0; j < numLibros; j++) {
                    if (biblioteca[j].titulo == titulo && biblioteca[j].disponible) {
                        biblioteca[j].disponible = false;
                        EST[i].librosPrestados[EST[i].numLibrosPrestados] = biblioteca[j];
                        EST[i].numLibrosPrestados++;
                        cout<<"Libro '"<<titulo << "' prestado a " <<EST[i].nombre<<endl;
                        return;
                    }
                }
            }
            cout<<"Libro no disponible"<<endl;
            return;
        }
    }
    cout<<"Estudiante no encontrado"<<endl;
}
void devolverLibro(string codigoEstudiante,string titulo) {
    
    for (int i = 0; i < numEstudiantes; i++) {
        if (EST[i].codigo == codigoEstudiante) {
        
            for (int j = 0; j < EST[i].numLibrosPrestados; j++) {
                if (EST[i].librosPrestados[j].titulo == titulo) {
                   
                    for (int k = 0; k < numLibros; k++) {
                        if (biblioteca[k].titulo == titulo) {
                            biblioteca[k].disponible = true;
                            break;
                        }
                    }

                    EST[i].numLibrosPrestados--;
                    EST[i].librosPrestados[j] = EST[i].librosPrestados[EST[i].numLibrosPrestados];

                    cout<<"Libro '" <<titulo<< "' devuelto correctamente" << endl;
                    return;
                }
            }

            cout<<"El estudiante no tiene prestado el libro '"<<titulo<<endl;
            return;
        }
    }

    cout<<"Estudiante no encontrado"<<endl;
}