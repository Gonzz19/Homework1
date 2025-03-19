#include <iostream>
#include <chrono>
#include <string>

using namespace std;

bool cadenas_iguales(string cadena1, string cadena2, int index = 0);

int main()
{
    string cadena1 = "Hola Doctor Mundo";
    string cadena2 = "Hola Doctor Mundo";

    auto start = chrono::high_resolution_clock::now();
    bool iguales = cadenas_iguales(cadena1, cadena2);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "Las cadenas son iguales: " << (iguales ? "Si" : "No") << endl;
    cout << "Tiempo de ejecución: " << duration.count() << " ns" << endl;

    return 0;
}

bool cadenas_iguales(string cadena1, string cadena2, int index)
{
    if (cadena1.length() != cadena2.length()) return false;
    if (index == cadena1.length()) return true;
    if (cadena1[index] != cadena2[index]) return false;
    return cadenas_iguales(cadena1, cadena2, index + 1);
}