#pragma once

#include <iostream>
#include <exception>
#include <limits>
using namespace std;

float getInputFloat(){
    do{
        float numero;
        try {
            cout << "Ingrese una opción: ----------------- ";
            cin >> numero;

            if(cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Entrada inválida. Por favor, intente de nuevo.");
            }
            return numero;
        } catch (const invalid_argument& ia) {
            cerr << ia.what() << endl;
        }
    }while (1);
}