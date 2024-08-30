#include <iostream>
using namespace std;

int* crearArray(int n)
{
    int* array = new int[n];
    for(int i = 0; i < n; i++)
    {
        array[i] = 0;
    }
    return array;
}

void redimensionarArray(int*& array, int& n)
{
    int* arrayNuevo = new int[n + 1];
    for(int i = 0; i < n; i++)
    {
        arrayNuevo[i] = array[i];
    }
    arrayNuevo[n] = 0;
    n++;
    delete[] array;
    array = arrayNuevo;
}

int agregarElemento(int*& array, int& n, int elem)
{
    int i = 0;
    while(array[i] != 0 && i < n)
    {
        i++;
    }
    if(i == n)
    {
        redimensionarArray(array, n); 
    }
    array[i] = elem;
    return i;
}

int buscarElemento(int* array, int n, int elem)
{
    bool encontrado = false;
    int pos = -1;
    int i = 0;
    while(i < n && !encontrado)
    {
        if(array[i] == elem)
        {
            encontrado = true;
            pos = i;
        }
        i++;
    }
    return pos;
}

bool arrayLleno(int* array, int n)
{
    for(int i = 0; i < n; i++)
    {
        if(array[i] == 0)
        {
            return false;
        }
    }
    return true;
}

void insertar(int*& array, int n, int pos, int elem)
{
    if(arrayLleno(array, n))
    {
        redimensionarArray(array,n);
    }
    for(int i = n; i > pos; i--)
    {
        array[i] = array[i - 1]; 
    }
    array[pos] = elem;
}

int borrar(int*& array, int n, int pos)
{
    for(int i = pos; i < n ; i++)
    {
        array[i] = array[i + 1];
    }
}

int descubrir(int*& array, int n, int elem)
{
    int pos = buscarElemento(array, n, elem);
    if(pos == -1)
    {
        pos = agregarElemento(array, n, elem);
    }
    return pos;
}

int main()
{
    // Ejemplo de uso
    int n = 5;
    int* array = crearArray(n);

    agregarElemento(array, n, 3);
    agregarElemento(array, n, 7);
    insertar(array, n, 1, 5);
    borrar(array, n, 2);
    int pos = descubrir(array, n, 10);

    // Imprimir el array
    for(int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    delete[] array; // Liberar la memoria del array
    return 0;
}








