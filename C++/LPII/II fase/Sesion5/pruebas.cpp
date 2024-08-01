#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <exception>
using namespace std;

void menu();

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
        float capital;
        int dni;
    public:
        Banco(float capital, int dni){
            this -> capital = capital;
            this -> dni = dni;
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