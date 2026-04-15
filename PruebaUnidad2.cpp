#include <iostream>
#include <string>
using namespace std;

//Clase producto
class Producto {
private:
    string nombre;
    string categoria;
    int stock;

public:
    // Constructor
    Producto(string n = "", string c = "", int s = 0) {
        nombre = n;
        categoria = c;
        stock = s;
    }

    // Métodos get y set (encapsulamiento)
    string getNombre() { return nombre; }
    string getCategoria() { return categoria; }
    int getStock() { return stock; }

    void setStock(int s) {
        if (s >= 0)
            stock = s;
    }

    void mostrar() {
        cout << "Nombre: " << nombre
             << " | Categoria: " << categoria
             << " | Stock: " << stock << endl;
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

        cout << "Nombre: ";
        cin >> nombre;

        cout << "Categoria: ";
        cin >> categoria;

        cout << "Stock: ";
        while (!(cin >> stock) || stock < 0) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Dato invalido. Intente de nuevo: ";
        }

        productos[total] = Producto(nombre, categoria, stock);
        total++;
    }

    void mostrar() {
        for (int i = 0; i < total; i++) {
            cout << i << ". ";
            productos[i].mostrar();
        }
    }

    // BUSQUEDA LINEAL
    int buscar(string nombre) {
        for (int i = 0; i < total; i++) {
            if (productos[i].getNombre() == nombre)
                return i;
        }
        return -1;
    }

    /* ORDENAMIENTO BURBUJA
    //void ordenar(string nombre) {
        int num;
        cout<<"Ingrese el numero de orden: "<<endl;
        cin>>num;

        for (int i = 0; i < total; i++) {
            if (productos[i].getNombre() == nombre)
                return i;
        }
    }*/

};

// ================= RECURSIVIDAD =================
int intentosRestantes(int n) {
    if (n == 0)
        return 0;
    return 1 + intentosRestantes(n - 1);
}

// ================= AHORCADO =================
void Ahorcado() {
    string palabra = "codigo";
    string oculto = "______";
    int intentos = 6;
    char letra;

    while (intentos > 0 && oculto != palabra) {
        cout << "Palabra: " << oculto << endl;
        cout << "Intentos: " << intentos << endl;
        cout << "Letra: ";
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
        cout << "Ganaste!\n";
    else
        cout << "Perdiste. Era: " << palabra << endl;
}

// ================= MAIN =================
int main() {
    Inventario inv;
    int opcion;

    do {
        cout << "--- MENU PRINCIPAL ---"<<endl;
        cout << "1. Inventario\n";
        cout << "2. Ahorcado\n";
        cout << "3. Mostrar intentos (recursivo)\n";
        cout << "4. Salir"<<endl;
        cout << "Opcion: ";

        while (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Dato invalido: ";
        }

        switch (opcion) {
        case 1: {
            int op2;
            do {
                cout << "\n============INVENTARIO============"<<endl;
                cout << "1. Agregar" <<endl; 
                cout << "2. Mostrar" <<endl;
                cout << "3. Buscar" <<endl;
                cout << "4. Ordenar" <<endl;
                cout << "5. Volver" <<endl;
                cin >> op2;

                
                switch (op2)
                {
                case 1: inv.agregarProducto();
                    /* code */
                    break;

                case 2: inv.mostrar();;
                    /* code */
                    break;
                    
                case 3: {
                    string nombre;
                    cout << "Buscar: ";
                    cin >> nombre;
                    int pos = inv.buscar(nombre);
                    if (pos != -1) cout << "Encontrado";
                    else cout << "No encontrado";
                    };
                    /* code */
                    break;
                
                case 4: {
                    string nombre;
                    cout << "Buscar nombre: ";
                    cin >> nombre;
                    int pos = inv.buscar(nombre);
                    if (pos != -1) cout << "Encontrado";
                    else cout << "No encontrado";
                    };
                    /* code */
                    break;    


                default:
                    break;
                }

                //else if (op2 == 4) inv.ordenar();
                
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
            cout << "Saliendo..."<<endl;
            break;

        default:
            cout << "Opcion invalida"<<endl;
        }

    } while (opcion != 4);

    return 0;
}