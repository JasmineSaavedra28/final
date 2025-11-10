#include "Proveedor.hpp"

Proveedor::Proveedor(int id, std::string nombre, std::string cuit)
    : id(id), nombre(nombre), cuit(cuit) {}

int Proveedor::getId() const { return id; }
std::string Proveedor::getNombre() const { return nombre; }
std::string Proveedor::getCuit() const { return cuit; }

void Proveedor::setNombre(std::string n) { nombre = n; }
void Proveedor::setCuit(std::string c) { cuit = c; }

std::string Proveedor::getInfo() const {
    return "Proveedor #" + std::to_string(id) + " - " + nombre + " - CUIT: " + cuit;
}
