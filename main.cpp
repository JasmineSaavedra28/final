#include <iostream>
#include <vector>
#include <limits>

#include "ProveedorManager.hpp"
#include "Pedido.hpp"
#include "Articulo.hpp"
#include "Empleado.hpp"

// --- Estructuras de Datos Globales ---
// Se usan variables globales para simplicidad en esta aplicación de consola.
ProveedorManager g_proveedorManager;
std::vector<Articulo> g_articulos;
std::vector<Empleado> g_empleados;
std::vector<Pedido> g_pedidos;

// --- Prototipos de Funciones para el Menú ---
void mostrarMenuPrincipal();
void gestionarProveedores();
void cargarArticulo();
void cargarEmpleado();
void cargarPedido();
void mostrarPedidos();
void cargarDatosIniciales();

// --- Lógica Principal de la Aplicación ---
int main() {
    cargarDatosIniciales();

    int opcion = 0;
    do {
        mostrarMenuPrincipal();
        std::cin >> opcion;

        // Limpia el buffer de entrada en caso de un error (ej: si se ingresa texto)
        if (std::cin.fail()) {
            std::cout << "Opcion invalida. Por favor, ingrese un numero." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            opcion = 0; // Resetea la opción para evitar un bucle infinito
            continue;
        }

        switch (opcion) {
            case 1:
                gestionarProveedores();
                break;
            case 2:
                cargarEmpleado();
                break;
            case 3:
                cargarArticulo();
                break;
            case 4:
                cargarPedido();
                break;
            case 5:
                mostrarPedidos();
                break;
            case 6:
                std::cout << "Saliendo del programa..." << std::endl;
                break;
            default:
                std::cout << "Opcion no valida. Intente de nuevo." << std::endl;
                break;
        }
        std::cout << std::endl;

    } while (opcion != 6);

    return 0;
}

// --- Implementación de las Funciones ---

void mostrarMenuPrincipal() {
    std::cout << "--- Gestion de Compra de Materia Prima ---" << std::endl;
    std::cout << "1. Gestionar Proveedores" << std::endl;
    std::cout << "2. Cargar Empleado" << std::endl;
    std::cout << "3. Cargar Articulo" << std::endl;
    std::cout << "4. Cargar Pedido" << std::endl;
    std::cout << "5. Mostrar Pedidos" << std::endl;
    std::cout << "6. Salir" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "Ingrese su opcion: ";
}

void cargarDatosIniciales() {
    // Carga de proveedores
    g_proveedorManager.addProveedor(Proveedor(1, "Gomas SRL", "20-12345678-9"));
    g_proveedorManager.addProveedor(Proveedor(2, "Latex S.A.", "20-87654321-0"));

    // Carga de artículos
    g_articulos.emplace_back(1, "Goma EVA", 5000);
    g_articulos.emplace_back(2, "Caucho Natural", 35000);

    // Carga de empleados
    g_empleados.emplace_back(1, "Carlos Lopez", "Comprador");
    g_empleados.emplace_back(2, "Ana Torres", "Administracion");

    // Carga de un pedido de ejemplo
    std::vector<DetallePedido> detallesPedido1;
    // Se usan punteros a los artículos en el vector global
    detallesPedido1.emplace_back(&g_articulos[0], 10);
    detallesPedido1.emplace_back(&g_articulos[1], 5);
    
    // Se buscan los punteros al proveedor y empleado correctos
    Proveedor* prov1 = g_proveedorManager.findProveedor(1);
    Empleado* emp1 = &g_empleados[0]; // Puntero al empleado en el vector global

    if (prov1 && emp1) {
        g_pedidos.emplace_back(1, prov1, emp1, detallesPedido1);
    }
    
    std::cout << "Datos iniciales cargados." << std::endl << std::endl;
}

void gestionarProveedores() {
    int opcion = 0;
    do {
        std::cout << "\n--- Gestion de Proveedores ---" << std::endl;
        std::cout << "1. Anadir Proveedor" << std::endl;
        std::cout << "2. Listar Proveedores" << std::endl;
        std::cout << "3. Actualizar Proveedor" << std::endl;
        std::cout << "4. Eliminar Proveedor" << std::endl;
        std::cout << "5. Volver al Menu Principal" << std::endl;
        std::cout << "-----------------------------" << std::endl;
        std::cout << "Ingrese su opcion: ";
        std::cin >> opcion;

        if (std::cin.fail()) {
            std::cout << "Opcion invalida. Por favor, ingrese un numero." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            opcion = 0;
            continue;
        }

        int id;
        std::string nombre, cuit;

        switch (opcion) {
            case 1:
                std::cout << "Ingrese ID del nuevo proveedor: ";
                std::cin >> id;
                std::cout << "Ingrese Nombre: ";
                std::cin.ignore();
                std::getline(std::cin, nombre);
                std::cout << "Ingrese CUIT: ";
                std::getline(std::cin, cuit);
                g_proveedorManager.addProveedor(Proveedor(id, nombre, cuit));
                std::cout << "Proveedor anadido." << std::endl;
                break;
            case 2:
                std::cout << "\n--- Listado de Proveedores ---" << std::endl;
                g_proveedorManager.listProveedores();
                break;
            case 3:
                std::cout << "Ingrese ID del proveedor a actualizar: ";
                std::cin >> id;
                std::cout << "Ingrese Nuevo Nombre: ";
                std::cin.ignore();
                std::getline(std::cin, nombre);
                std::cout << "Ingrese Nuevo CUIT: ";
                std::getline(std::cin, cuit);
                if (g_proveedorManager.updateProveedor(id, nombre, cuit)) {
                    std::cout << "Proveedor actualizado." << std::endl;
                } else {
                    std::cout << "Proveedor no encontrado." << std::endl;
                }
                break;
            case 4:
                std::cout << "Ingrese ID del proveedor a eliminar: ";
                std::cin >> id;
                if (g_proveedorManager.removeProveedor(id)) {
                    std::cout << "Proveedor eliminado." << std::endl;
                } else {
                    std::cout << "Proveedor no encontrado." << std::endl;
                }
                break;
            case 5:
                break;
            default:
                std::cout << "Opcion no valida." << std::endl;
                break;
        }
    } while (opcion != 5);
}

void cargarEmpleado() {
    int id;
    std::string nombre, cargo;

    std::cout << "Ingrese ID del nuevo empleado: ";
    std::cin >> id;
    std::cout << "Ingrese Nombre: ";
    std::cin.ignore();
    std::getline(std::cin, nombre);
    std::cout << "Ingrese Cargo: ";
    std::getline(std::cin, cargo);

    g_empleados.emplace_back(id, nombre, cargo);
    std::cout << "Empleado anadido." << std::endl;
}

void cargarArticulo() {
    int id;
    std::string descripcion;
    float precio;

    std::cout << "Ingrese ID del nuevo articulo: ";
    std::cin >> id;
    std::cout << "Ingrese Descripcion: ";
    std::cin.ignore();
    std::getline(std::cin, descripcion);
    std::cout << "Ingrese Precio: ";
    std::cin >> precio;

    g_articulos.emplace_back(id, descripcion, precio);
    std::cout << "Articulo anadido." << std::endl;
}

void cargarPedido() {
    int idPedido, idProv, idEmp, idArt, cant;
    
    std::cout << "Iniciando carga de nuevo pedido..." << std::endl;

    std::cout << "Ingrese ID del Pedido: ";
    std::cin >> idPedido;

    std::cout << "\nProveedores disponibles:" << std::endl;
    g_proveedorManager.listProveedores();
    std::cout << "Seleccione ID del Proveedor: ";
    std::cin >> idProv;
    Proveedor* prov = g_proveedorManager.findProveedor(idProv);
    if (!prov) {
        std::cout << "Proveedor no encontrado." << std::endl;
        return;
    }

    std::cout << "\nEmpleados disponibles:" << std::endl;
    for(const auto& emp : g_empleados) {
        std::cout << emp.getInfo() << std::endl;
    }
    std::cout << "Seleccione ID del Empleado: ";
    std::cin >> idEmp;
    Empleado* emp = nullptr;
    for(auto& e : g_empleados) {
        if (e.getId() == idEmp) {
            emp = &e;
            break;
        }
    }
    if (!emp) {
        std::cout << "Empleado no encontrado." << std::endl;
        return;
    }

    std::vector<DetallePedido> detalles;
    char continuar = 's';
    while (continuar == 's' || continuar == 'S') {
        std::cout << "\nArticulos disponibles:" << std::endl;
        for(const auto& art : g_articulos) {
            std::cout << art.getInfo() << std::endl;
        }
        std::cout << "Seleccione ID del Articulo: ";
        std::cin >> idArt;
        Articulo* art = nullptr;
        for(auto& a : g_articulos) {
            if (a.getId() == idArt) {
                art = &a;
                break;
            }
        }

        if (!art) {
            std::cout << "Articulo no encontrado." << std::endl;
        } else {
            std::cout << "Ingrese cantidad: ";
            std::cin >> cant;
            detalles.emplace_back(art, cant);
            std::cout << "Articulo agregado al pedido." << std::endl;
        }

        std::cout << "Desea agregar otro articulo? (s/n): ";
        std::cin >> continuar;
    }

    g_pedidos.emplace_back(idPedido, prov, emp, detalles);
    std::cout << "Pedido cargado exitosamente." << std::endl;
}

void mostrarPedidos() {
    std::cout << "--- Mostrando Pedidos Cargados ---" << std::endl;
    if (g_pedidos.empty()) {
        std::cout << "No hay pedidos para mostrar." << std::endl;
        return;
    }

    for (auto &p : g_pedidos) {
        std::cout << p.getInfo() << std::endl;
    }
}