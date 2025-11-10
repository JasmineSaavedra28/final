#include <iostream>
#include <vector>

#include "ProveedorManager.hpp"
#include "Pedido.hpp"
#include "Articulo.hpp"
#include "Empleado.hpp"

int main() {

    // 1. Se crea el administrador de proveedores.
    //    Este objeto se encargará de gestionar la lista de proveedores.
    ProveedorManager pm;

    // 2. Se crean y añaden proveedores a la lista (CREATE del CRUD).
    //    CRUD: Create, Read, Update, Delete (Crear, Leer, Actualizar, Borrar).
    pm.addProveedor(Proveedor(1, "Gomas SRL", "20-12345678-9"));
    pm.addProveedor(Proveedor(2, "Latex S.A.", "20-87654321-0"));

    // 3. Se listan los proveedores existentes (READ del CRUD).
    pm.listProveedores();

    // 4. Se crean los artículos que se van a comprar.
    Articulo a1(1, "Goma EVA", 5000);
    Articulo a2(2, "Caucho Natural", 35000);

    // 5. Se crean los empleados que procesan los pedidos.
    Empleado e1(1, "Carlos Lopez", "Comprador");
    Empleado e2(2, "Ana Torres", "Administracion");

    // 6. Se prepara una lista para guardar los pedidos.
    std::vector<Pedido> pedidos;

    // --- Crear Pedido 1: Contiene 10 Goma EVA y 5 Caucho Natural ---
    std::vector<DetallePedido> detallesPedido1;
    detallesPedido1.emplace_back(&a1, 10); // Se añade el artículo a1 con cantidad 10.
    detallesPedido1.emplace_back(&a2, 5);  // Se añade el artículo a2 con cantidad 5.
    
    // Se crea el pedido completo y se añade a la lista de pedidos.
    // Se busca el proveedor por ID (pm.findProveedor(1)) para asociarlo.
    pedidos.emplace_back(1, pm.findProveedor(1), &e1, detallesPedido1);

    // --- Crear Pedido 2: Contiene 20 Caucho Natural ---
    std::vector<DetallePedido> detallesPedido2;
    detallesPedido2.emplace_back(&a2, 20); // Se añade el artículo a2 con cantidad 20.

    // Se crea el segundo pedido y se añade a la lista.
    pedidos.emplace_back(2, pm.findProveedor(2), &e2, detallesPedido2);

    // 7. Se muestran todos los pedidos creados.
    std::cout << "\nPedidos:\n";
    for (auto &p : pedidos) {
        // Se llama a getInfo() de cada pedido para ver el resumen.
        std::cout << p.getInfo() << std::endl;
    }

    return 0;
}
