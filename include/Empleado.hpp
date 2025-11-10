#ifndef EMPLEADO_HPP
#define EMPLEADO_HPP

#include <string>

// Representa a un empleado de la empresa.
class Empleado {
private:
    int id;                 // Identificador único del empleado.
    std::string nombre;     // Nombre del empleado.
    std::string puesto;     // Puesto o cargo del empleado.

public:
    // Constructor para inicializar un empleado.
    Empleado(int id, std::string nombre, std::string puesto);

    // Métodos para obtener los datos del empleado.
    int getId() const;
    std::string getNombre() const;
    std::string getPuesto() const;

    // Devuelve una cadena con la información completa del empleado.
    std::string getInfo() const;
};

#endif
