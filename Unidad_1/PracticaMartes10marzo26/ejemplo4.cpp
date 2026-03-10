#include <iostream>

using namespace std;

int main() {

    int tam;
    cout << "¿Cuantos elementos quieres? ";
    cin >> tam;

    int* arreglo = new int[tam];

    delete[] arreglo;

    return 0;
}