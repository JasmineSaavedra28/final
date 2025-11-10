#pragma once
#include <string>

class Articulo {
private:
    int id;
    std::string nombre;
    double precio;

public:
    Articulo(int id, std::string nombre, double precio);
    std::string getNombre() const;
    double getPrecio() const;
    std::string getInfo() const;
};
