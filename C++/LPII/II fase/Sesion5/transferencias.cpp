#include <iostream>
#include <stdlib.h>
#include <vector>
#include <ctime>
#include <exception>
using namespace std;

int menu();
int menu_yape();
int menu_plin();
int menu_banco();
void crear_banco();

class Banco;
class Plin;
class Yape;
class CodigoQr{
    public:
        int qr;

        CodigoQr(){
            qr = (rand() % 9999) + 10000;
        }
};

class IFormaPago{
    protected:
        float capital = 0;
        Banco *cuenta_bancaria;
        const CodigoQr *codigo;

    public:
        virtual void aumentarSaldo(float monto) = 0;
        virtual void disminuirSaldo(float monto) = 0;
        virtual void depositar() = 0;
        virtual void escanearQr(int codigo, float cantidad, IFormaPago *otro) = 0;
        virtual void getInfo() = 0;
        int getCodigoqr(){
            return codigo -> qr;
        }
        virtual ~ IFormaPago(){}
};

class IDeposito{
    protected:
        float setMonto(){
            float *monto = 0;
            float temp;
            cout << "Ingrese el monto: ";
            cin >> temp;
            monto = new float(temp);
            return *monto;
        }
};

class Banco : IDeposito{
    private:
        float capital = 0;
        int dni;
    public:
        Banco(int dni){
            this -> capital = 0l;
            this -> dni = dni;
        }

        int getDni(){
            return dni;
        }

        void getInfo(){
            cout << "Capital del banco: " << capital << endl;
        }

        void depositarBanco(){
            capital += IDeposito::setMonto();
        }
        float depositar(){
            float temp = capital;
            capital -= IDeposito::setMonto();
            return temp - capital;
        }
};



class Yape : public IFormaPago{
    private:
        void aumentarSaldo(float cantidad) override {
            capital += cantidad;
        }
        void disminuirSaldo(float cantidad) override{
            capital -= cantidad;
        }
    public:

        Yape(Banco *_banco){
            this -> codigo = new CodigoQr();
            this -> cuenta_bancaria = _banco;
        }

        void depositar() override{
            capital = cuenta_bancaria->depositar();
        }

        void getInfo() override {
            cout << "Capital del yape: " << capital << endl;
            cuenta_bancaria -> getInfo();
            cout << "Código QR: " << codigo -> qr << endl;
        }

        void escanearQr(int codigo, float cantidad, IFormaPago *otro) override{
            if (codigo  == otro -> getCodigoqr()){
                aumentarSaldo(cantidad);
                otro -> disminuirSaldo(cantidad);
            }
            else{
                cout << "Código QR incorrecto" << endl;
            }
        }
            
};

class Plin : public IFormaPago{
    private:
        void aumentarSaldo(float cantidad) override {
            capital += cantidad;
        }
        void disminuirSaldo(float cantidad) override{
            capital -= cantidad;
        }
    public:

        Plin(Banco *_banco){
            this -> codigo = new CodigoQr();
            this -> cuenta_bancaria = _banco;
        }
        void depositar() override{
            capital = cuenta_bancaria->depositar();
        }

        void getInfo() override {
            cout << "Capital del yape: " << capital << endl;
            cuenta_bancaria -> getInfo();
            cout << "Código QR: " << codigo -> qr << endl;
        }

        void escanearQr(int codigo, float cantidad, IFormaPago *otro) override{
            if (codigo  == otro -> getCodigoqr()){
                aumentarSaldo(cantidad);
                otro -> disminuirSaldo(cantidad);
            }
            else{
                cout << "Código QR incorrecto" << endl;
            }
        }
};

vector<Banco*> bancos;
vector<Yape*> yapes;
vector<Plin*> plines;

int main(){
    srand(time(NULL));
    do{
        switch (menu())
        {
        case 1:
            char op;
            do{
                cout << "Ingrese el banco que desea concetar con Yape (S) Iniciar Sesion (N) Registrarse: ";
                cin >> op;
                if (op == 'S' || op == 's')  menu_yape();
                else if (op == 'N' || op == 'n' ) crear_banco();
                else continue;
                break;  
            } while (1);
        
        default:
            break;
        }
    } while (1);
    
    exit(0);
}
int menu(){
    cout << "Agregar Yape        ----------------- 1" << endl;
    cout << "Agregar Plin        ----------------- 2" << endl;
    cout << "Opciones Yape       ----------------- 3" << endl;
    cout << "Opciones Plin       ----------------- 4" << endl;
    cout << "Ingrese una opción: ----------------- ";
    int opcion;
    cin >> opcion;
    return opcion;
}

int menu_yape(){
    cout << "Ingrese su DNI para iniciar sesión: ";
    int dni;
    cin >> dni;
    for (int i = 0; i < bancos.size(); i++){
        if (bancos[i] -> getDni() == dni){
            Yape *yape = new Yape(bancos[i]);
            yapes.push_back(yape);
            break;
        }
    }
}

void crear_banco(){
    cout << "Ingrese su DNI para registrarse al banco: ";
    int dni;
    cin >> dni;
    Banco *banco = new Banco(dni);
    bancos.push_back(banco);
}