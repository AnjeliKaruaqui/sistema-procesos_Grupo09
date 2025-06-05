#include <iostream>
using namespace std;

// -----------------------------------------------
// PROYECTO: Sistema de Gestion de Procesos
// ESTRUCTURA DE DATOS DINÁMICAS DESDE CERO
// Autores: Equipo 09
// -----------------------------------------------

// ------------------ LISTA ENLAZADA ------------------
// Estructura para almacenar los procesos registrados
struct Proceso {
    int id;                    // ID del proceso
    char nombre[30];           // Nombre del proceso
    int prioridad;             // Prioridad (1 a 10)
    Proceso* siguiente;        // Puntero al siguiente nodo
};

// Variable global para el inicio de la lista
Proceso* lista = NULL;

// ------------------ COLA DE PRIORIDAD ------------------
// Estructura para la planificacion de procesos en CPU
struct NodoCola {
    Proceso* proceso;          // Apunta al proceso de la lista
    NodoCola* siguiente;       // Siguiente en la cola
};

// Variable global para el frente de la cola
NodoCola* frente = NULL;

// ------------------ PILA PARA GESTION DE MEMORIA ------------------
// Estructura para simular bloques de memoria asignados
struct NodoPila {
    int bloque;                // Identificador del bloque
    NodoPila* siguiente;       // Puntero al siguiente bloque
};

// Variable global para la cima de la pila
NodoPila* cima = NULL;

// ------------------ FUNCION PRINCIPAL ------------------
int main() {
    // Menú en desarrollo
    cout << "Sistema de GestiOn de Procesos - [EN DESARROLLO]" << endl;
    return 0;
}
