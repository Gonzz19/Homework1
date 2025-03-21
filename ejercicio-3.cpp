#include <iostream>
#include <memory>

using namespace std;

// Definicion de estructuras
struct Nodo {
    int valor;
    shared_ptr<Nodo> next = nullptr;
};

struct Lista {
    size_t size = 0;
    shared_ptr<Nodo> head = nullptr;
    shared_ptr<Nodo> tail = nullptr;
};

// Declaracion de funciones
Nodo crear_nodo(int valor);
bool push_head(Lista &lista, int valor);
bool push_tail(Lista &lista, int valor);
bool insert(Lista &lista, size_t pos, int valor);
bool borrar(Lista &lista, size_t pos);
bool borrar_ultimo(Lista &lista);
void print_lista(Lista &lista);

int main()
{
    // Ejemplo de uso
    cout << "Lista simplemente enlazada" << endl;
    int n;
    cout << "Ingrese opcion: " << endl;
    cout << "1. Insertar al inicio" << endl;
    cout << "2. Insertar al final" << endl;
    cout << "3. Insertar en posicion" << endl;
    cout << "4. Borrar en posicion" << endl;
    cout << "5. Imprimir lista" << endl;
    cout << "6. Salir" << endl;
    Lista lista;
    cin >> n;
    while (n!=6)
    {
        switch (n)
        {
            int valor;
            int pos;
            case 1:
                
                cout << "Ingrese valor: ";
                cin >> valor;
                push_head(lista, valor);
                break;
            case 2:
                cout << "Ingrese valor: ";
                cin >> valor;
                push_tail(lista, valor);
                break;
            case 3:
                cout << "Ingrese valor: ";
                cin >> valor;
                cout << "Ingrese posicion: ";
                cin >> pos;
                insert(lista, pos, valor);
                break;
            case 4:
                cout << "Ingrese posicion: ";
                cin >> pos;
                borrar(lista, pos);
                break;
            case 5:
                print_lista(lista);
                break;
            default:
                cout << "Opcion invalida" << endl;
                break;
        }
        cout << "Ingrese opcion: " << endl;
        cout << "1. Insertar al inicio" << endl;
        cout << "2. Insertar al final" << endl;
        cout << "3. Insertar en posicion" << endl;
        cout << "4. Borrar en posicion" << endl;
        cout << "5. Imprimir lista" << endl;
        cout << "6. Salir" << endl;
        cin >> n;
    }
    return 0;
}

Nodo crear_nodo(int valor)
{
    // Funcion para crear un nodo
    Nodo nodo;
    nodo.valor = valor;
    return nodo;
}

bool push_head(Lista &lista, int valor)
{
    // Funcion para agregar un nodo al inicio de la lista
    shared_ptr<Nodo> nodo = make_shared<Nodo>(crear_nodo(valor));
    if (lista.size == 0)
    {
        // Caso en que la lista esta vacia
        lista.head = nodo;
        lista.tail = nodo;
    }
    else
    {
        // Caso en que la lista ya cuenta con algo
        nodo->next = lista.head;
        lista.head = nodo;
    }
    lista.size++;
    return true;
}

bool push_tail(Lista &lista, int valor)
{
    shared_ptr<Nodo> nodo = make_shared<Nodo>(crear_nodo(valor));
    if (lista.size == 0)
    {
        // Caso en que la lista esta vacia
        lista.head = nodo;
        lista.tail = nodo;
    }
    else
    {
        // Caso en que la lista ya cuenta con algo
        lista.tail->next = nodo;
        lista.tail = nodo;
    }
    lista.size++;
    return true;
}

bool insert(Lista &lista, size_t pos, int valor)
{
    if (pos > lista.size) 
    {
        // Caso en que la posicion es mayor al tamaño de la lista
        // Agrego al final
        cout << "Fuera de rango, se agrega al final" << endl;
        return push_tail(lista, valor);
    }
    // Reutilizo las funciones de agregar al inicio y al final
    if (pos == 0) return push_head(lista, valor);
    if (pos == lista.size) return push_tail(lista, valor);
    
    // Caso generico
    shared_ptr<Nodo> nodo = make_shared<Nodo>(crear_nodo(valor));
    shared_ptr<Nodo> current = lista.head;
    for (size_t i = 0; i < pos - 1; i++)
    {
        current = current->next;
    }
    nodo->next = current->next;
    current->next = nodo;
    lista.size++;
    return true;
}

bool borrar(Lista &lista, size_t pos)
{
    if (lista.size == 0)
    {
        cout << "Lista vacia" << endl;
        return false;
    }
    if (pos >= lista.size)
    {
        // Caso en que la posicion es mayor al tamaño de la lista
        // Elimino el ultimo
        cout << "Fuera de rango, se eliminara el ultimo" << endl;
        return borrar_ultimo(lista);
    } 

    if (pos == 0)
    {
        // Caso en que se elimina el primer elemento
        lista.head = lista.head->next;
        lista.size--;
        return true;
    }

    // Caso generico
    shared_ptr<Nodo> current = lista.head;
    for (size_t i = 0; i < pos - 1; i++)
    {
        current = current->next;
    }
    current->next = current->next->next;
    if (pos == lista.size - 1)
    {
        lista.tail = current;
    }
    lista.size--;
    return true;
}

void print_lista(Lista &lista)
{
    shared_ptr<Nodo> current = lista.head;
    while (current->next != nullptr)
    {
        // Imprimo todos los elementos menos el ultimo
        // Para que la flecha no se imprima sola
        cout << current->valor << "->";
        current = current->next;
    }
    // Imprimo el ultimo elemento
    cout << current->valor;
    cout << endl;
}   

bool borrar_ultimo(Lista &lista)
{
    // Funcion auxiliar para borrar el ultimo elemento
    if (lista.size == 1)
    {
        // Caso en que la lista tiene un solo elemento
        lista.head = nullptr;
        lista.tail = nullptr;
        lista.size = 0;
        return true;
    }
    // Caso generico
    shared_ptr<Nodo> current = lista.head;
    for (size_t i = 0; i < lista.size - 2; i++)
    {
        current = current->next;
    }
    current->next = nullptr;
    lista.tail = current;
    lista.size--;
    return true;
}

