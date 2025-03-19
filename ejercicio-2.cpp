#include <iostream>
#include <string>
#include <fstream>

using namespace std;

enum TYPEMESSAGE {DEBUG, INFO, WARNING, ERROR, CRITICAL};

void logMessage(string mensaje, int tipomensaje);

int main() {
    logMessage("Se esta debugeando el sistema", DEBUG);
    logMessage("Informacion: el sol sale todo los dias (conocimiento ampliativo)", INFO);
    logMessage("Se rompio la pc, llamar a soporte", WARNING);
    logMessage("Error se mojo la mother y la grafica", ERROR);
    logMessage("Esta lloviendo mucho", CRITICAL);
    logMessage("Este mensaje no llega a ningun lado", 5);
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