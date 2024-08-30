#include<iostream>
using namespace std;

struct Nodo
{
    int info;
    Nodo* sgte;
};





Nodo* agregarPrincipio(Nodo*& lista, int info)
{
    Nodo* nuevo = new Nodo();
    nuevo->info = info;
    nuevo->sgte = lista;

    lista = nuevo;
    return nuevo;
}

Nodo* agregarFinal(Nodo*& lista, int info)
{
    Nodo* nuevo = new Nodo();
    nuevo->info = info;
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

bool borrar(Nodo*& lista, int elem)
{
    Nodo* aux = lista;
    Nodo* ant = nullptr;
    bool encontrado = false;

    while(aux != nullptr && !encontrado)
    {
        if(aux->info == elem)
        {
            encontrado = true;
        }
        else
        {
            ant = aux;
            aux = aux->sgte;
        }  
    }

    if(encontrado)
    {
        if(ant == nullptr)
        {
            lista = lista ->sgte;
        }else
        {
            ant->sgte = aux->sgte;
        }
        delete aux;
        return true;
    }
    return false;
}

Nodo* buscar(Nodo* lista, int elem)
{
    Nodo* aux = lista;

    while(aux != nullptr)
    {
        if(aux->info == elem)
        {
            return aux;
        }
        aux = aux ->sgte;
    }

    return aux;
}

Nodo* insertarOrdenadoAscendente(Nodo*& lista, int elem)
{
    Nodo* nuevo = new Nodo();
    nuevo->info = elem;
    nuevo->sgte = nullptr;

    Nodo* aux = lista;
    Nodo* ant = nullptr;
    
    while(aux != nullptr && aux->info < elem)
    {
        ant = aux;
        aux = aux->sgte;
    }
    
    if(ant == nullptr)
    {
        nuevo->sgte = lista;
        lista = nuevo;
    }else
    {
        ant->sgte = nuevo;
        nuevo->sgte = aux;
    }   
    return nuevo;
}

Nodo* buscarEInsertarOrdenadoAscendente(Nodo*& lista, int elem, bool encontrado)
{
    Nodo* ret = buscar(lista, elem);
    encontrado = (ret != nullptr);
    if(!encontrado)
    {
        ret = insertarOrdenadoAscendente(lista, elem);
    }
    return ret;
}


void ordenarAscendente(Nodo*& lista)
{
    Nodo* ordenado = nullptr;
    Nodo* aux = lista;
    while(aux != nullptr)
    {
        insertarOrdenadoAscendente(ordenado,aux->info);
        Nodo* temp = aux;
        aux = aux ->sgte;
        delete temp;
    }
    lista = ordenado;
}

int main()
{
    
}