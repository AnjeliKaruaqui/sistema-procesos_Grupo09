void menu() {
    int op;
    do {
        cout << "\n--- MENU PRINCIPAL: SISTEMA DE GESTION DE PROCESOS ---\n";
        cout << "1. Registrar proceso\n";
        cout << "2. Mostrar lista de procesos\n";
        cout << "3. Encolar proceso a CPU\n";
        cout << "4. Ejecutar siguiente proceso\n";
        cout << "5. Ver cola de CPU\n";
        cout << "6. Asignar bloque de memoria\n";
        cout << "7. Liberar bloque de memoria\n";
        cout << "8. Ver estado de memoria\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> op;

        switch (op) {
            case 1: insertarProceso(); break;
            case 2: mostrarProcesos(); break;
            case 3: encolarProceso(); break;
            case 4: ejecutarProceso(); break;
            case 5: mostrarCola(); break;
            case 6: asignarMemoria(); break;
            case 7: liberarMemoria(); break;
            case 8: verMemoria(); break;
        }
    } while (op != 0);
}
