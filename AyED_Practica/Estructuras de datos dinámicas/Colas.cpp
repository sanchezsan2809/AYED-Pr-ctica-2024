
struct Nodo
{
    int info;
    Nodo* sgte;
};

Nodo* encolar(Nodo*& primero, Nodo* ultimo, int elem)
{
    Nodo* nuevo = new Nodo();
    nuevo->info = elem;
    nuevo->sgte = nullptr;

    if(ultimo != nullptr)
    {
        ultimo->sgte = nuevo;
        ultimo = nuevo;
    }else
    {
        primero = nuevo;
    }
    ultimo = nuevo;
    return nuevo;
}

int desencolar(Nodo*& primero, Nodo* ultimo)
{
    Nodo* aux = primero;
    int ret = aux->info;
    delete aux;
    primero = primero->sgte;
    if (primero == nullptr)
    {
        ultimo = nullptr;
    }
    return ret;
}

bool colaVacia(Nodo* primero, Nodo* ultimo)
{
    return (primero == nullptr);
}

int main()
{
    Nodo* primero = nullptr;
    Nodo* ultimo = nullptr;
}