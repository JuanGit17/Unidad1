#include <iostream>

using namespace std;

void swap(int *a, int *b) {
    // ESCRIBA SU LÓGICA AQUÍ
    int aux = *a;
    *a = *b;
    *b = aux;
}

int main() {
    int x = 50, y = 10;
    cout << "Antes: x=" << x << ", y=" << y << endl;

    // Llamada a la función
    swap(&x, &y);

    cout << "Después: x=" << x << ", y=" << y << endl;
    return 0;
}