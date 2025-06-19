#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>
#include <windows.h>

using namespace std;

void ChColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

string Minus(const string &texto)
{
    string textoMinus = texto;
    transform(textoMinus.begin(), textoMinus.end(), textoMinus.begin(), ::tolower);
    return textoMinus;
}

void resaltar(string linea, const string &PBuscada)
{
    string lineaMinus = Minus(linea);
    string palabraMinus = Minus(PBuscada);
    size_t posicion = lineaMinus.find(palabraMinus);

    while (posicion != string::npos)
    {
        cout << linea.substr(0, posicion);
        ChColor(10);
        cout << linea.substr(posicion, PBuscada.length());
        ChColor(7);
        linea = linea.substr(posicion + PBuscada.length());
        lineaMinus = lineaMinus.substr(posicion + PBuscada.length());
        posicion = lineaMinus.find(palabraMinus);
    }
    cout << linea << endl;
}

int main()
{

    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    string nombreArchivo = "C:/Users/migue/OneDrive/Desktop/programacion 2/el_quijote.txt";
    ifstream archivo(nombreArchivo);

    if (!archivo.is_open())
    {
        cerr << "No se pudo abrir el archivo." << endl;
        return 1;
    }

    string linea;
    string PBuscada;
    char repetir;

    do
    {
        cout << "Ingrese la palabra para buscar: ";
        getline(cin, PBuscada);

        if (PBuscada.empty())
        {
            cout << "ingrese una entrada" << endl;
            continue;
        }

        int CTotales = 0;
        archivo.clear();
        archivo.seekg(0);

        while (getline(archivo, linea))
        {
            string lineaMinus = Minus(linea);
            string palabraMinus = Minus(PBuscada);
            size_t posicion = lineaMinus.find(palabraMinus);

            if (posicion != string::npos)
            {
                resaltar(linea, PBuscada);
                size_t contador = 0;

                while (posicion != string::npos)
                {
                    contador++;
                    posicion = lineaMinus.find(palabraMinus, posicion + 1);
                }

                CTotales += contador;
            }
            else
            {
                cout << linea << endl;
            }
        }

        cout << "coincidencias para \"" << PBuscada << "\": " << CTotales << endl;
        cout << "¿Repetir la búsqueda? (S/N): ";
        cin >> repetir;
        cin.ignore();
    } while (repetir == 'S' || repetir == 's');

    archivo.close();
    return 0;
}