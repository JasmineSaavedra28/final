#ifndef PEDIDO_HPP
#define PEDIDO_HPP

#include <string>
#include <vector>
#include "Proveedor.hpp"
#include "Empleado.hpp"
#include "DetallePedido.hpp"

// Representa un pedido de compra a un proveedor.
class Pedido {
private:
    int id;                                     // Identificador único del pedido.
    Proveedor* proveedor;                       // Puntero al proveedor al que se le hace el pedido.
    Empleado* empleado;                         // Puntero al empleado que gestiona el pedido.
    std::vector<DetallePedido> detalles;        // Lista de todos los artículos y cantidades pedidas.

public:
    // Constructor para crear un nuevo pedido.
    Pedido(int id, Proveedor* pr, Empleado* emp, const std::vector<DetallePedido>& detalles);

    // Devuelve una cadena con la información completa del pedido.
    std::string getInfo() const;

    // Calcula y devuelve el costo total del pedido.
    double getTotal() const;
};

#endif
