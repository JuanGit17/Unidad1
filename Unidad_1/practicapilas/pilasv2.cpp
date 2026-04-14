#include <iostream>
#include <stdlib.h>


struct Nodo {
    int valor;
    Nodo *siguiente;
};


void push(Nodo *&pila, int n);          
void mostrarPila(Nodo *pila);           
void pop(Nodo *&pila);                  
void vaciarPila(Nodo *&pila);           

int main() {
    Nodo *pila = nullptr; 
    int opcion, cantidad, dato;

    do {
        std::cout << "SISTEMA DE GESTION DE PILAS" << std::endl;
        std::cout << "1. Insertar un numero" << std::endl;
        std::cout << "2. Insertar multiples numeros" << std::endl;
        std::cout << "3. Ver contenidos de la pila" << std::endl;
        std::cout << "4. Eliminar el dato de la cima" << std::endl;
        std::cout << "5. Vaciar toda la pila" << std::endl;
        std::cout << "6. Salir" << std::endl;
        std::cout << "Seleccione una operacion: ";
        std::cin >> opcion;

        switch(opcion) {
            case 1:
                std::cout << "Ingrese el valor: ";
                std::cin >> dato;
                push(pila, dato);
                break;

            case 2:
                std::cout << "¿Cuantos elementos desea ingresar?: ";
                std::cin >> cantidad;
                for(int i = 0; i < cantidad; i++) {
                    std::cout << "(" << i + 1 << "/" << cantidad << ") Valor: ";
                    std::cin >> dato;
                    push(pila, dato);
                }
                break;

            case 3:
                mostrarPila(pila);
                break;

            case 4:
                pop(pila);
                break;

            case 5:
                std::cout << "Iniciando limpieza de memoria..." << std::endl;
                vaciarPila(pila);
                break;

            case 6:
                std::cout << "Desconectando sistema." << std::endl;
                break;

            default:
                std::cout << "Alerta: Codigo de operacion invalido." << std::endl;
        }

    } while(opcion != 6);

    return 0;
}


void push(Nodo *&pila, int n) {
    Nodo *nuevo_nodo = new Nodo(); 
    nuevo_nodo->valor = n;         
    nuevo_nodo->siguiente = pila;  
    pila = nuevo_nodo;             
    std::cout << "  > Nodo [" << n << "] registrado." << std::endl;
}

void mostrarPila(Nodo *pila) {
    Nodo *aux = pila;
    if(aux == nullptr) {
        std::cout << "\n[!] La pila esta vacia actualmente." << std::endl;
    } else {
        std::cout << "\nEstado actual de la Pila (Cima -> Fondo):" << std::endl;
        while(aux != nullptr) {
            std::cout << "| " << aux->valor << " |" << std::endl;
            aux = aux->siguiente;
        }
        std::cout << "| NULL |" << std::endl;
    }
}


void pop(Nodo *&pila) {
    if(pila != nullptr) {
        Nodo *aux = pila;
        int v = aux->valor;
        pila = aux->siguiente; 
        delete aux;            
        std::cout << "  > Elemento [" << v << "] eliminado de la cima." << std::endl;
    } else {
        std::cout << "\n[!] Error: No hay elementos para eliminar." << std::endl;
    }
}


void vaciarPila(Nodo *&pila) {
    if(pila == nullptr) {
        std::cout << "La pila ya esta limpia." << std::endl;
    } else {
        while(pila != nullptr) {
            pop(pila); 
        }
        std::cout << "Sistema de memoria liberado correctamente." << std::endl;
    }
}