#include <iostream>
#include <cmath>
using namespace std;

// Clase abstracta "Forma"
class Forma {
public:
    virtual double calcularPerimetro() = 0; // Método abstracto
};

// Clase derivada "Círculo"
class Circulo : public Forma {
private:
    double radio;

public:
    Circulo(double r) : radio(r) {}

    double calcularPerimetro() override {
        return 2 * 3.14159 * radio;
    }
};

// Clase derivada "Rectángulo"
class Rectangulo : public Forma {
private:
    double base, altura;

public:
    Rectangulo(double b, double h) : base(b), altura(h) {}

    double calcularPerimetro() override {
        return 2 * (base + altura);
    }
};

// Clase derivada "Triángulo"
class Triangulo : public Forma {
private:
    double base, altura;

public:
    Triangulo(double b, double h) : base(b), altura(h) {}

    double calcularPerimetro() override {
        return base + altura + sqrt(base * base + altura * altura);
    }
};

int main() {
    string figura;
    double radio, base, altura;

    cout << "Elige una figura (Círculo, Rectángulo, Triángulo): ";
    cin >> figura;

    if (figura == "Círculo") {
        cout << "Introduce el radio: ";
        cin >> radio;
        Circulo c(radio);
        cout << "El perímetro del círculo es: " << c.calcularPerimetro() << endl;
    } else if (figura == "Rectángulo") {
        cout << "Introduce la base y la altura: ";
        cin >> base >> altura;
        Rectangulo r(base, altura);
        cout << "El perímetro del rectángulo es: " << r.calcularPerimetro() << endl;
    } else if (figura == "Triángulo") {
        cout << "Introduce la base y la altura: ";
        cin >> base >> altura;
        Triangulo t(base, altura);
        cout << "El perímetro del triángulo es: " << t.calcularPerimetro() << endl;
    } else {
        cout << "Figura no válida." << endl;
    }

    return 0;
}