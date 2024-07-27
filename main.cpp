#include <iostream>
#include "biblioteca.h"
using namespace std;

int main(){
    
    string nombre;
    char tipoUsuario;
    bool esAdmin;
    bool usuarioValido = false;

    cin.ignore(); cout<<"Ingrese su nombre: "; getline(cin, nombre);  
        while (usuarioValido == false){
        cout<<"Ingrese el tipo de usuario (A para administrador, E para estudiante): ";cin>>tipoUsuario;
        
        if (tipoUsuario == 'A' || tipoUsuario == 'a'){
            esAdmin = true;
            usuarioValido = true;
        }else if (tipoUsuario == 'E' || tipoUsuario == 'e'){
            esAdmin = false;
            usuarioValido = true;
        }else{
            cout<<"La entrada no es valida"<<endl;
        }
    }

    agregarUsuario(nombre, esAdmin);
    
    int op;
    cout<<"=================================================="<<endl;
    cout<<"Bienvenido a la BIBLIOTECA "<<nombre<<endl;
    cout<<"=================================================="<<endl;    

    do{
        cout<<"Menu de opciones:"<<endl;
        if (esAdmin == true){
            cout<<"1. Agregar libro"<<endl;
        }
        cout<<"0. Salir"<<endl;
        cout<<"Seleccione una opcion: ";cin>>op;

        string titulo, autor;
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
                break;
            case 0:
                cout<<"Saliendo..."<<endl;
                system("pause");
                break;
            default:
                cout<<"Opcion invalida, intente de nuevo."<<endl;
                system("pause");
                break;
        }

    } while (op != 0);

    return 0;
}