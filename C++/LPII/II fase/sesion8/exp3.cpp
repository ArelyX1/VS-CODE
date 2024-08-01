#include <iostream>
#include <string>
using namespace std;

// Clase base "Animal"
class Animal {
public:
    virtual string hacerSonido() {
        return "El animal hace un sonido.";
    }
};

// Clase derivada "Perro"
class Perro : public Animal {
public:
    string hacerSonido() override {
        return "El perro ladra.";
    }
};

// Clase derivada "Gato"
class Gato : public Animal {
public:
    string hacerSonido() override {
        return "El gato maúlla.";
    }
};

// Clase derivada "Vaca"
class Vaca : public Animal {
public:
    string hacerSonido() override {
        return "La vaca muuge.";
    }
};

int main() {
    // Crear instancias de diferentes animales
    Animal* animal1 = new Perro();
    Animal* animal2 = new Gato();
    Animal* animal3 = new Vaca();

    // Llamar al método "hacerSonido()" en cada animal
    cout << animal1->hacerSonido() << endl; // El perro ladra.
    cout << animal2->hacerSonido() << endl; // El gato maúlla.
    cout << animal3->hacerSonido() << endl; // La vaca muuge.

    // Liberar la memoria de los objetos
    delete animal1;
    delete animal2;
    delete animal3;

    return 0;
}