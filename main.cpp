#include <iostream>
#include <vector>

#include "ProveedorManager.hpp"
#include "Pedido.hpp"
#include "Articulo.hpp"
#include "Empleado.hpp"

int main() {

    ProveedorManager pm;

    // CRUD hardcodeado
    pm.addProveedor(Proveedor(1, "Gomas SRL", "20-12345678-9"));
    pm.addProveedor(Proveedor(2, "Latex S.A.", "20-87654321-0"));

    // Mostrar proveedores
    pm.listProveedores();

    // Crear artículos
    Articulo a1(1, "Goma EVA", 5000);
    Articulo a2(2, "Caucho Natural", 35000);

    // Crear empleados
    Empleado e1(1, "Carlos Lopez", "Comprador");
    Empleado e2(2, "Ana Torres", "Administracion");

    // --- Crear Pedidos con Múltiples Artículos ---
    std::vector<Pedido> pedidos;

    // Pedido 1: Contiene 10 Goma EVA y 5 Caucho Natural
    std::vector<DetallePedido> detallesPedido1;
    detallesPedido1.emplace_back(&a1, 10); // 10 de Goma EVA
    detallesPedido1.emplace_back(&a2, 5);  // 5 de Caucho Natural
    pedidos.emplace_back(1, pm.findProveedor(1), &e1, detallesPedido1);

    // Pedido 2: Contiene 20 Caucho Natural
    std::vector<DetallePedido> detallesPedido2;
    detallesPedido2.emplace_back(&a2, 20); // 20 de Caucho Natural
    pedidos.emplace_back(2, pm.findProveedor(2), &e2, detallesPedido2);

    // Mostrar pedidos
    std::cout << "\nPedidos:\n";
    for (auto &p : pedidos) {
        std::cout << p.getInfo() << std::endl;
    }

    return 0;
}
