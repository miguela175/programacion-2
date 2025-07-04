#include <iostream>
#include <fstream>

int main() {
    std::ofstream archivo("inventario.bin", std::ios::binary);
    if (!archivo) {
        std::cerr << "No se pudo crear el archivo inventario.bin" << std::endl;
        return 1;
    }
    // El archivo se crea vacío
    archivo.close();
    std::cout << "Archivo inventario.bin creado correctamente." << std::endl;
    return 0;
}