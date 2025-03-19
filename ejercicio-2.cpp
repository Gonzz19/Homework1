#include <iostream>
#include <string> 
#include <fstream>

using namespace std;

// Enumeracion para los tipos de mensajes
enum TYPEMESSAGE {DEBUG, INFO, WARNING, ERROR, CRITICAL};

// Declaro las funciones y ademas hago sobre carga de funciones
void logMessage(string mensaje, int tipomensaje);
void logMessage(string mensaje, string archivo, int linea_error);
void logMessage(string mensaje, string usuario);

int main() {
    // Pruebas de los mensajes
    logMessage("Se esta debugeando el sistema", DEBUG);
    logMessage("Informacion: el sol sale todo los dias (conocimiento ampliativo)", INFO);
    logMessage("Se rompio la pc, llamar a soporte", WARNING);
    logMessage("Error se mojo la mother y la grafica", ERROR);
    logMessage("Esta lloviendo mucho", CRITICAL);
    logMessage("Este mensaje no llega a ningun lado", 5);
    logMessage("Exploto el codigo", "ejercicio-2.cpp", 30);
    logMessage("Acceso garantizado", "admin");
    try {
        cout << "Division entera de dos numeros" << endl;
        int x;
        cout << "Ingrese el valor de x: ";
        cin >> x;
        int y;
        cout << "Ingrese el valor de y: ";
        cin >> y;
        if (y == 0) {
            throw "Division por cero";
        }
        cout << x / y << endl;
    } catch (const char* e) {
        // Causo un error en runtime
        logMessage(e, "ejercicio-2.cpp", 32);
        return 1;
    }
    return 0;
}

void logMessage(string mensaje, int tipomensaje)
{
    // Abro el archivo en modo append
    ofstream outFile("Mensajes.txt", ios::app);
    if (outFile.is_open())
    {
        // Dependiendo del tipo de mensaje imprimo
        switch (tipomensaje)
        {
        case DEBUG:
            outFile << "[DEBUG] <" << mensaje <<">" <<  endl;
            break;
        case INFO:
            outFile << "[INFO] <" << mensaje <<">" <<  endl;
            break;
        case WARNING:
            outFile << "[WARNING] <" << mensaje <<">" <<  endl;
            break;
        case ERROR:
            outFile << "[ERROR] <" << mensaje <<">" <<  endl;
            break;
        case CRITICAL:
            outFile << "[CRITICAL] <" << mensaje <<">" <<  endl;
            break;
        
        default:
            outFile << "[UNKNOWN] <Error desconocido> "<<  endl;
            break;
        }
    }
    else
    {
        // Por si no se puede abrir el archivo
        cout << "Error al abrir el archivo" << endl;
    }
    outFile.close();
}

void logMessage(string mensaje, string archivo, int linea_error)
{
    // Mismo funcionamiento que la primera funcion
    ofstream outFile("Mensajes.txt", ios::app);
    if (outFile.is_open())
    {
        outFile << "[ERROR] <" << mensaje << "> [ARCHIVO: " << archivo << "][LINEA: " << linea_error <<"]" <<endl;
    }
    else
    {
        cout << "Error al abrir el archivo" << endl;
    }
    outFile.close();
}

void logMessage(string mensaje, string usuario)
{
    // Mismo funcionamiento que la primera funcion
    ofstream outFile("Mensajes.txt", ios::app);
    if (outFile.is_open())
    {
        outFile << "[SECURITY] <" << mensaje << "> [USUARIO: " << usuario <<"]" <<endl;
    }
    else
    {
        cout << "Error al abrir el archivo" << endl;
    }
    outFile.close();
}