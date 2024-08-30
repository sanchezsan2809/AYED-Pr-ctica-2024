#include <iostream>

using namespace std;
int main()
{
    int x[20] = {4,6,7,8,13,15,17,19};
    int n = 8; //Longitud del array
    int t  = 6;


    //Búsqueda lineal
    bool encontrado = false;
    int i = 0;
    while(i < n && !encontrado)
    {
        if(x[i] == t)
        {
            encontrado = true;
        }
    }
    if(encontrado)
    {
        cout << "Elemento encontrado en la posición: " << i - 1 << endl;
    }else
    {
        cout << "Elemento no encontrado. " << endl;
    }
    

    //Búsqueda binaria
    int p = 0;
    int u = n - 1;
    int c;
    bool encontrado = false;
    while(p <= u && !encontrado)
    {
        c = (p + u) / 2;
        encontrado = x[c] == t;

        p = x[c] < t? c + 1: p;
        u = x[c] > t? c - 1: u;
    }

    if(encontrado)
    {
        cout << "Elemento encontrado en la posición: " << c << endl;
    }else
    {
        cout << "Elemento no encontrado" << endl;
    }
    
}