#include "DetallePedido.hpp"
#include <string>
#include <sstream>   // Para formatear strings
#include <iomanip>   // Para std::fixed y std::setprecision

DetallePedido::DetallePedido(Articulo* articulo, int cantidad)
    : articulo(articulo), cantidad(cantidad) {
    if (articulo) {
        // Captura el precio del artículo al momento de crear el detalle.
        // Es una buena práctica por si el precio del artículo cambia en el futuro.
        this->precioUnitario = articulo->getPrecio();
    } else {
        this->precioUnitario = 0.0;
    }
}

std::string DetallePedido::getInfo() const {
    std::stringstream ss;
    ss << "  - Item: " << articulo->getNombre()
       << ", Cantidad: " << cantidad
       << ", P/U: $" << std::fixed << std::setprecision(2) << precioUnitario;
    // std::fixed -> Usa notación de punto fijo (ej. 123.45)
    // std::setprecision(2) -> Muestra 2 dígitos después del punto decimal
    return ss.str();
}

double DetallePedido::getSubtotal() const {
    return cantidad * precioUnitario;
}