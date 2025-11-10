#pragma once
#include <string>

// Representa un artículo o producto que puede ser comprado.
class Articulo {
private:
    int id;                 // Identificador único del artículo.
    std::string nombre;     // Nombre del artículo.
    double precio;          // Precio unitario del artículo.

public:
    // Constructor para inicializar un artículo.
    Articulo(int id, std::string nombre, double precio);

    // Métodos para obtener los datos del artículo.
    std::string getNombre() const;
    double getPrecio() const;
    int getId() const; // Added getId() method

    // Devuelve una cadena con la información completa del artículo.
    std::string getInfo() const;
};
