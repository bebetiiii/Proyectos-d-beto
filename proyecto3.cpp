#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class Producto {
private:
    int id;
    string nombre;
    double precio;
    int stock;

public:
    Producto(int _id, string _nombre, double _precio, int _stock) 
        : id(_id), nombre(_nombre), precio(_precio), stock(_stock) {}

    int getId() const { return id; }
    string getNombre() const { return nombre; }
    double getPrecio() const { return precio; }
    int getStock() const { return stock; }

    void setStock(int _stock) { stock = _stock; }

    void mostrarProducto() const {
        cout << left << setw(10) << id << setw(20) << nombre << setw(10) << precio << setw(10) << stock << endl;
    }
};

class Inventario {
private:
    vector<Producto> productos;

public:
    void agregarProducto(const Producto& prod) {
        productos.push_back(prod);
    }

    void mostrarInventario() const {
        cout << left << setw(10) << "ID" << setw(20) << "Nombre" << setw(10) << "Precio" << setw(10) << "Stock" << endl;
        for (const auto& prod : productos) {
            prod.mostrarProducto();
        }
    }

    void cargarInventario(const string& archivo) {
        ifstream inFile(archivo);
        if (inFile.is_open()) {
            int id, stock;
            double precio;
            string nombre;

            while (inFile >> id >> nombre >> precio >> stock) {
                agregarProducto(Producto(id, nombre, precio, stock));
            }
            inFile.close();
        } else {
            cout << "No se pudo abrir el archivo" << endl;
        }
    }

    void guardarInventario(const string& archivo) const {
        ofstream outFile(archivo);
        if (outFile.is_open()) {
            for (const auto& prod : productos) {
                outFile << prod.getId() << " " << prod.getNombre() << " "
                        << prod.getPrecio() << " " << prod.getStock() << endl;
            }
            outFile.close();
        } else {
            cout << "No se pudo abrir el archivo" << endl;
        }
    }

    Producto* buscarProducto(int id) {
        for (auto& prod : productos) {
            if (prod.getId() == id) {
                return &prod;
            }
        }
        return nullptr;
    }

    void actualizarStock(int id, int nuevoStock) {
        Producto* prod = buscarProducto(id);
        if (prod) {
            prod->setStock(nuevoStock);
            cout << "Stock actualizado" << endl;
        } else {
            cout << "Producto no encontrado" << endl;
        }
    }
};

int main() {
    Inventario inventario;

    inventario.cargarInventario("inventario.txt");

    inventario.agregarProducto(Producto(101, "Laptop", 1200.99, 10));
    inventario.agregarProducto(Producto(102, "Teclado", 45.50, 20));

    inventario.mostrarInventario();

    inventario.actualizarStock(101, 8);

    inventario.mostrarInventario();

    inventario.guardarInventario("inventario.txt");

    return 0;
}