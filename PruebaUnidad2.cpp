#include <iostream>
#include <string>
using namespace std;

// ================= CLASE PRODUCTO =================
class Producto {
private:
    string nombre;
    string categoria;
    int stock;
    float precio;

public:
    Producto(string n = "", string c = "", int s = 0, float p = 0) {
        nombre = n;
        categoria = c;
        stock = s;
        precio = p;
    }

    string getNombre() { return nombre; }
    string getCategoria() { return categoria; }
    int getStock() { return stock; }
    float getPrecio() { return precio; }

    void setStock(int s) {
        if (s >= 0) stock = s;
    }

    void setPrecio(float p) {
        if (p >= 0) precio = p;
    }

    void mostrar() {
        cout << "Nombre: " << nombre << endl;
        cout << "Categoria: " << categoria << endl;
        cout << "Stock: " << stock << endl;
        cout << "Precio: " << precio << endl;
        cout << "----------------------" << endl;
    }
};

// ================= CLASE INVENTARIO =================
class Inventario {
private:
    Producto productos[50];
    int total;

public:
    Inventario() { total = 0; }

    void agregarProducto() {
        string nombre, categoria;
        int stock;
        float precio;

        cout << "Nombre: " << endl;
        cin >> nombre;

        cout << "Categoria: " << endl;
        cin >> categoria;

        cout << "Stock: " << endl;
        while (!(cin >> stock) || stock < 0) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Dato invalido. Intente de nuevo: " << endl;
        }

        cout << "Precio: " << endl;
        while (!(cin >> precio) || precio < 0) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Dato invalido. Intente de nuevo: " << endl;
        }

        productos[total] = Producto(nombre, categoria, stock, precio);
        total++;
    }

    void mostrar() {
        if (total == 0) {
            cout << "Inventario vacio" << endl;
            return;
        }

        for (int i = 0; i < total; i++) {
            cout << i + 1 << "." << endl;
            productos[i].mostrar();
        }
    }

    int buscar(string nombre) {
        for (int i = 0; i < total; i++) {
            if (productos[i].getNombre() == nombre)
                return i;
        }
        return -1;
    }

    void ordenar(int pos1, int pos2) {
        if (pos1 >= 0 && pos1 < total && pos2 >= 0 && pos2 < total) {
            Producto temp = productos[pos1];
            productos[pos1] = productos[pos2];
            productos[pos2] = temp;
            cout << "Productos intercambiados correctamente" << endl;
        } else {
            cout << "Posiciones invalidas" << endl;
        }
    }
};

// RECURSIVIDAD 
int intentosRestantes(int n) {
    if (n == 0)
        return 0;
    return 1 + intentosRestantes(n - 1);
}

// AHORCADO 
void Ahorcado() {
    string palabra = "codigo";
    string oculto = "______";
    int intentos = 6;
    char letra;

    while (intentos > 0 && oculto != palabra) {
        cout << "Palabra: " << oculto << endl;
        cout << "Intentos: " << intentos << endl;
        cout << "Letra: " << endl;
        cin >> letra;

        bool acierto = false;

        for (int i = 0; i < palabra.length(); i++) {
            if (palabra[i] == letra) {
                oculto[i] = letra;
                acierto = true;
            }
        }

        if (!acierto)
            intentos--;
    }

    if (oculto == palabra)
        cout << "Ganaste!" << endl;
    else
        cout << "Perdiste. Era: " << palabra << endl;
}

// MAIN 
int main() {
    Inventario inv;
    int opcion;

    do {
        cout << "--- MENU PRINCIPAL ---" << endl;
        cout << "1. Inventario" << endl;
        cout << "2. Ahorcado" << endl;
        cout << "3. Mostrar intentos (recursivo)" << endl;
        cout << "4. Salir" << endl;
        cout << "Opcion: " << endl;

        while (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Dato invalido: " << endl;
        }

        switch (opcion) {
        case 1: {
            int op2;
            do {
                cout << "============ INVENTARIO ============" << endl;
                cout << "1. Agregar" << endl;
                cout << "2. Mostrar" << endl;
                cout << "3. Buscar" << endl;
                cout << "4. Ordenar" << endl;
                cout << "5. Volver" << endl;
                cout << "Opcion: " << endl;

                while (!(cin >> op2)) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Opcion invalida: " << endl;
                }

                switch (op2) {
                case 1:
                    inv.agregarProducto();
                    break;

                case 2:
                    inv.mostrar();
                    break;

                case 3: {
                    string nombre;
                    cout << "Buscar: " << endl;
                    cin >> nombre;
                    int pos = inv.buscar(nombre);
                    if (pos != -1)
                        cout << "Encontrado en posicion " << pos + 1 << endl;
                    else
                        cout << "No encontrado" << endl;
                    break;
                }

                case 4: {
                    int p1, p2;
                    cout << "Posicion 1: " << endl;
                    cin >> p1;
                    cout << "Posicion 2: " << endl;
                    cin >> p2;

                    inv.ordenar(p1 - 1, p2 - 1);
                    break;
                }

                case 5:
                    cout << "Volviendo..." << endl;
                    break;

                default:
                    cout << "Opcion invalida" << endl;
                }

            } while (op2 != 5);
            break;
        }

        case 2:
            Ahorcado();
            break;

        case 3:
            cout << "Intentos totales: " << intentosRestantes(6) << endl;
            break;

        case 4:
            cout << "Saliendo..." << endl;
            break;

        default:
            cout << "Opcion invalida" << endl;
        }

    } while (opcion != 4);

    return 0;
}