#ifndef DETALLE_PEDIDO_HPP
#define DETALLE_PEDIDO_HPP

#include <string>
#include "Articulo.hpp"

class DetallePedido {
private:
    Articulo* articulo;
    int cantidad;
    double precioUnitario; // Precio al momento de la compra

public:
    DetallePedido(Articulo* articulo, int cantidad);
    std::string getInfo() const;
    double getSubtotal() const;
};

#endif