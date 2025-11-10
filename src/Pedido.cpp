// Archivo de implementación para la clase Pedido.

#include "Pedido.hpp"
#include <string>
#include <sstream> // Para construir el string de información
#include <iomanip> // Para std::fixed y std::setprecision

// Constructor de la clase Pedido.
// Inicializa un objeto Pedido con un ID, un proveedor, un empleado y los detalles del pedido.
Pedido::Pedido(int id, Proveedor* pr, Empleado* emp, const std::vector<DetallePedido>& detalles)
    : id(id), proveedor(pr), empleado(emp), detalles(detalles) {}

// Devuelve una cadena con la información completa y formateada del pedido.
// Útil para mostrar los datos de un pedido de forma legible.
std::string Pedido::getInfo() const {
    std::stringstream ss;
    ss << "Pedido #" << id << " a Proveedor: " << proveedor->getNombre() << "\n";
    ss << "  Procesado por: " << empleado->getNombre() << "\n";
    ss << "  Articulos:\n";
    for (const auto& detalle : detalles) {
        ss << "    - " << detalle.getInfo() << "\n"; // Agrega un guion para mayor claridad
    }
    ss << "  TOTAL DEL PEDIDO: $" << std::fixed << std::setprecision(2) << getTotal();
    return ss.str();
}

// Calcula y devuelve el costo total del pedido.
// Itera sobre todos los detalles del pedido y suma sus subtotales.
double Pedido::getTotal() const {
    double total = 0.0;
    for (const auto& detalle : detalles) {
        total += detalle.getSubtotal();
    }
    return total;
}