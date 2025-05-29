#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

bool buscarPalabra(const string& nombredeArchivo, const string& palabra) {
    ifstream archivo(nombredeArchivo);
    if (!archivo) {
        cout << "El archivo " << nombredeArchivo << " no existe." << endl;
        return false;
    }

    string contenido, linea;
    while (getline(archivo, linea)) {
        contenido += linea + " ";
    }
    string contenido_minuscula = contenido;
    string palabra_minuscula = palabra;
    transform(contenido_minuscula.begin(), contenido_minuscula.end(), contenido_minuscula.begin(), ::tolower);
    transform(palabra_minuscula.begin(), palabra_minuscula.end(), palabra_minuscula.begin(), ::tolower);

    if (contenido_minuscula.find(palabra_minuscula) != string::npos) {
        cout << "La palabra '" << palabra << "' fue encontrada en el archivo." << endl;
        return true;
    } else {
        cout << "La palabra '" << palabra << "' no fue encontrada en el archivo." << endl;
        return false;
    }
}

int main() {
    string nombredeArchivo, palabra;
    nombredeArchivo = "C:/Users/migue/OneDrive/Desktop/programacion 2/el_quijote.txt";

    cout << "Ingrese la palabra a buscar: ";
    cin >> palabra;
    cout << "Buscando la palabra " << palabra << " en el archivo " << nombredeArchivo << "..." << endl;


    buscarPalabra(nombredeArchivo, palabra);

    return 0;
}