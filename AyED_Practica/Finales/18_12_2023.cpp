#include <iostream>
#include <stdio.h>
using namespace std;

/*

//1)
struct Nodo
{
    int info;
    Nodo* sgte;
};

int pop(Nodo*& pila);
Nodo* insertarOrdenado(Nodo*& lista, int elem);
int desencolar(Nodo*& colaPrimero, Nodo*& colaUltimo);
 

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
*/

/*
//2)
struct NotaRecuperatorio2ndoParcial
{
    int legajo;
    double nota;
};

struct Nodo
{
    NotaRecuperatorio2ndoParcial info;
    Nodo* sgte;
};


void actualizarVectorNotas(int notas[1500][3], Nodo* recuperatorios);
int* buscarAlumno(int notas[1500][3], int legajo);

void actualizarVectorNotas(int notas[1500][3], Nodo* recuperatorios)
{
    Nodo* aux = recuperatorios;
    while(aux != nullptr)
    {

        if (aux->info.nota >= 6)
        {
            int* nota = buscarAlumno(notas, aux->info.legajo);
            if(nota != nullptr)
            {
                *nota = aux->info.nota;
            }
        }
        aux = aux->sgte;
    }
}

Precondiciones: 
- "notas" debe ser un vector bidimensional(una matriz), en el que cada 
fila representa la nota de un alumno, la primera columna representa su 
legajo, la segunda la nota de su primer parcial, y la tercera la nota
de su segundo parcial. 
- "recuperatorios" debe ser la referencia al primer nodo de una lista
cuyos nodos contienen el legajo de un estudiante, y la nota del recupe
ratorio del segundo parcial. 

Postcondiciones: 
- Si tanto el vector de notas como la lista de notas de recuperatorios
contienen información, a la salida, se habrán actualizado los valores de 
las notas del segundo parcial de los alumnos que hayan rendido el recupe
ratorio y lo hayan aprobado. 



int* buscarAlumno(int notas[1500][3], int legajo)
{
    int p = 0;
    int u = 1499;
    int c;
    bool encontrado = false;

    while(p <= u && !encontrado)
    {
        c = (p + u) / 2;
        encontrado = notas[c][0] == legajo;

        p = notas[c][0] < legajo ? c + 1 : p;
        u = notas[c][0] > legajo ? c - 1 : u;
    }

    if(encontrado)
    {
        return &notas[c][2];
    }

    return nullptr;
}
*/

/*
3)
    a) La salida por pantalla es: 2 3 1, 
    b) La salida por pantalla es: 31

4) 
    a) Falso. Existe pérdida de información en el apareo de archivos,
    y viene dada por todos aquellos registros leídos que no tengan 
    correspondencia con algún registro del otro archivo.
    b) Verdadero. El corte de control implica dividir el archivo en 
    conjuntos de registros que compartan un mismo campo clave, y procesarlos
    en grupos. Sólo se puede aplicar si los registros están ordenados por campo
    clave, y si la clave no se repite entre diferentes grupos de registros.       
*/

