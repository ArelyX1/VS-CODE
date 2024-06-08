#include <iostream>

using namespace std;

// Clase base "Vehículo"
class Vehiculo {
public:
    void acelerar() {
        cout << "Acelerando el vehículo" << endl;
    }
};

// Clase derivada "Coche" que hereda de "Vehículo"
class Coche : public Vehiculo {
public:
    void acelerar() {
        cout << "Acelerando el coche" << endl;
    }

    void encenderLuces() {
        cout << "Luces del coche encendidas" << endl;
    }
};

// Clase derivada "Motocicleta" que hereda de "Vehículo"
class Motocicleta : public Vehiculo {
public:
    void acelerar() {
        cout << "Acelerando la motocicleta" << endl;
    }
};

int main() {
    // Crear una instancia de la clase "Coche"
    Coche coche;
    coche.acelerar();  // Debe imprimir "Acelerando el coche"
    coche.encenderLuces();  // Debe imprimir "Luces del coche encendidas"

    // Crear una instancia de la clase "Motocicleta"
    Motocicleta motocicleta;
    motocicleta.acelerar();  // Debe imprimir "Acelerando la motocicleta"

    return 0;
}