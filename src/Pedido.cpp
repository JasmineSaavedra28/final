#include "Pedido.hpp"
#include <string>
#include <sstream> // Para construir el string de información
#include <iomanip> // Para std::fixed y std::setprecision

Pedido::Pedido(int id, Proveedor* pr, Empleado* emp, const std::vector<DetallePedido>& detalles)
    : id(id), proveedor(pr), empleado(emp), detalles(detalles) {}

std::string Pedido::getInfo() const {
    std::stringstream ss;
    ss << "Pedido #" << id << " a Proveedor: " << proveedor->getNombre() << "\n";
    ss << "  Procesado por: " << empleado->getNombre() << "\n";
    ss << "  Articulos:\n";
    for (const auto& detalle : detalles) {
        ss << detalle.getInfo() << "\n";
    }
    ss << "  TOTAL DEL PEDIDO: $" << std::fixed << std::setprecision(2) << getTotal();
    return ss.str();
}

double Pedido::getTotal() const {
    double total = 0.0;
    for (const auto& detalle : detalles) {
        total += detalle.getSubtotal();
    }
    return total;
}
