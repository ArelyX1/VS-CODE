#pragma once
#include "Banco.h"
#include "CodigoQr.h"

class IFormaPago{
    protected:
        float capital = 0;
        Banco *cuenta_bancaria;
        const CodigoQr *codigo;
    public:
        virtual void aumentarSaldo(float) = 0;
        virtual void disminuirSaldo(float) = 0;
        virtual void depositar() = 0;
        virtual void escanearQr(int, float, IFormaPago*) = 0;
        virtual void getInfo() = 0;
        int getCodigoqr(){
            return codigo -> qr;
        }
        virtual ~ IFormaPago(){}
};