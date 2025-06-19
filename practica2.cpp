#include <iostream>
#include <fstream>
#include <vector>
#include <cstring> // Para strcmp y strcpy
#include <cstdlib> // Para system()

using namespace std;

// Definir el código de color naranja
#define COLOR_NARANJA "\033[38;5;208m"
#define RESET_COLOR "\033[0m"

// Estructura para representar un producto
struct Producto {
    char codigo[10]; // Codigo alfanumerico
    char nombre[30];
    float precio;
    int stock;
    char categoria[30];
    bool activo;
};

// Arreglo dinamico de productos
vector<Producto> productos;

// Funcion para limpiar la pantalla
void limpiarPantalla() {
    #ifdef _WIN32
        system("cls"); // Para Windows
    #else
        system("clear"); // Para Unix/Linux/macOS
    #endif
}

// Funcion para mostrar el menu
void mostrarMenu() {
    cout << COLOR_NARANJA << "\n    Abraham Management Menu   \n\n" << RESET_COLOR;
    cout << "1. Agregar un nuevo producto\n";
    cout << "2. Mostrar todos los productos activos\n";
    cout << "3. Mostrar productos por categoria\n";
    cout << "4. Buscar un producto por codigo\n";
    cout << "5. Modificar un producto\n";
    cout << "6. Eliminar un producto (borrado logico)\n";
    cout << "7. Recuperar un producto borrado\n";
    cout << "8. Guardar datos en archivo binario\n";
    cout << "9. Cargar datos desde archivo binario\n";
    cout << "10. Salir\n";
    cout << "\nSeleccione una opcion: ";
}

// Funcion para agregar un nuevo producto
void agregarProducto() {
    limpiarPantalla();
    Producto nuevo;
    cout << "\n--- Agregar Nuevo Producto ---\n";
    cout << "Codigo: ";
    cin.ignore();
    cin.getline(nuevo.codigo, 10);
    cout << "Nombre: ";
    cin.getline(nuevo.nombre, 30);
    cout << "Precio: ";
    cin >> nuevo.precio;
    cout << "Stock: ";
    cin >> nuevo.stock;
    cout << "Categoria: ";
    cin.ignore();
    cin.getline(nuevo.categoria, 30);
    nuevo.activo = true;

    productos.push_back(nuevo);
    cout << "Producto agregado con exito.\n";
}

// Funcion para mostrar todos los productos activos
void mostrarProductosActivos() {
    limpiarPantalla();
    if (productos.empty()) {
        cout << "No hay productos almacenados.\n";
        return;
    }
    cout << "\n--- Productos Activos ---\n";
    for (size_t i = 0; i < productos.size(); i++) {
        if (productos[i].activo) {
            cout << i + 1 << ". Codigo: " << productos[i].codigo << ", Nombre: " << productos[i].nombre
                 << ", Precio: " << productos[i].precio << ", Stock: " << productos[i].stock
                 << ", Categoria: " << productos[i].categoria << endl;
        }
    }
}

// Funcion para mostrar productos por categoria
void mostrarProductosPorCategoria() {
    limpiarPantalla();
    if (productos.empty()) {
        cout << "No hay productos almacenados.\n";
        return;
    }
    char categoria[30];
    cout << "\nIngrese la categoria: ";
    cin.ignore();
    cin.getline(categoria, 30);

    cout << "\n--- Productos en la categoria " << categoria << " ---\n";
    for (size_t i = 0; i < productos.size(); i++) {
        if (productos[i].activo && strcmp(productos[i].categoria, categoria) == 0) {
            cout << "Codigo: " << productos[i].codigo << ", Nombre: " << productos[i].nombre
                 << ", Precio: " << productos[i].precio << ", Stock: " << productos[i].stock << endl;
        }
    }
}

// Funcion para buscar un producto por codigo
void buscarProductoPorCodigo() {
    limpiarPantalla();
    if (productos.empty()) {
        cout << "No hay productos almacenados.\n";
        return;
    }
    char codigo[10];
    cout << "\nIngrese el codigo del producto: ";
    cin.ignore();
    cin.getline(codigo, 10);

    for (size_t i = 0; i < productos.size(); i++) {
        if (strcmp(productos[i].codigo, codigo) == 0 && productos[i].activo) {
            cout << "\n--- Producto Encontrado ---\n";
            cout << "Codigo: " << productos[i].codigo << ", Nombre: " << productos[i].nombre
                 << ", Precio: " << productos[i].precio << ", Stock: " << productos[i].stock
                 << ", Categoria: " << productos[i].categoria << endl;
            return;
        }
    }
    cout << "Producto no encontrado.\n";
}