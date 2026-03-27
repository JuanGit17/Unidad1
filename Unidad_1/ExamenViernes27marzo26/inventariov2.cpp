/*Sistema de gestion de inventario en una empresa, utilizando punteros, array, estructura y memoria
a)el usuario debe ingresar la cantidad de productos (minimo 10):
cada producto debe contener id, decripccion, cantidad y precio
b) mostrar productos en orden alfabetico.*/
#include <iostream>
#include <string>


struct producto {
    int id;
    std::string descripcion;
    int cantidad;
    float precio;
};

void ordenarInventario(producto* inventario, int n) {
    producto aux;
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (inventario[j].descripcion > inventario[j + 1].descripcion) {
                
                aux = inventario[j];
                inventario[j] = inventario[j + 1];
                inventario[j + 1] = aux;
            }
        }
    }
}

int main() {

   std::cout << "Programa de gestion de inventario" << std::endl;
   std::cout << "Llene los datos a continuacion:" << std::endl;
   
   
    int n;

   do {
    std::cout << "Ingrese la cantidad de produtos (minimo 10)" << std::endl;
    if (!(std::cin >> n)) {
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    } else if (n < 10) {
        std::cout<<"El minimo son 10 productos." << std::endl;

    } 



   } while (n < 10);
   std::cin.ignore();

   producto* inventario = new producto[n];

   for ( int i = 0; i < n; i++) {
    std::cout<< "Producto: " << i + 1 << std::endl;
    std::cout << "ID: "; 
    std::cin >> inventario[i].id;
    std::cin.ignore();
    std::cout << "Descripcion: "; getline(std::cin, inventario[i].descripcion);
    std::cout << "Cantidad: ";
    std::cin >> inventario[i].cantidad;
    std::cout << "Precio: ";
    std::cin >> inventario[i].precio;

   }
  

   ordenarInventario(inventario, n);

   std::cout << "Sus productos son: " << std::endl;
        for (int i = 0; i < n; i++) {
            std::cout << "ID: " << inventario[i].id; 
            std::cout<< " | Descripcion: " << inventario[i].descripcion; 
            std::cout<< " | Cantidad: " << inventario[i].cantidad; 
            std::cout<< " | Precio: " << inventario[i].precio << std::endl;
}

int borrarid;
    std::cout << "Si desea eliminar algun producto de la lista, ingrese su ID a continuacion: " << std::endl;
     std::cin >> borrarid;

      for (int i = 0; i < n; i++) {
        if (inventario[i].id == borrarid) {
            for (int j = i; j < n - 1; j++) inventario[j] = inventario[j + 1];
            n--;
            std::cout << "Lista actualizada: " << std::endl;
            for (int i = 0; i < n; i++) {
                std::cout << "ID: " << inventario[i].id; 
                std::cout<< " | Descripcion: " << inventario[i].descripcion; 
                std::cout<< " | Cantidad: " << inventario[i].cantidad; 
                std::cout<< " | Precio: " << inventario[i].precio << std::endl; 
        }
    }

    delete [] inventario;
    return 0;
}
}

/*Opcional: organizarlo con dos menues, uno con agregar, y otro para eliminar por id del producto, el producto*/