#include "ProveedorManager.hpp"
#include <iostream>

// Agrega un nuevo proveedor a la lista (vector).
// Recibe el proveedor por valor, creando una copia dentro del manager.
void ProveedorManager::addProveedor(Proveedor p) {
    proveedores.push_back(p);
}

// Muestra por pantalla la información de todos los proveedores en la lista.
void ProveedorManager::listProveedores() const {
    for (const auto &p : proveedores) {
        std::cout << p.getInfo() << std::endl;
    }
}

// Busca un proveedor por su ID.
// Devuelve un puntero al proveedor si lo encuentra, o nullptr si no existe.
Proveedor* ProveedorManager::findProveedor(int id) {
    for (auto &p : proveedores) {
        if (p.getId() == id) {
            return &p;
        }
    }
    return nullptr;
}

// Actualiza los datos de un proveedor existente.
// Primero busca al proveedor por ID y, si lo encuentra, cambia su nombre y CUIT.
bool ProveedorManager::updateProveedor(int id, std::string nuevoNombre, std::string nuevoCuit) {
    Proveedor* p = findProveedor(id);
    if (p) { // Si se encontró el proveedor (p no es nullptr)
        p->setNombre(nuevoNombre);
        p->setCuit(nuevoCuit);
        return true; // Éxito
    }
    return false; // Fracaso, no se encontró
}

// Elimina un proveedor de la lista usando su ID.
// Recorre la lista y, si encuentra el ID, borra el elemento del vector.
bool ProveedorManager::removeProveedor(int id) {
    for (auto it = proveedores.begin(); it != proveedores.end(); ++it) {
        if (it->getId() == id) {
            proveedores.erase(it);
            return true; // Éxito
        }
    }
    return false; // Fracaso, no se encontró
}
