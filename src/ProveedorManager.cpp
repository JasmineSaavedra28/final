#include "ProveedorManager.hpp"
#include <iostream>

void ProveedorManager::addProveedor(Proveedor p) {
    proveedores.push_back(p);
}

void ProveedorManager::listProveedores() const {
    for (auto &p : proveedores)
        std::cout << p.getInfo() << std::endl;
}

Proveedor* ProveedorManager::findProveedor(int id) {
    for (auto &p : proveedores)
        if (p.getId() == id)
            return &p;
    return nullptr;
}

bool ProveedorManager::updateProveedor(int id, std::string nuevoNombre, std::string nuevoCuit) {
    Proveedor* p = findProveedor(id);
    if (!p) return false;
    p->setNombre(nuevoNombre);
    p->setCuit(nuevoCuit);
    return true;
}

bool ProveedorManager::removeProveedor(int id) {
    for (auto it = proveedores.begin(); it != proveedores.end(); ++it) {
        if (it->getId() == id) {
            proveedores.erase(it);
            return true;
        }
    }
    return false;
}
