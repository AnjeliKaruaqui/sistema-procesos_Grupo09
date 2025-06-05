struct NodoPila {
    int bloque;
    NodoPila* siguiente;
};

NodoPila* cima = NULL;

void asignarMemoria() {
    int bloque;
    cout << "?? N�mero del bloque a asignar: ";
    cin >> bloque;

    NodoPila* nuevo = new NodoPila;
    nuevo->bloque = bloque;
    nuevo->siguiente = cima;
    cima = nuevo;

    cout << "? Bloque " << bloque << " asignado a memoria.\n";
}

void liberarMemoria() {
    if (cima == NULL) {
        cout << "? No hay bloques en memoria.\n";
        return;
    }

    cout << "?? Liberando bloque: " << cima->bloque << endl;
    NodoPila* temp = cima;
    cima = cima->siguiente;
    delete temp;
}

void verMemoria() {
    if (cima == NULL) {
        cout << "?? Memoria vac�a.\n";
        return;
    }

    cout << "\n?? Estado actual de memoria:\n";
    NodoPila* aux = cima;
    while (aux != NULL) {
        cout << "- Bloque " << aux->bloque << endl;
        aux = aux->siguiente;
    }
}
