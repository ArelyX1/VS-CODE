#include <iostream>
#include <vector>
using namespace std;

class Animales{
    protected:
        string nombre;

    private:
        string edad;
    public:
        Animales(string, string edad_inicial);
        virtual void hacerSonido();
        void setNombre(string nombre_nuevo){nombre = nombre_nuevo;}
        string getNombre(){return nombre;}
        void setEdad(string edad_nuevo){edad = edad_nuevo;}
        string getEdad(){return edad;}
};
Animales::Animales(string nombre_inicial, string edad_inicial = "Desconocido"){
    nombre = nombre_inicial;
    edad = edad_inicial;
}
void Animales :: hacerSonido(){
    cout << "El animal hizo un sonido raro y genérico";
}

class Mamifero : public Animales{
    private:
        string familia_animal;
        string raza;
    public:
        
};

int main(){
    Animales perro("Bingo");
    cout << perro.getEdad();
}