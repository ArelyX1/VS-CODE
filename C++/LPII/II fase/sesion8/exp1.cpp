#include <iostream>
#include <cmath>
using namespace std;

// Clase abstracta "Figura"
class Figura {
public:
    virtual double calcularArea() = 0; // Método abstracto
};

// Clase derivada "Círculo"
class Circulo : public Figura {
private:
    double radio;

public:
    Circulo(double r) : radio(r) {}

    double calcularArea() override {
        return 3.14159 * radio * radio;
    }
};

// Clase derivada "Rectángulo"
class Rectangulo : public Figura {
private:
    double base, altura;

public:
    Rectangulo(double b, double h) : base(b), altura(h) {}

    double calcularArea() override {
        return base * altura;
    }
};

// Clase derivada "Triángulo"
class Triangulo : public Figura {
private:
    double base, altura;

public:
    Triangulo(double b, double h) : base(b), altura(h) {}

    double calcularArea() override {
        return 0.5 * base * altura;
    }
};

// Clase derivada "Cuadrado"
class Cuadrado : public Figura {
private:
    double lado;

public:
    Cuadrado(double l) : lado(l) {}

    double calcularArea() override {
        return lado * lado;
    }
};

// Clase derivada "Pentágono"
class Pentagono : public Figura {
private:
    double lado;

public:
    Pentagono(double l) : lado(l) {}

    double calcularArea() override {
        return (5 * lado * lado) / (4 * tan(3.14159 / 5.0));
    }
};

int main() {
    string figura;
    double radio, base, altura, lado;

    cout << "Elige una figura (Círculo, Rectángulo, Triángulo, Cuadrado, Pentágono): ";
    cin >> figura;  

    if (figura == "Círculo") {
        cout << "Introduce el radio: ";
        cin >> radio;
        Circulo c(radio);
        cout << "El área del círculo es: " << c.calcularArea() << endl;
    } else if (figura == "Rectángulo") {
        cout << "Introduce la base y la altura: ";
        cin >> base >> altura;
        Rectangulo r(base, altura);
        cout << "El área del rectángulo es: " << r.calcularArea() << endl;
    } else if (figura == "Triángulo") {
        cout << "Introduce la base y la altura: ";
        cin >> base >> altura;
        Triangulo t(base, altura);
        cout << "El área del triángulo es: " << t.calcularArea() << endl;
    } else if (figura == "Cuadrado") {
        cout << "Introduce el lado: ";
        cin >> lado;
        Cuadrado cu(lado);
        cout << "El área del cuadrado es: " << cu.calcularArea() << endl;
    } else if (figura == "Pentágono") {
        cout << "Introduce el lado: ";
        cin >> lado;
        Pentagono p(lado);
        cout << "El área del pentágono es: " << p.calcularArea() << endl;
    } else {
        cout << "Figura no válida." << endl;
    }

    return 0;
}