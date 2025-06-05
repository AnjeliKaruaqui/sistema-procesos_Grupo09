#include <iostream>
#include <string>
using namespace std;

struct Proceso {
    int id;
    char nombre[30];
    int prioridad;
    Proceso* siguiente;
};

Proceso* lista = NULL;
int contadorID = 1;

void insertarProceso() {
    Proceso* nuevo = new Proceso;
    nuevo->id = contadorID++;
    cout << "\nIngrese nombre del proceso: ";
    cin >> nuevo->nombre;
    cout << "Ingrese prioridad (1-10): ";
    cin >> nuevo->prioridad;
    nuevo->siguiente = NULL;

    if (lista == NULL) {
        lista = nuevo;
    } else {
        Proceso* aux = lista;
        while (aux->siguiente != NULL) {
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo;
    }

    cout << "Proceso registrado con exito.\n";
}

void mostrarProcesos() {
    if (lista == NULL) {
        cout << "No hay procesos registrados.\n";
        return;
    }

    Proceso* aux = lista;
    cout << "\nProcesos registrados:\n";
    while (aux != NULL) {
        cout << "ID: " << aux->id << " | Nombre: " << aux->nombre << " | Prioridad: " << aux->prioridad << endl;
        aux = aux->siguiente;
    }
}

int main() {
    int opcion;
    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Insertar proceso\n";
        cout << "2. Mostrar procesos\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                insertarProceso();
                break;
            case 2:
                mostrarProcesos();
                break;
            case 3:
                cout << "Saliendo del programa.\n";
                break;
            default:
                cout << "Opcion no valida.\n";
                break;
        }
    } while(opcion != 3);

    return 0;
}

