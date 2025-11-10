#ifndef EMPLEADO_HPP
#define EMPLEADO_HPP

#include <string>

class Empleado {
private:
    int id;
    std::string nombre;
    std::string puesto;

public:
    Empleado(int id, std::string nombre, std::string puesto);

    int getId() const;
    std::string getNombre() const;
    std::string getPuesto() const;
    std::string getInfo() const;
};

#endif

