#pragma once
#include "IDeposito.h"

class Banco : protected IDeposito{
    private:
        float capital;
        int dni;
    public:
        Banco(float, int);
        void getInfo();
        void depositarBanco();
        float depositar();
};