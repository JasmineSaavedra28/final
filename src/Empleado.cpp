#include "Empleado.hpp"

// Constructor de la clase Empleado.
// Inicializa un nuevo objeto Empleado con id, nombre y puesto.
Empleado::Empleado(int id, std::string nombre, std::string puesto)
    : id(id), nombre(nombre), puesto(puesto) {}

// Método para obtener el ID del empleado.
int Empleado::getId() const {
    return id;
}

// Método para obtener el nombre del empleado.
std::string Empleado::getNombre() const {
    return nombre;
}

// Método para obtener el puesto del empleado.
std::string Empleado::getPuesto() const {
    return puesto;
}

// Método para obtener una cadena con la información del empleado.
// Combina el nombre y el puesto en un formato legible.
std::string Empleado::getInfo() const {
    return nombre + " - Puesto: " + puesto;
}

