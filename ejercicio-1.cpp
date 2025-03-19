#include <iostream>
#include <memory>

using namespace std;

unique_ptr< unique_ptr<int[]>[] > crearMatriz(int n);
void printMatriz(unique_ptr< unique_ptr<int[]>[] > &matriz, int n);

int main() {
    int n;
    cout << "Ingrese el tamaño de la matriz: ";
    cin >> n;

    unique_ptr< unique_ptr<int[]>[]> matriz = crearMatriz(n);
    printMatriz(matriz, n);

    return 0;
}

unique_ptr< unique_ptr<int[]>[] > crearMatriz(int n)
{
    unique_ptr< unique_ptr<int[]>[] > matriz = make_unique< unique_ptr<int[]>[] >(n);
    int contador = 1;
    for (int i = 0; i < n; i++)
    {
        matriz[i] = make_unique<int[]>(n);
        for (int j = 0; j < n; j++)
        {
            matriz[i][j] = contador++;
        }
    }

    return matriz;
}

void printMatriz(unique_ptr< unique_ptr<int[]>[] > &matriz, int n)
{
    for (int i = n * n - 1; i >= 0; i--)
    {
        int k =  i / n;
        int j = i % n;
        cout << "Matriz[" << k << "][" << j << "] = " << matriz[k][j] << endl;
    }
}
