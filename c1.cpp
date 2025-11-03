#include <iostream>
#include <string.h>

using namespace std;

struct Producto{
    char nombre[50];
    double precio;
    int cantidad;
};

// FUNCIÓN MOSTRAR TODOS LOS PRODUCTOS
void mostrarProductos(Producto productos[], int n) {
    cout << "\n=== LISTA DE PRODUCTOS ===\n\n";
    
    if (n == 0) {
        cout << "No hay productos.\n";
        return;
    }
    
    for (int i = 0; i < n; i++) {
        cout << "Producto " << (i + 1) << ":\n";
        cout << "  Nombre: " << productos[i].nombre << endl;
        cout << "  Precio: $" << productos[i].precio << endl;
        cout << "  Cantidad: " << productos[i].cantidad << endl;
        cout << "-------------------------\n";
    }
}

// Ejemplo de uso
int main() {
    Producto productos[100];
    int total = 0;
    
    // Llamar la función
    mostrarProductos(productos, total);
    
    return 0;
}