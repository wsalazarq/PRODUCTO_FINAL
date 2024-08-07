#include <iostream>
#include "biblioteca.h"
#include <cctype>
using namespace std;

int main(){
    char tipoUsuario;
    bool esAdmin;
    bool usuarioValido = false;
    int opInicio;
    
    cargarDatos();

   do {
        cout<<"1. Iniciar Sesion"<<endl;
        cout<<"2. Registrarse"<<endl;
        cout<<"3. Salir"<<endl;
        cout<<"Elija una opcion: ";cin>>opInicio;

        switch (opInicio) {
            case 1:
                cout<<"Ingrese el tipo de usuario (A para administrador, E para estudiante): ";
                cin>>tipoUsuario;
                tipoUsuario = toupper(tipoUsuario);

                if (tipoUsuario == 'A') {
                    usuarioValido = iniciarSesionAdministrador();
                    esAdmin = usuarioValido;
                } else if (tipoUsuario == 'E') {
                    usuarioValido = iniciarSesionEstudiante();
                    esAdmin = !usuarioValido;
                } else {
                    cout << "La entrada no es valida" << endl;
                }
                break;
            case 2:
                cout<<"Ingrese el tipo de usuario (A para administrador, E para estudiante): ";
                cin>>tipoUsuario;
                tipoUsuario = toupper(tipoUsuario);

                if (tipoUsuario == 'A') {
                    registrarAdministrador();
                    usuarioValido = true;
                    esAdmin = true;
                } else if (tipoUsuario == 'E') {
                    registrarEstudiante();
                    usuarioValido = true;
                    esAdmin = false;
                } else {
                    cout<<"La entrada no es valida"<<endl;
                }
                break;
            case 3:
                cout << "Saliendo..." << endl;
                guardarDatos();
                return 0;
            default:
                cout<<"Opcion invalida, intente de nuevo"<<endl;
                break;
        }
    } while (!usuarioValido);

    int op;
    cout<<"=================================================="<<endl;
    cout<<"         Bienvenido a la BIBLIOTECA "<<endl;
    cout<<"=================================================="<<endl;    

    inicializarLibros();
    do{
        cout<<"Menu de opciones:"<<endl;
        if (esAdmin == true){
            cout<<"1. Agregar libro"<<endl;
            cout<<"2. Eliminar libro"<<endl;
            cout<<"3. Mostrar libros"<<endl;
            cout<<"4. Mostrar datos"<<endl;
        }else{
            cout<<"3. Mostrar libros"<<endl;
            cout<<"4. Mostrar datos"<<endl;
            cout<<"5. Solicitar libro"<<endl;
            cout<<"6. Devolver libro"<<endl;
        }
        cout<<"0. Salir"<<endl;
        cout<<"Seleccione una opcion: ";cin>>op;

        string titulo, autor, codigo;
        int anio;

        switch (op){
            case 1:
                if (esAdmin == true){
                    cin.ignore(); 
                    cout<<"Ingrese el titulo del libro: "; getline(cin, titulo);
                    cout<<"Ingrese el autor del libro: "; getline(cin, autor);
                    cout<<"Ingrese el anio del libro: ";cin>>anio;

                    agregarLibro(titulo, autor, anio);
                }else{
                    cout<<"Opcion invalida, intente de nuevo."<<endl;
                }
                cout<<endl;
                break;
            case 2:
                if (esAdmin == true){
                    cin.ignore(); cout<<"Ingrese el titulo del libro que desea eliminar: "; getline(cin, titulo);
                    eliminarLibro(titulo);
                }else{
                    cout<<"Opcion invalida, intente de nuevo"<<endl;
                }
                break;
            case 3:
                mostrarLibros();
                break;
            case 4:
                char opDatos;
                if (esAdmin == true){
                    cout<<"Ingrese los datos del tipo de usuario que desea mostrar (A para administrador, E para estudiante): ";cin>>opDatos;
                    opDatos = toupper(opDatos);

                    if (opDatos == 'A'){
                        mostrarDatosAdministrador();
                    } else if (opDatos == 'E'){
                        mostrarDatosEstudiante();
                    } else {
                        cout<<"Opcion invalida, intente de nuevo"<<endl;
                    }
                }else{
                    mostrarDatosEstudiante();
                }
                break;
            case 5:
                cin.ignore();
                cout<<"Ingrese el titulo del libro que desea solicitar: "; getline(cin, titulo);
                cout<<"Ingrese el codigo del estudiante: ";cin>>codigo;
                solicitarLibro(codigo, titulo);
                break;
            case 6:
                cin.ignore();
                cout<<"Ingrese el titulo del libro que desea devolver: "; getline(cin, titulo);
                cout<<"Ingrese el codigo del estudiante: ";cin>>codigo;
                devolverLibro(codigo, titulo);
                break;
            case 0:
                cout<<"Saliendo..."<<endl;
                guardarDatos();
                break;
            default:
                cout<<"Opcion invalida, intente de nuevo."<<endl;
                cout<<endl;
                break;
        }

    } while (op != 0);

    return 0;
}