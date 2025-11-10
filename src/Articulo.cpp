#include "Articulo.hpp"

Articulo::Articulo(int id, std::string nombre, double precio)
    : id(id), nombre(nombre), precio(precio) {}

std::string Articulo::getNombre() const {
    return nombre;
}

double Articulo::getPrecio() const {
    return precio;
}

std::string Articulo::getInfo() const {
    return nombre + " $" + std::to_string(precio);
}
