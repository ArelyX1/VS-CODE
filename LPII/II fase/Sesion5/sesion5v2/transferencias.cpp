#include "IFormaPago.h"
#include "Yape.h"
#include "IDeposito.h"
#include "Plin.h"
#include "Banco.h"
#include "CodigoQr.h"

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <ctime>
#include <exception>

using namespace std;

void menu();
class Banco;
class Plin;
class Yape;

float IDeposito::setMonto(){
    float *monto = 0;
    float temp;
    cout << "Ingrese el monto: ";
    cin >> temp;
    monto = new float(temp);
    return *monto;
}

Banco::Banco(float capital, int dni){
    this -> capital = capital;
    this -> dni = dni;
}
void Banco::getInfo(){
    cout << "Banco Pepe" << endl;
    cout << "DNI: " << dni << endl;
    cout << "Capital: " << capital << endl;
}
void Banco::depositarBanco(){
    capital += setMonto();
}
float Banco::depositar(){
    float temp = capital;
    capital -=IDeposito::setMonto();
    return temp - capital;
}
Yape::Yape(Banco *banco){
    this -> cuenta_bancaria = banco;
    this -> codigo = new CodigoQr();
}
void Yape::aumentarSaldo(float monto){
    capital += monto;
}
void Yape::disminuirSaldo(float monto){
    capital -= monto;
}
void Yape::depositar(){
    capital = cuenta_bancaria -> depositar();
}
void Yape::getInfo(){
    cout << "Yape" << endl;
    cout << "Codigo QR: " << codigo -> qr << endl;
    cout << "Capital: " << capital << endl;
}
void Yape::escanearQr(int codigo, float cantidad, IFormaPago *otro){
    if(codigo == otro -> getCodigoqr()){
        otro -> aumentarSaldo(cantidad);
        disminuirSaldo(cantidad);
    }
    else{
        cout << "Codigo QR incorrecto" << endl;
    }
}
Yape::~Yape(){
    delete codigo;
}
Plin::Plin(Banco *banco){
    this -> cuenta_bancaria = banco;
    this -> codigo = new CodigoQr();
}
void Plin::aumentarSaldo(float monto){
    capital += monto;
}
void Plin::disminuirSaldo(float monto){
    capital -= monto;
}
void Plin::depositar(){
    capital = cuenta_bancaria -> depositar();
}
void Plin::getInfo(){
    cout << "Plin" << endl;
    cout << "Codigo QR: " << codigo -> qr << endl;
    cout << "Capital: " << capital << endl;
}
void Plin::escanearQr(int codigo, float cantidad, IFormaPago *otro){
    if(codigo == otro -> getCodigoqr()){
        otro -> aumentarSaldo(cantidad);
        disminuirSaldo(cantidad);
    }
    else{
        cout << "Codigo QR incorrecto" << endl;
    }
}
Plin::~Plin(){
    delete codigo;
}

int main(){
    srand(time(NULL));
    Yape *yape = new Yape(new Banco(1000, 3379));
    Yape *yape2 = new Yape(new Banco(1000, 6078));
    yape -> depositar();
    yape2 -> depositar();

    yape -> getInfo();
    yape2 -> getInfo();

    int codigo;
    cout << "Ingrese el código QR de la otra cuenta (2): ";
    cin >> codigo;
    cout << "Ingrese la cantidad a transferir: ";
    float cantidad;
    cin >> cantidad;
    yape -> escanearQr(codigo, cantidad, yape2);
    cout << "__________________\n"; 
    yape -> getInfo();
    yape2 -> getInfo();

    exit(0);
}