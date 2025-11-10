#ifndef DETALLE_PEDIDO_HPP
#define DETALLE_PEDIDO_HPP

#include <string>
#include "Articulo.hpp"

// Representa una línea de detalle dentro de un pedido.
// Contiene un artículo, la cantidad pedida y el precio en ese momento.
class DetallePedido {
private:
    Articulo* articulo;     // Puntero al artículo que se está pidiendo.
    int cantidad;           // Cantidad de unidades del artículo.
    double precioUnitario;  // Precio del artículo al momento de hacer el pedido.

public:
    // Constructor: asocia un artículo y una cantidad.
    DetallePedido(Articulo* articulo, int cantidad);

    // Devuelve una cadena con la información del detalle.
    std::string getInfo() const;

    // Calcula y devuelve el subtotal (cantidad * precio).
    double getSubtotal() const;
};

#endif