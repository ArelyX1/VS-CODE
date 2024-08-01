#include "dependencias/ifInt.h"
#include "dependencias/ifFloat.h"
#include "dependencias/getStr.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void addClient();
void generalClientList();
void menu();
void foundId();
void foundCity();
void foundState();
int getFrequency(string);
void change();
void deleteClient();

void addClient(){
    try{
        ofstream file("clientes.csv", ios::app);
        if(!file.is_open()) {
            throw ofstream::failure("No se puede abrir el archivo clientes.csv");
        }

        file.exceptions(ofstream::failbit | ofstream::badbit);
        long int id;
        char ciudad[20], correo[100];
        string nombre;
        int estado;
        cout << "Ingrese el id: ";
        cin >> id;
        cout << "Ingrese el nombre: ";
        nombre = getSTR(100);
        cout << "Ingrese la ciudad: ";
        cin.getline(ciudad, 20);
        cout << "Ingrese el correo: ";
        cin.getline(correo, 100);
        cout << "Ingrese el estado 1 si 0 no ";
        estado = getInputInt();
        file << id << ";" << nombre << ";" << ciudad << ";" << correo << ";" << estado << endl;
        file.close();
        cout << "Se ha guardado el cliente" << endl;
    }
    catch(exception e){
        cout << "No se puede abrir el archivo" << endl;
    }
}

void menu(){
    short opcion;
    do{
        cout << "1. Agregar cliente" << endl;
        cout << "2. Listar clientes" << endl;
        cout << "3. Cambiar datos" << endl;
        cout << "4. Borrar cliente" << endl;
        cout << "5. Salir" << endl;
        cout << "Ingrese una opción: ";
        opcion = short(getInputInt());
        switch(opcion){
            case 1:
                addClient();
                break;
            case 5:
                cout << "Saliendo..." << endl;
                break;
        }
    }while(opcion != 5);
}

int main(){
    menu();
}