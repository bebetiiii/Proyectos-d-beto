#include <iostream>
using namespace std;

class Persona
{
private:
    string nombre;
    int edad;

public:
    Persona()
    {
        nombre = "";
        edad = 0;
    }

    string getNombre();
    int getEdad();

    void setNombre(string n);
    void setEdad(int e);

    void agregar();
    void mostrar();
};

string Persona::getNombre()
{
    return nombre;
}

void Persona::setNombre(string n)
{
    nombre = n;
}

void Persona::setEdad(int e)
{
    edad = e;
}

int Persona::getEdad()
{
    return edad;
}

void Persona::agregar()
{
    cout << "Ingresa tu nombre: ";
    cin >> nombre;
    cout << "Ingresa tu edad: ";
    cin >> edad;
}

void Persona::mostrar()
{
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
}

class Administrador
{
private:
    int contador;
    Persona lista_personas[10];

public:
    Administrador()
    {
        contador = 0;
    }

    void Agregar();
    void Mostrar();
    void Buscar();
    void Eliminar();
    void Menu();
};

void Administrador::Agregar()
{
    if (contador < 10)
    {
        Persona aux;
        aux.agregar();
        lista_personas[contador] = aux;
        contador++;
    }
    else
    {
        cout << "Lista llena." << endl;
    }
}

void Administrador::Mostrar()
{
    cout << "Lista de personas:" << endl;
    for (int i = 0; i < contador; i++)
    {
        lista_personas[i].mostrar();
    }
}

void Administrador::Buscar()
{
    string nom;
    bool encontrado = false;

    cout << "Ingresa el nombre que quieres buscar: ";
    cin >> nom;

    for (int i = 0; i < contador; i++)
    {
        if (nom == lista_personas[i].getNombre())
        {
            lista_personas[i].mostrar();
            encontrado = true;
            break;
            
        }
    }

    if (encontrado == false)
    {
        cout << "Persona no encontrada" << endl;
    }
}

void Administrador::Eliminar()
{
    string nom;
    bool encontrado = false;

    cout << "Ingresa el nombre de la persona a eliminar: ";
    cin >> nom;

    for (int i = 0; i < contador; i++)
    {
        if (nom == lista_personas[i].getNombre())
        {
            encontrado = true;
            for (int j = i; j < contador - 1; j++)
            {
                lista_personas[j] = lista_personas[j + 1];
            }
            contador--;
            cout << "Persona eliminada." << endl;
            break;
        }
    }

    if (!encontrado)
    {
        cout << "Persona no encontrada." << endl;
    }
}

void Administrador::Menu()
{
    int opc = 0;
    do
    {
        cout << "Bienvenido" << endl;
        cout << "1-Agregar" << endl;
        cout << "2-Mostrar" << endl;
        cout << "3-Buscar" << endl;
        cout << "4-Eliminar" << endl;
        cout << "5-Salir" << endl;
        cout << "Elige una opcion: ";
        cin >> opc;

        switch (opc)
        {
        case 1:
            Agregar();
            break;
        case 2:
            Mostrar();
            break;
        case 3:
            Buscar();
            break;
        case 4:
            Eliminar();
            break;
        case 5:
            cout << "Hasta luego." << endl;
            break;
        default:
            cout << "Opcion no valida." << endl;
        }

    } while (opc != 5);
}

int main()
{
    Administrador admin;
    admin.Menu();
    return 0;

}