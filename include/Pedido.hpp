#ifndef PEDIDO_HPP
#define PEDIDO_HPP

#include <string>
#include <vector>
#include "Proveedor.hpp"
#include "Empleado.hpp"
#include "DetallePedido.hpp"

class Pedido {
private:
    int id;
    Proveedor* proveedor;
    Empleado* empleado;   // Empleado que procesa la orden
    std::vector<DetallePedido> detalles;

public:
    Pedido(int id, Proveedor* pr, Empleado* emp, const std::vector<DetallePedido>& detalles);

    std::string getInfo() const;
    double getTotal() const;
};

#endif
