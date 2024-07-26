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
    
    return 0;
}