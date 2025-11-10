#include "Articulo.hpp"

// Constructor de la clase Articulo.
// Inicializa un nuevo objeto Articulo con un id, nombre y precio.
Articulo::Articulo(int id, std::string nombre, double precio)
    : id(id), nombre(nombre), precio(precio) {}

// Método para obtener el nombre del artículo.
std::string Articulo::getNombre() const {
    return nombre;
}

// Método para obtener el precio del artículo.
double Articulo::getPrecio() const {
    return precio;
}

// Método para obtener una cadena con la información del artículo.
// Combina el nombre y el precio en un formato legible.
std::string Articulo::getInfo() const {
    return nombre + " $" + std::to_string(precio);
}
