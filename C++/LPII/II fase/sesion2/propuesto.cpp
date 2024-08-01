#include <iostream>
#include <vector>
using namespace std;


class Producto {
private:
    string nombre;
    int cantidadInventario;
    double precio;


public:
    Producto(string _nombre, int _cantidadInventario, double _precio) : nombre(_nombre), cantidadInventario(_cantidadInventario), precio(_precio) {}


    string getNombre() const { return nombre; }
    int getCantidadInventario() const { return cantidadInventario; }
    double getPrecio() const { return precio; }


    void mostrarInformacion() const {
        cout << "Nombre: " << nombre << endl;
        cout << "Cantidad en inventario: " << cantidadInventario << endl;
        cout << "Precio: $" << precio << endl;
    }


    void reducirInventario(int cantidad) {
        cantidadInventario -= cantidad;
    }
};


class Cliente {
private:
    string nombre;


public:
    Cliente(string _nombre) : nombre(_nombre) {}


    string getNombre() const { return nombre; }
};


class Tienda {
private:
    vector<Producto> inventario;
    vector<string> transacciones;


public:
    void registrarProducto() {
        string nombre;
        int cantidad;
        double precio;


        cout << "Ingrese el nombre del producto: ";
        cin >> nombre;
        cout << "Ingrese la cantidad en inventario: ";
        cin >> cantidad;
        cout << "Ingrese el precio del producto: ";
        cin >> precio;


        Producto nuevoProducto(nombre, cantidad, precio);
        inventario.push_back(nuevoProducto);


        cout << "Producto registrado exitosamente." << endl;
    }


    void mostrarInventario() const {
        if (inventario.empty()) {
            cout << "El inventario está vacío." << endl;
        } else {
            cout << "=== Inventario de la Tienda ===" << endl;
            for (const Producto& producto : inventario) {
                producto.mostrarInformacion();
                
            }
        }
    }


    Producto* buscarProducto(const string& nombre) {
        for (size_t i = 0; i < inventario.size(); ++i) {
            if (inventario[i].getNombre() == nombre) {
                return &inventario[i];
            }
        }
        return nullptr;
    }


    bool realizarCompra(Cliente& cliente, const string& nombre, int cantidad) {
        Producto* producto = buscarProducto(nombre);
        if (producto != nullptr && producto->getCantidadInventario() >= cantidad) {
            producto->reducirInventario(cantidad);
            string transaccion = nombre + " - " + to_string(cantidad);
            transacciones.push_back(transaccion);
            cout << "Compra realizada exitosamente." << endl;
            return true;
        } else {
            cout << "No hay suficiente inventario del producto solicitado." << endl;
            return false;
        }
    }


    void generarInformeVenta() const {
        if (transacciones.empty()) {
            cout << "No hay ventas registradas." << endl;
            return;
        }


        cout << "Informe de Ventas" << endl;
        for (const auto& transaccion : transacciones) {
            cout << "Producto: " << transaccion << endl;
        }
    }
};


int main() {
    Tienda tienda;
    int opcion;


    do {
        cout << "Menú de Sistema de Gestión de Tienda de Abarrotes" << endl;
        cout << "1. Registrar Producto y Actualizar Inventario" << endl;
        cout << "2. Mostrar Inventario" << endl;
        cout << "3. Comprar Producto" << endl;
        cout << "4. Generar Informe de Venta" << endl;
        cout << "5. Salir" << endl;
        cout << "1-5: ";
        cin >> opcion;


        switch (opcion) {
            case 1:
                tienda.registrarProducto();
                break;
            case 2:
                tienda.mostrarInventario();
                break;
            case 3: {
                string nombreProducto;
                int cantidadCompra;
                cout << "Ingrese el nombre del producto que desea comprar: ";
                cin >> nombreProducto;
                cout << "Ingrese la cantidad que desea comprar: ";
                cin >> cantidadCompra;
                Cliente cliente("Cliente");
                tienda.realizarCompra(cliente, nombreProducto, cantidadCompra);
                break;
            }
            case 4:
                tienda.generarInformeVenta();
                break;
            case 5:
                cout << "Saliendo del sistema. ¡Hasta luego!" << endl;
                break;
            default:
                cout << "Opción no válida. Por favor, seleccione una opción del menú." << endl;
        }
    } while (opcion != 5);
}
