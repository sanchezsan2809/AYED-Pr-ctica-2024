#include <iostream>
#include <stdio.h>
using namespace std;

/*
// 1)
struct Nodo
{
    int info;
    Nodo* sgte;
};
int pop(Nodo*& pila);
Nodo* insertarOrdenado(Nodo*& lista, int elem);
int desencolar(Nodo*& colaPrimero, Nodo*& colaUltimo);
Nodo* agregar(Nodo*& lista, int elem);

//a) 

Nodo* unir(Nodo*& pila, Nodo*& colaPrimero, Nodo*& colaUltimo)
{
    Nodo* lista = nullptr;

    while(pila != nullptr)
    {
        int info = pop(pila);
        insertarOrdenado(lista, info);
    }

    while(colaPrimero != nullptr)
    {
        int info = desencolar(colaPrimero, colaUltimo);
        insertarOrdenado(lista, info); 
    }

    return lista;
}

//b)
Nodo* intersecar (Nodo*& lista1, Nodo*& lista2)
{
    Nodo* aux1 = lista1;
    Nodo* listaInterseccion = nullptr;

    while(aux1 != nullptr)
    {
        Nodo* aux2 = lista2;
        while(aux2 != nullptr)
        {
            if(aux2->info == aux1->info)
            {
                int elem = aux1->info;
                agregar(listaInterseccion, elem);
                break;
            }
            aux2 = aux2->sgte;
        }
        aux1 = aux1->sgte;
    }

    return listaInterseccion;   
}

int pop(Nodo*& pila)
{
    int info = pila->info;
    Nodo* aux = pila;
    pila = pila->sgte;

    delete aux;
    return info;
}

int desencolar(Nodo*& colaPrimero, Nodo*& colaUltimo)
{
    int info = colaPrimero->info;
    Nodo* aux = colaPrimero;
    colaPrimero = colaPrimero->sgte;

    if(colaPrimero == nullptr)
    {
        colaUltimo = nullptr;
    }

    delete aux;
    return info;
}

Nodo* insertarOrdenado(Nodo*& lista, int elem)
{
    Nodo* nuevo = new Nodo();
    nuevo->info = elem;
    nuevo->sgte = nullptr; 

    if(lista == nullptr || lista->info >= elem)
    {
        nuevo->sgte = lista;
        lista = nuevo;
    }else
    {
        Nodo* aux = lista;
        Nodo* ant = nullptr;

        while(aux != nullptr && aux->info < elem)
        {
            ant =  aux;
            aux = aux->sgte;
        }
        nuevo->sgte = aux;
        ant->sgte = nuevo;

        return nuevo;
    }
}

Nodo* agregar(Nodo*& lista, int elem)
{
    Nodo* nuevo = new Nodo();
    nuevo->info = elem;
    nuevo->sgte = nullptr;

    if(lista == nullptr)
    {
        lista = nuevo;
    }else
    {
        Nodo* aux = lista;
        while(aux->sgte != nullptr)
        {
            aux = aux->sgte;
        }
        aux->sgte = nuevo;
    }
    return nuevo;
}

*/

/*
// 2)

struct reservasHotel
{
    int codigoHotel;
    int cantReservas;
    int cantDiasDisponibles;
};

struct reserva
{
    int codigoHotel;
    int cantDiasReservados;
};

struct Nodo
{
    reserva info;
    Nodo* sgte;
};

void actualizarReservasHotel(reservasHotel reservas[50], Nodo* listaReservas);
int buscarReservasHotel(reservasHotel reservas[50], int codigoHotel);

void actualizarReservasHotel(reservasHotel reservas[50], Nodo* listaReservas)
{
    Nodo* aux = listaReservas;
    while(aux != nullptr)
    {
        int pos = buscarReservasHotel(reservas, aux->info.codigoHotel);
        if(pos >= 0)
        {
        reservas[pos].cantReservas++;
        reservas[pos].cantDiasDisponibles -= aux->info.cantDiasReservados;
        }
        aux = aux->sgte;
    }
}

int buscarReservasHotel(reservasHotel reservas[50], int codigoHotel)
{
    int p = 0;
    int u = 49;
    int c; 
    bool encontrado = false;

    while(p <= u && !encontrado)
    {
        c = (p + u) / 2;
        reservasHotel hotel = reservas[c];

        encontrado = hotel.codigoHotel == codigoHotel; 
        p = hotel.codigoHotel < codigoHotel ? c + 1 : p;
        u = hotel.codigoHotel > codigoHotel ? c - 1 : u;
    }

    if(encontrado)
    {
        return c;
    }else
    {
        return -1;
    }
    
}

/* 
En primer lugar, considero más eficiente la estrategia de recorrer la lista de reservas
en comparación a una en la que se recorra el vector de reservas de los hoteles. Esto se debe
a que al iterar sobre la lista de reservas, se asegura que cada reserva se procesa y modifica
el vector de reservas de los hoteles de manera directa y específica. 
Considero también que modularizar el algoritmo de búsqueda de reservas en el vector mejora 
la claridad y la mantenibilidad del código. Esto no sólo hace que el código sea más facil de
entender, sino que también facilita las correcciones y actualizaciones futuras. 
*/

/**/

// 3)

struct Producto
{
    int codigoProducto;
    double peso;
    char tipo;
    int productosEnStock;
};

struct Nodo
{
    Producto info;
    Nodo* sgte;
};



Nodo* insertarOrdenado(Nodo*& lista, Producto);
Nodo* agregarSinRepetir(Nodo*& lista, Producto producto);
Nodo* agregar(Nodo*& lista, Producto producto);
bool seEncuentra(Nodo* lista, Producto producto);
FILE* generarArchivoOrdenado(Nodo* archivoOrdenado);
void mostrarLista(Nodo* lista);

int main()
{
    FILE* f = fopen("STOCK.dat", "r+b");

    Producto producto; 
    Nodo* archivoOrdenado = nullptr;
    Nodo* productosSinStock = nullptr;
    Nodo* productosPesadosYBebidas = nullptr;

    fread(&producto, sizeof (Producto),1, f);
    while(!feof(f))
    {
        insertarOrdenado(archivoOrdenado, producto);
        if (producto.productosEnStock == 0)
        {
            agregarSinRepetir(productosSinStock, producto);
        }
        if (producto.peso > 100 || producto.tipo == 'B')
        {
            agregarSinRepetir(productosPesadosYBebidas, producto);
        }
        fread(&producto, sizeof (Producto),1, f);
    }

    fclose(f);

    f = generarArchivoOrdenado(archivoOrdenado);

    cout << "Lista de productos sin stock: " << endl;
    mostrarLista(productosSinStock);

    cout << "Lista de productos pesados (más de 100 kg) y bebidas: " << endl;
    mostrarLista(productosPesadosYBebidas);
}


Nodo* insertarOrdenado(Nodo*& lista, Producto producto)
{
    Nodo* nuevo = new Nodo();
    nuevo->info = producto;
    nuevo->sgte = nullptr;

    if(lista->info.codigoProducto > producto.codigoProducto || lista == nullptr)
    {
        nuevo->sgte = lista;
        lista = nuevo;
    }else
    {        
        Nodo* aux = lista;
        Nodo* ant = nullptr;

        while(aux != nullptr && aux->info.codigoProducto < producto.codigoProducto)
        {
            ant = aux;
            aux = aux->sgte;
        }

        ant->sgte = nuevo;
        nuevo->sgte = aux;    
    }
    
    return nuevo;
}

Nodo* agregarSinRepetir(Nodo*& lista, Producto producto)
{
    Nodo* nuevo = nullptr;
    if(!seEncuentra(lista, producto))
    {
         nuevo = agregar(lista, producto);
    }

    return nuevo;
}

bool seEncuentra(Nodo* lista, Producto producto)
{
    Nodo* aux = lista;
    while(aux != nullptr)
    {
        if(aux->info.codigoProducto == producto.codigoProducto)
        {
            return true;
        }
        aux = aux->sgte;
    }
    return false;
}

Nodo* agregar(Nodo*& lista, Producto producto)
{
    Nodo* nuevo = new Nodo();
    nuevo->info = producto;
    nuevo->sgte = nullptr; 

    if(lista == nullptr)
    {
        nuevo->sgte = lista;
        lista = nuevo;
    }else
    {
        Nodo* aux = lista;
        while(aux != nullptr)
        {
            aux = aux->sgte;
        }
        aux->sgte = nuevo;
    }   
    return nuevo;
}

FILE* generarArchivoOrdenado(Nodo* lista)
{
    FILE* f = fopen("STOCK.dat", "w+b");
    Nodo* aux = lista;

    while(aux != nullptr)
    {
        Producto producto = aux->info;
        fwrite(&producto, sizeof (Producto), 1, f);
        aux = aux->sgte;
    }

    fclose(f);
    return f;
}

void mostrarLista(Nodo* lista)
{
    Nodo* aux = lista;
    while(aux != nullptr)
    {
        cout << "Código de producto: " << aux->info.codigoProducto << endl;
        aux = aux->sgte;
    }
}

