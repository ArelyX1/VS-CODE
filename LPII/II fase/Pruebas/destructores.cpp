#include <iostream>
#include <fstream> // Libreria para manejo de archivos
using namespace std;
class ClaseConDestructor {
public:
    ClaseConDestructor() {
        ptr = new int(10);  // creando un entero en el heap,
    //almacenamos el valor 10 en la dirección de memoria que apunta ptr
    }
/*
    ~ClaseConDestructor() {
        delete ptr;  // Liberamos la memoria en el destructor
    }
*/

    int* ptr; // creando un puntero a entero
};

int main() {
    ClaseConDestructor* obj = new ClaseConDestructor();
    delete obj;  // Esto llamará al destructor personalizado, que liberará la memoria de ptr, y luego liberará la memoria de obj
    cout << *(obj -> ptr) << endl;
}