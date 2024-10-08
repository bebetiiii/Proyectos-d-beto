#include <iostream>
#include <string>

using namespace std;

const int MAX_ENVIOS = 100;

struct Envio {
    string nombre; 
    string destino; 
    float cantidadPlastico; 
    string fechaSalida; 
};

class BaseDeDatosEnvios {
private:
    Envio envios[MAX_ENVIOS];
    int contador;

public:
    BaseDeDatosEnvios() : contador(0) {}

    void agregarEnvio() {
        if (contador >= MAX_ENVIOS) {
            cout << "Límite de envíos alcanzado." << endl;
            return;
        }

        cout << "Ingrese el nombre del paquete: ";
        cin >> envios[contador].nombre;
        cout << "Ingrese el destino del paquete: ";
        cin >> envios[contador].destino;
        cout << "Ingrese la cantidad de plástico (kg): ";
        cin >> envios[contador].cantidadPlastico;
        cout << "Ingrese la fecha de salida (DD/MM/AAAA): ";
        cin >> envios[contador].fechaSalida;

        contador++;
        cout << "Envio agregado exitosamente." << endl;
    }

    void mostrarEnvios() {
        if (contador == 0) {
            cout << "No hay envíos registrados." << endl;
            return;
        }

        cout << "Listado de envíos:" << endl;
        for (int i = 0; i < contador; i++) {
            cout << "Nombre: " << envios[i].nombre << ", Destino: " << envios[i].destino
                 << ", Cantidad de plástico: " << envios[i].cantidadPlastico << " kg, "
                 << "Fecha de salida: " << envios[i].fechaSalida << endl;
        }
    }

    void buscarEnvio() {
        string nombreBuscado;
        cout << "Ingrese el nombre del paquete a buscar: ";
        cin >> nombreBuscado;

        for (int i = 0; i < contador; i++) {
            if (envios[i].nombre == nombreBuscado) {
                cout << "Envio encontrado: " << endl;
                cout << "Nombre: " << envios[i].nombre << ", Destino: " << envios[i].destino
                     << ", Cantidad de plástico: " << envios[i].cantidadPlastico << " kg, "
                     << "Fecha de salida: " << envios[i].fechaSalida << endl;
                return;
            }
        }
        cout << "Envio no encontrado." << endl;
    }
};

int main() {
    BaseDeDatosEnvios baseDeDatos;
    int opcion;

    do {
        cout << "\nMenu de opciones:" << endl;
        cout << "1. Agregar Envio" << endl;
        cout << "2. Mostrar Envios" << endl;
        cout << "3. Buscar Envio" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                baseDeDatos.agregarEnvio();
                break;
            case 2:
                baseDeDatos.mostrarEnvios();
                break;
            case 3:
                baseDeDatos.buscarEnvio();
                break;
            case 4:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while (opcion != 4);

    return 0;
}