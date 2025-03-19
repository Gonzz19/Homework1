#include <iostream>
#include <string>
#include <fstream>

using namespace std;

enum TYPEMESSAGE {DEBUG, INFO, WARNING, ERROR, CRITICAL};

void logMessage(string mensaje, int tipomensaje);
void logMessage(string mensaje, string archivo, int linea_error);
void logMessage(string mensaje, string usuario);

int main() {
    logMessage("Se esta debugeando el sistema", DEBUG);
    logMessage("Informacion: el sol sale todo los dias (conocimiento ampliativo)", INFO);
    logMessage("Se rompio la pc, llamar a soporte", WARNING);
    logMessage("Error se mojo la mother y la grafica", ERROR);
    logMessage("Esta lloviendo mucho", CRITICAL);
    logMessage("Este mensaje no llega a ningun lado", 5);
    logMessage("Exploto el codigo", "ejercicio-2.cpp", 30);
    logMessage("Acceso garantizado", "admin");
    return 0;
}

void logMessage(string mensaje, int tipomensaje)
{
    ofstream outFile("Mensajes.txt", ios::app);
    if (outFile.is_open())
    {
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
        cout << "Error al abrir el archivo" << endl;
    }
    outFile.close();
}

void logMessage(string mensaje, string archivo, int linea_error)
{
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