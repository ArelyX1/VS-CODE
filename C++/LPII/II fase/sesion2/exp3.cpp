#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Producto {
private:
    int codigo;
    string nombre;
    int cantidad;

public:
    Producto(int cod, string nom, int cant) : codigo(cod), nombre(nom), cantidad(cant) {}

    void getDetalles() const {
        cout << "Código: " << codigo << " | Nombre: " << nombre << " | Cantidad: " << cantidad << "\n";
    }

    void setDetalles(string nom, int cant, int cod) {
        nombre = nom;
        cantidad = cant;
        codigo = cod;
    }

    static int generarCodigo() {
        static int codigoActual = 1;
        return codigoActual++;
    }
};

class Inventario {
private:
    vector<Producto> productos;

public:
    void agregarProducto(const Producto& producto) {
        productos.push_back(producto);
    }

    void mostrarInventario() const {
        cout << "Inventario:\n";
        for (const auto& producto : productos) {
            producto.getDetalles();
        }
    }
};

int main() {
    Inventario inventario;

    Producto p1(Producto::generarCodigo(), "Papa", 10);
    Producto p2(Producto::generarCodigo(), "Tomate", 20);

    inventario.agregarProducto(p1);
    inventario.agregarProducto(p2);

    inventario.mostrarInventario();
}