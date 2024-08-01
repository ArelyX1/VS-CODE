#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <set>
#include <algorithm>
using namespace std;

class Producto {
private:
    static std::set<int> codigos;
    int codigo;
    string nombre;
    int cantidad;
    int precio;
    string descripcion;
public:
    Producto(int, string, int, string);
    void getDetalles();
    void setDetalles(string, int, int, string);
    static int generarCodigo();
    bool operator==(const Producto& p) const {
        return codigo == p.codigo;
    }
};

set<int> Producto::codigos; //Inicialización de los codigos

Producto::Producto(int precio, string nombre, int cantidad, string descripcion) {
    this->codigo = generarCodigo();
    this->nombre = nombre;
    this->cantidad = cantidad;
    this->precio = precio;
    this->descripcion = descripcion;
}

void Producto::getDetalles() {
    cout << "Código del producto: " << codigo << endl;
    cout << "Nombre del producto: " << nombre << endl;
    cout << "Precio del producto: " << precio << endl;
    cout << "Descripción del producto: " << descripcion << endl;
}

void Producto::setDetalles(string nombre, int cantidad, int precio, string descripcion) {
    this->nombre = nombre;
    this->cantidad = cantidad;
    this->precio = precio;
    this->descripcion = descripcion;
}

int Producto::generarCodigo() {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dis(1000, 10000);

    int codigo;
    do {
        codigo = dis(gen);
    } while (codigos.find(codigo) != codigos.end());
    codigos.insert(codigo);
    return codigo;
}

class Inventario {
private:
    vector<Producto> productos;
public:
    Inventario(vector<Producto> productos);
    vector<Producto> getProductos();
    void setProductos(vector<Producto>);
    void agregarProducto(Producto);
    void eliminarProducto(Producto);
    void mostrarProductos() {
        for (Producto producto : productos) {
            producto.getDetalles();
        }
    }
};

Inventario::Inventario(vector<Producto> productos) {
    this->productos = productos;
}

vector<Producto> Inventario::getProductos() {
    return productos;
}

void Inventario::setProductos(vector<Producto> productos) {
    this->productos = productos;
}

void Inventario::agregarProducto(Producto producto) {
    productos.push_back(producto);
}

void Inventario::eliminarProducto(Producto producto) {
    productos.erase(remove(productos.begin(), productos.end(), producto), productos.end());
}

int main() {
    Producto producto(100, "Producto 1", 100, "Este es el producto 1");
    producto.getDetalles();
    
    producto.setDetalles("Producto 1 modificado", 200, 150, "Este es el producto 1 modificado");
    producto.getDetalles();
    
    Producto producto2(100, "Producto 2", 100, "Este es el producto 2");
    producto2.getDetalles();
    
    producto2.setDetalles("Producto 2 modificado", 300, 250, "Este es el producto 2 modificado");
    producto2.getDetalles();

    vector<Producto> productos = {producto, producto2};
    Inventario inventario(productos);
    inventario.eliminarProducto(producto);

    producto2.setDetalles("Producto 2 modificado 22", 300, 250, "Este es el producto 2 modificado");
    cout << "Mostrando un producto del inventario ----------------------------------" << endl;
    inventario.mostrarProductos();
    //cout << "Intente agregale el menu y meterle en html pero ya seria enfermizo"; 
}