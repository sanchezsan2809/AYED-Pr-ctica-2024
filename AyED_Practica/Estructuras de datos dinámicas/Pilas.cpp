
struct Nodo
{
    int info;
    Nodo* sgte;
};

Nodo* push(Nodo*& pila, int elem)
{
    Nodo* nuevo = new Nodo();
    nuevo->info = elem;
    nuevo->sgte = pila;

    pila = nuevo;
    return nuevo;
}

int pop(Nodo*& pila)
{
    Nodo* aux = pila;
    pila = pila->sgte;
    int info = aux->info;
    delete aux; 
    return info;
}

bool pilaVacia(Nodo* pila)
{
    return (pila == nullptr);
}

int main()
{
    Nodo* pila = nullptr;
}