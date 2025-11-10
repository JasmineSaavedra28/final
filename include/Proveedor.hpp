#pragma once
#include <string>

class Proveedor {
private:
    int id;
    std::string nombre;
    std::string cuit;

public:
    Proveedor(int id, std::string nombre, std::string cuit);

    int getId() const;
    std::string getNombre() const;
    std::string getCuit() const;

    void setNombre(std::string n);
    void setCuit(std::string c);
    std::string getInfo() const;
};

