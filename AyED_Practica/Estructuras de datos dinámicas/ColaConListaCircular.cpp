
struct Nodo
{
    int info;
    Nodo* sgte;
};

Nodo* encolar(Nodo*& ultimo, int elem)
{
    Nodo* nuevo = new Nodo();
    nuevo->info = elem;
    if (ultimo != nullptr)
    {
        nuevo->sgte = ultimo->sgte;
        ultimo->sgte = nuevo;
    }else
    {
        nuevo->sgte = nuevo;
    }
    ultimo = nuevo; 
}

int desencolar(Nodo*& ultimo)
{
    Nodo* aux = ultimo->sgte;
    int ret = aux->info;
    ultimo->sgte = aux->sgte;

    if(aux == ultimo)
    {
        ultimo = nullptr;
    }
    delete aux;
    return ret;
}

int main()
{
    Nodo* ultimo = nullptr;
}