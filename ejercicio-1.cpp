#include <iostream>
#include <memory>

using namespace std; //  Para evitar usar std:: en cada línea

// Declaro las funciones que voy a usar
unique_ptr< unique_ptr<int[]>[] > crearMatriz(int n);
// Recibo la matriz por referencia para no hacer una copia
void printMatriz(unique_ptr< unique_ptr<int[]>[] > &matriz, int n);

int main() 
{
    // Pido el tamaño de la matriz
    int n;
    cout << "Ingrese el tamaño de la matriz: ";
    cin >> n;

    // Creo la matriz definiendo el tipo de dato de salida
    unique_ptr< unique_ptr<int[]>[]> matriz = crearMatriz(n);
    printMatriz(matriz, n);

    return 0;
}

unique_ptr< unique_ptr<int[]>[] > crearMatriz(int n)
{
    // Creo la matriz de unique pointers 2D
    unique_ptr< unique_ptr<int[]>[] > matriz = make_unique< unique_ptr<int[]>[] >(n);
    int contador = 1;
    for (int i = 0; i < n; i++)
    {
        // A cada fila le asigno un arreglo de enteros
        matriz[i] = make_unique<int[]>(n);
        for (int j = 0; j < n; j++)
        {
            // lleno la matriz con numeros consecutivos
            matriz[i][j] = contador++;
        }
    }

    return matriz;
}

void printMatriz(unique_ptr< unique_ptr<int[]>[] > &matriz, int n)
{
    // Imprimo la matriz en orden inverso
    for (int i = n * n - 1; i >= 0; i--)
    {
        // Calculo los indices de la matriz
        // Utilizo los int para que me trunque los decimales
        int k =  i / n;
        int j = i % n;
        cout << "Matriz[" << k << "][" << j << "] = " << matriz[k][j] << endl;
    }
}
