#include <string.h>
#include <iostream>
using namespace std;


//1)

struct InfoNodoLista
{
    int campo1;
    char campo2[20];
    float campo3;
    int campo4;
};

struct NodoLista
{
    InfoNodoLista info;
    NodoLista* sgte;
};

struct InfoNodoSublista
{
    float campo3;
    int campo4;
};

struct NodoSublista
{
    InfoNodoSublista info;
    NodoSublista* sgte;
};


struct InfoNodoListaResultado
{
    int campo1;
    char campo2[20];
    NodoSublista* sublista;
};

struct NodoListaResultado
{
    InfoNodoListaResultado info;
    NodoListaResultado* sgte;
};

NodoListaResultado* insertarOrdenado(NodoListaResultado*& listaResultado, InfoNodoLista info);
NodoListaResultado* insertarSinRepetir(NodoListaResultado*& listaResultado, InfoNodoLista info);
InfoNodoLista pop(NodoLista*& lista);
NodoSublista* agregar(NodoSublista*& sublista, InfoNodoLista info);

// 2)
NodoListaResultado* cargarListaDeListas(NodoLista*& lista)
{
    NodoListaResultado* listaResultado = nullptr;

    while(lista != nullptr)
    {
        InfoNodoLista infoLista = pop(lista);
        insertarSinRepetir(listaResultado, infoLista);
    }

    return listaResultado;
}

InfoNodoLista pop(NodoLista*& lista)
{
    InfoNodoLista info = lista->info;
    NodoLista* aux = lista;
    lista = lista->sgte;

    delete aux;
    return info;
}

NodoListaResultado* insertarSinRepetir(NodoListaResultado*& listaResultado, InfoNodoLista info)
{
    NodoListaResultado* aux = listaResultado;
    bool encontrado = false;
    while(aux != nullptr && !encontrado)
    {
        if(aux->info.campo1 == info.campo1 || aux->info.campo2 == info.campo2)
        {
            encontrado = true;
        }else
        {
            aux = aux->sgte;
        }
    }

    if(encontrado)
    {
        agregar(aux->info.sublista,info);
        return aux;
    }else
    {
        NodoListaResultado* nuevo = insertarOrdenado(listaResultado, info);
        return nuevo;
    } 
}

NodoSublista* agregar(NodoSublista*& sublista, InfoNodoLista info)
{
    NodoSublista* nuevo = new NodoSublista();
    nuevo->info.campo3 = info.campo3;
    nuevo->info.campo4 = info.campo4;
    nuevo->sgte = nullptr;

    if(sublista == nullptr)
    {
        sublista = nuevo;
    }else
    {
        NodoSublista* aux = sublista;
        while(aux->sgte != nullptr)
        {
            aux = aux->sgte;
        }
        aux->sgte = nuevo;
    }
    return nuevo;
}


int main()
{
    NodoLista* lista;

    NodoListaResultado* listaResultado = cargarListaDeListas(lista);
    NodoListaResultado* aux = listaResultado;
    while(aux != nullptr)
    {
        cout << "Nuevo nodo: " << endl;
        cout << "Campo 1: " << aux->info.campo1 << endl;
        cout << "Campo 2: " << aux->info.campo2 << endl;

        cout << "Sublista: " << endl;
        NodoSublista* aux1 = aux->info.sublista;
        while(aux1 != nullptr)
        {
            cout << "Nuevo subnodo: " << endl;
            cout << "Campo 3: " << aux1->info.campo3 << endl;
            cout << "Campo 4: " << aux1->info.campo4 << endl;

            aux1 = aux1->sgte;
        }

        aux = aux->sgte;
    }
}

/*
4) 
Lista ordenada con repetición: 
Ventajas: 
- La lógica necesaria para agregar, borrar, insertar o buscar elementos
es más simple. 
- El hecho de que requiera declarar menos estructuras de datos (los nodos y
su respectiva información) la hace más fácil de entender y manejar. 
Desventajas: 
- Permite la existencia de elementos con datos duplicados, generando
espacio innecesario en memoria.
- La duplicación de información la hace menos organizada y hace más difícil
acceder a la información.  

Lista ordenada con sublista: 
Ventajas: 
- Permite una mejor organización de la información, y por ende facilita el
acceso a datos particulares. 
- Elimina los datos duplicados entre nodos, generando sublistas con todos
aquellos que no se repitan. Hay un manejo más eficiente del espacio de me
moria. 
Desventajas: 
- La existencia de múltiples estructuras de datos, utilizadas para almace
nar información en listas y sublistas, complica las operaciones de adición, 
borrado, búsqueda e inserción. 
- La inserción es más lenta por la verificación de existencia de duplicados. 
*/