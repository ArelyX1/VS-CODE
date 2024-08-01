#pragma once
#include "IFormaPago.h"

class Yape : public IFormaPago{
    private:
        void aumentarSaldo(float);
        void disminuirSaldo(float);
    public:
        Yape(Banco*);
        void depositar() override;
        void getInfo() override;
        void escanearQr(int, float, IFormaPago*);
        ~Yape();
};