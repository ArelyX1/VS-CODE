#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Producto {
    int codigo;
    string nombre;
    int cantidad;
    int precio;
    string descripcion;
};

vector<Producto> inventario;

void agregarProducto(int codigo, string nombre, int cantidad, int precio, string descripcion) {
    Producto nuevoProducto = {codigo, nombre, cantidad, precio, descripcion};
    inventario.push_back(nuevoProducto);
}

void mostrarInformacionProducto(int codigo) {
    for (const auto& producto : inventario) {
        if (producto.codigo == codigo) {
            cout << "Código: " << producto.codigo << endl;
            cout << "Nombre: " << producto.nombre << endl;
            cout << "Cantidad: " << producto.cantidad << endl;
            cout << "Precio: " << producto.precio << endl;
            cout << "Descripción: " << producto.descripcion << endl;
            return;
        }
    }
    cout << "Producto no encontrado." << endl;
}

void actualizarInformacionProducto(int codigo, string nuevoNombre, int nuevaCantidad, int nuevoPrecio, string nuevaDescripcion) {
    for (auto& producto : inventario) {
        if (producto.codigo == codigo) {
            producto.nombre = nuevoNombre;
            producto.cantidad = nuevaCantidad;
            producto.precio = nuevoPrecio;
            producto.descripcion = nuevaDescripcion;
            cout << "Información actualizada correctamente." << endl;
            return;
        }
    }
    cout << "Producto no encontrado." << endl;
}

int main() {
    agregarProducto(1, "Producto 1", 10, 50, "Descripción del Producto 1");
    agregarProducto(2, "Producto 2", 20, 100, "Descripción del Producto 2");

    mostrarInformacionProducto(1);

    actualizarInformacionProducto(2, "Nuevo Producto 2", 30, 120, "Nueva Descripción del Producto 2");

    return 0;
}