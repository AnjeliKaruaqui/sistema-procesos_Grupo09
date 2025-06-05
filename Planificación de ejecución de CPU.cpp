#include <iostream>
#include <string>
using namespace std;

struct Proceso {
    int id;
    char nombre[30];
    int prioridad;
    Proceso* siguiente;
};

// Lista enlazada de procesos
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

// Cola de procesos con prioridad
struct NodoCola {
    Proceso* proceso;
    NodoCola* siguiente;
};

NodoCola* frente = NULL;

void encolarProceso() {
    int idBuscar;
    cout << "ID del proceso a encolar: ";
    cin >> idBuscar;

    Proceso* actual = lista;
    while (actual != NULL && actual->id != idBuscar) {
        actual = actual->siguiente;
    }

    if (actual == NULL) {
        cout << "Proceso no encontrado.\n";
        return;
    }

    NodoCola* nuevo = new NodoCola;
    nuevo->proceso = actual;
    nuevo->siguiente = NULL;

    if (frente == NULL || actual->prioridad > frente->proceso->prioridad) {
        nuevo->siguiente = frente;
        frente = nuevo;
    } else {
        NodoCola* temp = frente;
        while (temp->siguiente != NULL && temp->siguiente->proceso->prioridad >= actual->prioridad) {
            temp = temp->siguiente;
        }
        nuevo->siguiente = temp->siguiente;
        temp->siguiente = nuevo;
    }

    cout << "Proceso encolado en la CPU.\n";
}

void ejecutarProceso() {
    if (frente == NULL) {
        cout << "No hay procesos en la cola.\n";
        return;
    }

    cout << "Ejecutando: " << frente->proceso->nombre << " (Prioridad: " << frente->proceso->prioridad << ")\n";
    NodoCola* temp = frente;
    frente = frente->siguiente;
    delete temp;
}

void mostrarCola() {
    if (frente == NULL) {
        cout << "Cola vacia.\n";
        return;
    }

    cout << "\nCola de procesos (por prioridad):\n";
    NodoCola* aux = frente;
    while (aux != NULL) {
        cout << "- " << aux->proceso->nombre << " (P: " << aux->proceso->prioridad << ")\n";
        aux = aux->siguiente;
    }
}

int main() {
    int opcion;
    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Insertar proceso\n";
        cout << "2. Mostrar procesos\n";
        cout << "3. Encolar proceso\n";
        cout << "4. Ejecutar siguiente proceso\n";
        cout << "5. Mostrar cola\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: insertarProceso(); break;
            case 2: mostrarProcesos(); break;
            case 3: encolarProceso(); break;
            case 4: ejecutarProceso(); break;
            case 5: mostrarCola(); break;
            case 6: cout << "Saliendo del programa.\n"; break;
            default: cout << "Opcion no valida.\n"; break;
        }

    } while (opcion != 6);

    return 0;
}
