#include "dependencias/ifInt.h"
#include "dependencias/ifFloat.h"
#include "dependencias/getStr.h"
#include "dependencias/sha256.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>

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
class IProducto{
    protected:
        int id;
        string nombre;
        float precio;
        virtual void setData(){cout <<"?";}
};
class Libro: protected IProducto{
    public:
        char autor[100];
        
        Libro(int id, string nombre, float precio, string _autor): IProducto(){
            this->id = id;
            this->nombre = nombre;
            this->precio = precio;
            strncpy(autor, _autor.c_str(), sizeof(autor));
            this -> autor[sizeof(autor) - 1] = '\0';
        }
        void setData(){
            try{
                ofstream file("clientes.csv", ios::app);
                if(!file.is_open()) {
                    throw ofstream::failure("No se puede abrir el archivo clientes.csv");
                }
                file.exceptions(ofstream::failbit | ofstream::badbit);
                file << id << ";" << nombre << ";" << precio << ";" << autor << endl;
                file.close();
                cout << "Se ha guardado el cliente" << endl;
            }catch(exception e){
                cout << "No se puede abrir el archivo" << endl;
            }
        }
};
class Electronico: protected IProducto{
    public:
        char modelo[100];
        
        Electronico(int id, string nombre, float precio, string _modelo): IProducto(){
            this->id = id;
            this->nombre = nombre;
            this->precio = precio;
            strncpy(modelo, _modelo.c_str(), sizeof(modelo));
            this -> modelo[sizeof(modelo) - 1] = '\0';
        }
        void setData(){
            try{
                ofstream file("clientes.csv", ios::app);
                if(!file.is_open()) {
                    throw ofstream::failure("No se puede abrir el archivo clientes.csv");
                }
                file.exceptions(ofstream::failbit | ofstream::badbit);
                file << id << ";" << nombre << ";" << precio << ";" << modelo << endl;
                file.close();
                cout << "Se ha guardado el cliente" << endl;
            }catch(exception e){
                cout << "No se puede abrir el archivo" << endl;
            }
        }
};
class Ropa: protected IProducto{
    public:
        char color[100];
        
        Ropa(int id, string nombre, float precio, string _color): IProducto(){
            this->id = id;
            this->nombre = nombre;
            this->precio = precio;
            strncpy(color, _color.c_str(), sizeof(color));
            this -> color[sizeof(color) - 1] = '\0';
        }
        void setData(){
            try{
                ofstream file("clientes.csv", ios::app);
                if(!file.is_open()) {
                    throw ofstream::failure("No se puede abrir el archivo clientes.csv");
                }
                file.exceptions(ofstream::failbit | ofstream::badbit);
                file << id << ";" << nombre << ";" << precio << ";" << color << endl;
                file.close();
                cout << "Se ha guardado el cliente" << endl;
            }catch(exception e){
                cout << "No se puede abrir el archivo" << endl;
            }
        }
};

int main(){
    Ropa ropa(1, "ropa", 10.0, "azul");
    ropa.setData();
}