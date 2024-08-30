#include <iostream>
#include <string.h>
using namespace std;

//1)
struct Pasajero
{
    char nombre[40];
    char destino[30];
    char vuelo[6];
    int asiento;
    int salida; //ddhhmm
    int llegada; //ddhhmm
};


struct Nodo
{
    Pasajero info;
    Nodo* sgte;
};
/*Identificadores de variables y parámetros: 
Nodo: ultimo, aux, ant, nuevo, lista
Pasajero: pasajero
Otros: nombre, destino
*/


//Funciones y sus respectivos parámetros: 
Nodo* ingresarPasajero(Nodo*& ultimo, Pasajero pasajero);
void visualizar(Nodo* aux);
Nodo* buscarPasajero(Nodo* ultimo, string nombre, Nodo*& ant);
void visualizarPasajero(Nodo* ultimo, string nombre);
void visualizarListaTotal(Nodo* ultimo);
void visualizarListaDestino(Nodo* ultimo, string destino);
string eliminarPasajero(Nodo*& ultimo, string nombre);
void modificarDatosPas(Nodo*& ultimo, string nombre, Pasajero pasajero);
void mostrarOpciones(int& opcion);
Pasajero ingresarDatosPasajero();

//2) 
int main()
{
    Nodo* listaCircular = nullptr;
    int opcion;

    do
    {
        mostrarOpciones(opcion);
        switch (opcion)
        {
        case 1:
            Pasajero pasajero = ingresarDatosPasajero();
            ingresarPasajero(listaCircular, pasajero);
            break;
        case 2:
            char nombre[40]; 
            cout <<"Ingrese el nombre del pasajero: " << endl;
            cin >> nombre;
            visualizarPasajero(listaCircular, nombre);
            break;
        case 3:
            visualizarListaTotal(listaCircular);
            break;
        case 4: 
            char destino[30];
            cout << "Ingrese el nombre del destino: " << endl;
            cin >> destino;
            visualizarListaDestino(listaCircular, destino);
            break;
        case 5: 
            char nombre[40];
            cout << "Ingrese el nombre del pasajero: " << endl;
            cin >> nombre;
            eliminarPasajero(listaCircular, nombre);
            break;
        case 6: 
            char nombre[40];
            cout << "Ingrese el nombre del pasajero: " << endl;
            cin >> nombre; 
            cout << "Ingrese los datos: " << endl;
            Pasajero pasajero = ingresarDatosPasajero();
            modificarDatosPas(listaCircular, nombre, pasajero);      
        case 0:
            cout << "Saliendo..." << endl;
            break;                   
        default:
        cout << "Opción no válida" << endl;
            break;
        }
        
        mostrarOpciones(opcion);
    }while(opcion != 0);
    return 0;
}

void mostrarOpciones(int& opcion)
{
    cout <<"Ingrese un número acorde a la acción que quiere realizar" << endl;
    cout << "1: Ingresar un nuevo pasajero" << endl;
    cout << "2: Visualizar los datos de un pasajero" << endl;
    cout << "3: Visualizar los datos de la totalidad de los pasajeros" << endl;
    cout << "4: Visualizar los datos de la totalidad de los pasajeros de un destino determinado" << endl;
    cout << "5: Eliminar un pasajero de la lista de pasajeros" << endl;
    cout << "6: Modificar los datos de un pasajero" << endl;
    cout << "0: Terminar operaciones" << endl;
    cin >> opcion;
}

Pasajero ingresarDatosPasajero()
{
    Pasajero pasajero;

    cout << "Ingrese nombre y apellido: " << endl;
    cin.ignore();
    cin.getline(pasajero.nombre, 40); 
    cout << "Ingrese destino del vuelo: " << endl;
    cin.getline(pasajero.destino, 30);
    cout << "Ingrese nombre del vuelo: " << endl;
    cin.getline(pasajero.vuelo, 6);
    cout << "Ingrese asiento: " << endl;
    cin >> pasajero.asiento;
    cout << "Ingrese salida: " << endl;
    cin >> pasajero.salida;
    cout << "Ingrese llegada: " << endl;
    cin >> pasajero.llegada;

    return pasajero;
}

Nodo* ingresarPasajero(Nodo*& ultimo, Pasajero pasajero)
{
    Nodo* nuevo = new Nodo();
    nuevo->info = pasajero;


    if(ultimo == nullptr)
    {
        nuevo->sgte = nuevo;
    }else
    {
        nuevo->sgte = ultimo->sgte;
        ultimo->sgte = nuevo;
    }
    ultimo = nuevo;
    return ultimo;
}

/*
Precondiciones:
-El puntero "ultimo" debe ser nullptr en caso de una lista vacía, 
o apuntar al último nodo de una lista. 
-La variable pasajero debe contener datos válidos y completos 
del pasajero a ingresar

Postcondiciones: 
- Un nuevo nodo que contiene los datos del pasajero ingresados se
agregó a la lista. 
- El puntero último pasa a apuntar a este último nodo agregado. 
- Se retorna la dirección del nodo agregado.  
*/


void visualizar(Nodo* aux)
{
    Pasajero pasajero = aux->info;
    cout << "Nombre: " << pasajero.nombre << endl;
    cout << "Destino: " << pasajero.destino << endl;
    cout << "Vuelo: " << pasajero.vuelo << endl;
    cout << "Asiento: " << pasajero.asiento << endl;
    cout << "Salida: " << pasajero.salida << endl;
    cout << "Llegada: " << pasajero.llegada << endl;
}

/*
Precondiciones:
- El puntero aux debe ser un puntero a un nodo que contiene la
información del pasajero que se desea mostrar. 

Postcondiciones: 
- Se emiten por consola cada uno de los campos que contienen los datos
del pasajero, pertenecientes a un struct Pasajero. 

*/


Nodo* buscarPasajero(Nodo* ultimo, const char nombre[40], Nodo*& ant)
{
    Nodo* ant = ultimo;
    Nodo* aux = ultimo->sgte;
    
    do
    {
        if(strcmp(aux->info.nombre, nombre) == 0)
        {
            return aux;
        }
        ant = aux;
        aux = aux->sgte;
    } while(aux != ultimo->sgte);

    ant = nullptr;
    return nullptr;
}

/*
Precondiciones:
- El puntero "ultimo" debe contener la direccion del ultimo nodo 
de la lista, o ser "nullptr" en caso de que la lista esté vacía.  
- "nombre" debe contener el nombre del pasajero que se 
desea encontrar.
- "ant" es una referencia que se utilizará para apuntar al nodo anterior
al encontrado.   

Postcondiciones: 
- Si se encontró un pasajero con el nombre ingresado, se retorna un
puntero al nodo que contiene sus datos, y "ant" apuntará al nodo anterior
al encontrado, en caso de que se deseen realizar modificaciones sobre la 
lista. 
- Si no se encontró un pasajero con ese nombre, se retornará "nullptr", y
ant tendrá el valor nullptr. 

*/


void visualizarPasajero(Nodo*& ultimo, const char nombre[40])
{
    Nodo* ant = nullptr;
    Nodo* aux = buscarPasajero(ultimo, nombre, ant);
    
    if(aux != nullptr)
    {
        visualizar(aux);
    }else
    {
        cout << "Pasajero no encontrado" << endl;
    }
}

/*
Precondiciones:
- El puntero aux debe ser un puntero a un nodo que contiene la
información del pasajero que se desea mostrar. 

Postcondiciones: 
- Se emiten por consola cada uno de los campos que contienen los datos
del pasajero, pertenecientes a un struct Pasajero. 

*/


void visualizarListaTotal(Nodo* ultimo)
{
    if(ultimo == nullptr) return;


    Nodo* aux = ultimo->sgte;
    do
    {
        visualizar(aux);
        aux = aux->sgte;
    } while (aux != ultimo->sgte);
}
/*
Precondiciones: 
- El puntero "ultimo" debe contener la referencia al último nodo de la
lista. 

Postcondiciones: 
- Si la lista está vacía, se devuelve el control a la función principal
sin realizar ninguna operación. 
- Si la lista tiene elementos, se la recorre, mostrando por consola
los datos de cada uno de los pasajeros. 
*/


void visualizarListaDestino(Nodo* ultimo, const char destino[30])
{
    if(ultimo == nullptr) return;

    Nodo* aux = ultimo->sgte;
    do
    {
        if(strcmp(aux->info.destino, destino) == 0)
        {
            visualizar(aux);
        }
        aux = aux->sgte;
    } while (aux != ultimo->sgte);
}

/*
Precondiciones:
- El puntero "ultimo" debe contener la referencia al último nodo de la
lista.  
- "destino" debe contener un destino de vuelo a buscar. 

Postcondiciones: 
- Si la lista está vacía, se devuelve el control a la función principal
sin realizar ninguna operación. 
- Si la lista tiene elementos, se la recorre, mostrando por consola los
datos de los pasajeros cuyo destino coincida con el ingresado. 

*/



string eliminarPasajero(Nodo* ultimo, const char nombre[40])
{
    if(ultimo == nullptr) return "No encontrado";

    Nodo* ant = nullptr;
    Nodo* aux = buscarPasajero(ultimo, nombre, ant);

    if (aux == nullptr) return "No encontrado";

    string ret = aux->info.nombre;

    if(aux == ultimo && aux == ultimo->sgte)
    {
        ultimo == nullptr;
    }else
    {
        if(aux == ultimo)
        {
            ultimo = ant;
        }
        ant->sgte = aux->sgte;
    }      
    delete aux;

    return ret;
}
/*
Precondiciones:
- El puntero "ultimo" debe contener una referencia al último nodo de la
lista. 
- "nombre" debe contener el nombre de un pasajero. 

Postcondiciones: 
- Si la lista está vacía, se retorna el string "No encontrado". 
- Si no se encontró un pasajero con ese nombre, se retorna el string "No encontrado". 
- Si se encontró al pasajero, se eliminan sus datos de la lista, y se retorna
un string con su nombre.  
*/


// El parámetro pasajero debe contener los datos modificados del pasajero que se desea modificar
void modificarDatosPas(Nodo*& ultimo, const char nombre[40], Pasajero pasajero)
{
    if (ultimo == nullptr)
    {
        cout << "Lista vacía." << endl;
        return;
    }

    Nodo* ant = nullptr;
    Nodo* aux = buscarPasajero(ultimo, nombre, ant);

    if(aux != nullptr)
    {
        aux->info = pasajero;    
    }else
    {
        cout << "Pasajero no encontrado." << endl;
    }
    
    return;
}
/*
Precondiciones:
- El puntero "ultimo" debe contener una referencia al último nodo de 
la lista. 
- "nombre" debe contener el nombre de un pasajero. 
- "pasajero" debe contener los datos del pasajero que se desea modificar
con las alteraciones aplicadas. 

Postcondiciones: 
- Si la lista está vacía, se emite por consola el mensaje "Lista vacía", 
y se devuelve el control a la función principal. 
- Si no se encontró el pasajero, se emite por consola el mensaje 
"Pasajero no encontrado.", y se devuelve el control a la función principal. 
- Si se encontró el pasajero, se actualizan sus datos con los datos en
"pasajero".  
*/



/*
4_
La implementación de la solución podría usar como estructura 
para guardar los datos de los pasajeros una simple lista enlazada. 
Las ventajas, de ser este el caso, serían: 
-Un mejor tratamiento de los algoritmos de búsqueda y de recorrido de
la lista, al tener un puntero directo al primero de sus elementos,
en vez de al último.   
-La posibilidad de usar la expresión "aux != nullptr" como condición en los 
bucles de recorrido.

Sus desventajas serían:
-El acceso al último elemento de la lista se dificultaría, al tener que
recorrer toda la lista para llegar al mismo.  

*/