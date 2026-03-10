#include <iostream>

using namespace std;

// usaremos 'const' para el arreglo porque no vamos a modificar sus valores
void obtenerMinMax(const int *arr, int tam, int *min, int *max) {
    if (arr == nullptr || tam <= 0) return; // validacion de seguridad

    // inicializamos con el primer elemento
    *min = *max = *arr;

    // recorremos usando un puntero auxiliar que avanza
    const int *ptr = arr;
    for (int i = 0; i < tam; i++) {
        if (*ptr < *min) *min = *ptr;
        if (*ptr > *max) *max = *ptr;
        ptr++; // avanzamos a la siguiente direccion de memoria
    }
}

int main() {
    int datos[] = {15, 8, 42, 4, 23};
    int n = 5;
    int *p = datos; // puntero al inicio

    cout << "--- Registro de Memoria ---" << endl;
    for (int i = 0; i < n; i++) {
        cout << "[" << (p + i) << "] -> " << *(p + i) << endl;
    }

    int vMin, vMax;
    obtenerMinMax(datos, n, &vMin, &vMax);

    cout << "\n--- Rango Encontrado ---" << endl;
    cout << "Min: " << vMin << " | Max: " << vMax << endl;

    return 0;
}