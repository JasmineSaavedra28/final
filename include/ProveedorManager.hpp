#pragma once
#include <vector>
#include "Proveedor.hpp"

class ProveedorManager {
private:
    std::vector<Proveedor> proveedores;

public:
    void addProveedor(Proveedor p);
    void listProveedores() const;
    Proveedor* findProveedor(int id);
    bool updateProveedor(int id, std::string nuevoNombre, std::string nuevoCuit);
    bool removeProveedor(int id);
};
