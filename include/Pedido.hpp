// Archivo de cabecera para la clase Pedido.
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
    // Asigna un ID, un proveedor, un empleado y los detalles de los artículos.
    Pedido(int id, Proveedor* pr, Empleado* emp, const std::vector<DetallePedido>& detalles);

    // Devuelve una cadena con la información completa del pedido.
    // Incluye ID, proveedor, empleado y todos los detalles de los artículos.
    std::string getInfo() const;

    // Calcula y devuelve el costo total del pedido.
    // Suma los subtotales de cada detalle del pedido.
    double getTotal() const;
};

#endif