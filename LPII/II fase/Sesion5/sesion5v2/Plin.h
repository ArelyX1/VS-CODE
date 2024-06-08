#pragma once
#include "IFormaPago.h"

class Plin : public IFormaPago{
    private:
        void aumentarSaldo(float);
        void disminuirSaldo(float);
    public:
        Plin(Banco*);
        void depositar() override;
        void getInfo() override;
        void escanearQr(int, float, IFormaPago*);
        ~Plin();
};