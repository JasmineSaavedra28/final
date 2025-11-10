#include "Empleado.hpp"

Empleado::Empleado(int id, std::string nombre, std::string puesto)
    : id(id), nombre(nombre), puesto(puesto) {}

int Empleado::getId() const {
    return id;
}

std::string Empleado::getNombre() const {
    return nombre;
}

std::string Empleado::getPuesto() const {
    return puesto;
}

std::string Empleado::getInfo() const {
    return nombre + " - Puesto: " + puesto;
}

