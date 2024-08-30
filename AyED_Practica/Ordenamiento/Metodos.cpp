
/*
Ordenamiento por inserción avanzado(libro de Pablo)
int agregar(int x[], int num, int& n)
{
    x[n] = num;
    n++; 
    return n;
}

int borrar(int x[], int pos, int& n)
{
    if(pos < 0 || pos >= n)
    {
        return -1;
    }else
    {
        int num = x[pos]; 
        for(int i = pos; i < n; i++)
        {
            x[i] = x[i + 1];
        }
        x[n - 1] = 0;
        n--;
        return num;
    }
    
    
}

void ordenamientoPorInsercionAvanzado(int x[], int n)
{
   int p = n;
    while(p >= 0)
    {
        int pos = 0;
        int min = x[0];
        for(int i = 0; i < p; i++)
        {
            if(x[i] > min)
            {
                min = x[i];
                pos = i;
            }
        }

        agregar(x, min, n);
        borrar(x, pos, n);
        p--;
    } 
}

int main()
{
    int x[20] = {0};
    int n = 0;
    agregar(x, 3, n);
    agregar(x, 13,n);
    agregar(x, 2,n);
    agregar(x, 6,n);
    agregar(x, 17,n);
    agregar(x, 16,n);
    agregar(x, 4,n);
    agregar(x, 9,n);
    
    ordenamientoPorInsercionAvanzado(x, n);

}
*/

/*
    int x[20] = {12,4,15,6,7,13,6,8};

    //  Ordenamiento por burbujeo
    int i = 0;
    int n = 8; //Tamaño del array
    bool ordenado = false;
    while(i < n && !ordenado)
    {
        ordenado = true;
        for(int j = 0; j < n - i - 1;j++ )
        {
            if(x[j] > x[j + 1])
            {
                int aux = x[j];
                x[j] = x[j + 1];
                x[j + 1] = aux;

                ordenado = false;
            }
        }
        i++;
    }

    //  Ordenamiento por inserción binaria
    for(int i = 1; i < n; i++)
    {
        int aux = x[i];
        int p = 1;
        int u = i - 1;

        while(p <= u)
        {
            int c = (p + u) / 2;
            if(aux < x[c])
            {
                u = c - 1;
            }
            else
            {
                p = c + 1;
            }
        }
        for(int k = i - 1; i > p; k--)
        {
            x[k + 1] = x[k];
        }
        x[p] = aux;
    }

    //  Ordenamiento por selección
    for(int i = 0; i < n; i++)
    {
        int aux = x[i];
        int k = i;
        for(int j = i + 1; j < n; j++)
        {
            if(x[j] < aux)
            {
                aux = x[j];
                k = j;
            }
        }
        x[k] = x[i];
        x[i] = aux;
    }

*/