#include <iostream>
#include <chrono>
#include <string>

using namespace std;

// Declaro la función recursiva que compara dos cadenas de texto
bool cadenas_iguales(string cadena1, string cadena2, int index = 0);
constexpr bool cadenas_iguales2(char* cadena1, char* cadena2, int index = 0);

int main()
{
    string cadena1 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Praesent commodo cursus magna, vel scelerisque nisl consectetur et. Donec sed odio dui. Nulla vitae elit libero, a pharetra augue. Nullam id dolor id nibh ultricies vehicula ut id elit. Integer posuere erat a ante venenatis dapibus posuere velit aliquet. Aenean lacinia bibendum nulla sed consectetur.";
    string cadena2 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Praesent commodo cursus magna, vel scelerisque nisl consectetur et. Donec sed odio dui. Nulla vitae elit libero, a pharetra augue. Nullam id dolor id nibh ultricies vehicula ut id elit. Integer posuere erat a ante venenatis dapibus posuere velit aliquet. Aenean lacinia bibendum nulla sed consectetur.";

    // Mido el tiempo de ejecución de la función recursiva en ejecucion
    auto start = chrono::high_resolution_clock::now();
    bool iguales = cadenas_iguales(cadena1, cadena2);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "Tiempo de ejecución: " << duration.count() << " ns" << endl;
    cout << "Las cadenas son iguales: " << (iguales ? "Si" : "No") << endl;

    constexpr const char* cadena3 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Praesent commodo cursus magna, vel scelerisque nisl consectetur et. Donec sed odio dui. Nulla vitae elit libero, a pharetra augue. Nullam id dolor id nibh ultricies vehicula ut id elit. Integer posuere erat a ante venenatis dapibus posuere velit aliquet. Aenean lacinia bibendum nulla sed consectetur.";
    constexpr const char* cadena4 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Praesent commodo cursus magna, vel scelerisque nisl consectetur et. Donec sed odio dui. Nulla vitae elit libero, a pharetra augue. Nullam id dolor id nibh ultricies vehicula ut id elit. Integer posuere erat a ante venenatis dapibus posuere velit aliquet. Aenean lacinia bibendum nulla sed consectetur.";

    // Mido el tiempo de ejecución de la función recursiva en compilado
    auto start2 = chrono::high_resolution_clock::now();
    bool iguales2 = cadenas_iguales(cadena3, cadena4);
    auto end2 = chrono::high_resolution_clock::now();
    auto duration2 = chrono::duration_cast<chrono::nanoseconds>(end2 - start2);
    cout << "Tiempo de ejecución: " << duration2.count() << " ns" << endl;
    cout << "Las cadenas son iguales: " << (iguales2 ? "Si" : "No") << endl;

    return 0;
}

bool cadenas_iguales(string cadena1, string cadena2, int index)
{
    // Aca utilizo strings por la facilidad que brindan, aunque no es lo mas eficiente
    // char* es mas eficiente pero mas complicado de trabajar
    if (cadena1.length() != cadena2.length()) return false;
    if (index == cadena1.length()) return true;
    if (cadena1[index] != cadena2[index]) return false;
    return cadenas_iguales(cadena1, cadena2, index + 1);
}

constexpr bool cadenas_iguales2(const char* cadena1,const char* cadena2, int index = 0)
{
    // Aca utilizo char* por la eficiencia, y ademas es lo unico que puedo utilizar en una funcion constexpr
    if (&cadena1[index] == "\0" && &cadena2[index] == "\0") return true;
    if (&cadena1[index] == "\0" || &cadena2[index] == "\0") return false;
    if (cadena1[index] != cadena2[index]) return false;
    return cadenas_iguales2(cadena1, cadena2, index+1);
}