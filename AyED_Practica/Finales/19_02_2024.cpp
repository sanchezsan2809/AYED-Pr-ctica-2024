#include <iostream>
#include <string.h>
using namespace std;

//1) 
struct PorcentajeVotos
{
    double porcentaje;
    char nombre[20];
};


int formulario(int form[]);
void cargarFormularios(int votos[3][3][7], int form[13]);
int xx(int v[], int comienzo, int fin);
void mostrarResultados(int actividad, int institucion, int votos[3][3][7]);
double calcularPorcentaje(int parte, int total);
void asignarNombre(PorcentajeVotos& porcentaje, int i);
void ordenar(PorcentajeVotos porcentajes[7]);
void mostrarEncuestadosYPorcentajes(int votos[3][3][7]);

int main()
{
    //1) 
    int form[13]; //Est | Doc | Egresado | Pública | Privada | Terciario | Python | C++ | Java | Py+C | Py+J | C+J | Otro
    int votos[3][3][7]; //[actividad][institucion][opcion]


    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            for(int k = 0; k < 7; k++)
            {
                votos[i][j][k] = 0;
            }
        }
    }

    while(formulario(form))
    {
        cargarFormularios(votos, form);
    }

    int actividad, institucion;
    cout << "Ingrese actividad (1..3): " << endl;
    cin >> actividad;
    cout << "Ingrese institución (1..3): " << endl;
    cin >> institucion; 

    mostrarResultados(actividad, institucion, votos);
    mostrarEncuestadosYPorcentajes(votos);

    return 0;
}

//2) 
void cargarFormularios(int votos[3][3][7], int form[13])
{
    int actividad = xx(form, 0, 2);
    int institucion = xx(form, 3, 5); 
    int opcion = xx(form, 6, 12);

    votos[actividad][institucion][opcion]++;
}

//3)
int xx(int v[], int comienzo, int fin)
{
    int i = comienzo;
    for(; i <= fin; i++)
    {
        if(v[i]) return i - comienzo;
    }
    return -1;
}
/*
Dado un array de enteros, y dos valores numéricos enteros llamados
"comienzo" y "fin", la función recorre el array desde el valor determinado
por "comienzo", hasta el valor determinado por "fin"; en caso de encontrar
en alguna posición del array un valor diferente de cero, retorna la posición
del valor respecto de "comienzo"; en cualquier otro caso, retorna -1. 
*/

//4)

void mostrarResultados(int votos[3][3][7], int actividad, int institucion)
{
    actividad--;
    institucion--; 
    int total = 0;
    
    
    for(int i = 0; i < 7; i++)
    {
        total+= votos[actividad][institucion][i];
    }

    PorcentajeVotos porcentajes[7];
    for (int i = 0; i < 7; i++)
    {
        porcentajes[i].porcentaje = calcularPorcentaje(votos[actividad][institucion][i], total);
        asignarNombre(porcentajes[i], i);
    }

    ordenar(porcentajes);


    cout << "Ganador: " << porcentajes[0].nombre << endl;
    cout << "Porcentaje: " << porcentajes[0].porcentaje << "%"<< endl;

    for(int i = 1; i < 7; i++)
    {
        cout << "Nombre de opcion: " << porcentajes[i].nombre << endl;
        cout << "Porcentaje: " << porcentajes[i].porcentaje << "%" << endl;
    }
}

double calcularPorcentaje(int parte, int total)
{
    return (static_cast<double>(parte) / total * 100);
}

void asignarNombre(PorcentajeVotos& porcentaje, int i)
{
    switch (i)
        {
        case 0:
            strcpy(porcentaje.nombre, "Python");
            break;
        case 1: 
            strcpy(porcentaje.nombre, "C++");
            break;
        case 2: 
            strcpy(porcentaje.nombre, "Java");
            break;
        case 3: 
            strcpy(porcentaje.nombre, "Python y C++");
            break;
        case 4: 
            strcpy(porcentaje.nombre, "Python y Java");
            break;
        case 5: 
            strcpy(porcentaje.nombre, "C++ y Java");
            break;
        case 6: 
            strcpy(porcentaje.nombre, "Otro");          
        default:
            break;
        }
}

void ordenar(PorcentajeVotos porcentajes[7])
{
    for(int i = 0; i < 7; i++)
    {
        for(int j = 0; j < 6 - i; j++)
        {
            if(porcentajes[j].porcentaje < porcentajes[j + 1].porcentaje)
            {
                PorcentajeVotos aux = porcentajes[j];
                porcentajes[j] = porcentajes[j + 1];
                porcentajes[j + 1] = aux;
            }
        }
    }
}

//5)
void mostrarEncuestadosYPorcentajes(int votos[3][3][7])
{
    int total = 0, estudiantes = 0;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            for(int k = 0; k < 7; k++)
            {
                total += votos[i][j][k];
                if(i == 0)
                {
                    estudiantes += votos[i][j][k];
                }
            }
        }
    }

    double porcentajeEstudiantes = calcularPorcentaje(estudiantes, total);

    cout << "Cantidad total de encuestados: " << total << endl;
    cout << "Porcentaje de estudiantes: " << porcentajeEstudiantes << endl;
}