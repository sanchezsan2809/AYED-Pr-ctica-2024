#include <iostream>
using namespace std;


struct Pago
{
    int dni;
    int fechaPago;
    int importe;
};

struct Persona
{
    int dni;
    NodoSublista* pagos;
};

struct NodoSublista
{
    Pago info;
    NodoSublista* sgte;
};

struct Nodo
{
    Persona info;
    Nodo* sgte;
};

Nodo* descubrirPersona(Nodo*& personas, int dni)
{
    Nodo* aux = personas;
    Nodo* ret = nullptr;
    bool encontrado = false;
    while(aux != nullptr && !encontrado)
    {
        if(aux->info.dni == dni)
        {
            ret = aux;
            encontrado = true;
        }
        aux = aux->sgte;
    }
    if(!encontrado)
    {
        Persona persona;
        persona.dni = dni; 
        persona.pagos = nullptr;
        ret = agregarNodo(personas, persona);
    }
    return ret;
}

Nodo* agregarNodo(Nodo*& personas, Persona persona)
{
    Nodo* nuevo = new Nodo();
    nuevo->info = persona;
    nuevo->sgte = nullptr;

    if(personas == nullptr)
    {
        personas = nuevo;
    }
    else
    {
        Nodo* aux = personas;
        while(aux->sgte != nullptr)
        {
        aux = aux->sgte;
        }
        aux ->sgte = nuevo;
    }
    return nuevo;
}

NodoSublista* agregarNodoSublista(NodoSublista*& pagos, Pago pago)
{
    NodoSublista* nuevo = new NodoSublista();
    nuevo->info = pago;
    nuevo->sgte = nullptr;

    if(pagos == nullptr)
    {
        pagos = nuevo;
    }
    else
    {
        NodoSublista* aux = pagos;
        while(aux->sgte != nullptr)
        {
            aux = aux->sgte;
        }
        aux ->sgte = nuevo;
    }

    return nuevo;
}

void procesarPago(Nodo*& personas, Pago pago)
{
    Nodo* persona = descubrirPersona(personas, pago.dni);
    agregarNodoSublista(persona->info.pagos, pago);
}

void emitirResultadosPorPersona(Nodo* personas)
{
    Nodo* aux = personas;
    while(aux != nullptr)
    {
        double totalAbonado = 0;
        int contPagos = 0;
        Persona persona = aux->info;
        cout <<"DNI de persona: " << persona.dni << endl;
        NodoSublista* pagos = persona.pagos;
        while(pagos != nullptr)
        {
            totalAbonado += pagos->info.importe;
            contPagos++;
            pagos = pagos->sgte;
        }
        double importePromedio = totalAbonado / contPagos;

        cout <<"Cantidad de pagos efectuados: " << contPagos << endl;
        cout <<"Importe promedio de los pagos :" << importePromedio << endl;
        cout <<"Cantidad total abonada: " << totalAbonado << endl;
        cout << endl;

        aux = aux->sgte;
    }
}

void emitirResultadosGenerales(Nodo* personas)
{
    int contPersonas = 0, contPagos = 0, mayorCantidad = 0, dniDeMayorCantidad;
    double totalImportes = 0;

    Nodo* aux = personas;
    while(aux != nullptr)
    {
        Persona persona = aux->info;
        contPersonas++;
        NodoSublista* pagos = persona.pagos;
        while(pagos != nullptr)
        {
            Pago pago = pagos->info;
            contPagos++;
            totalImportes += pago.importe;
            if(pago.importe > mayorCantidad)
            {
                mayorCantidad = pago.importe;
                dniDeMayorCantidad = persona.dni;
            }
            pagos = pagos->sgte;
        }
        aux = aux->sgte;
    }
    double promedioPagos = totalImportes / contPagos; 

    cout << "Cantidad de personas que efectuaron al menos un pago: " << contPersonas << endl;
    cout << "El promedio de los importes pagados es: " << promedioPagos << endl;
    cout << "El DNI de la persona que abonó la mayor cantidad de dinero es: " << dniDeMayorCantidad << endl;
}

void liberarMemoria(Nodo* personas)
{
    while(personas != nullptr)
    {
        Nodo* temp = personas; 
        personas = personas ->sgte;

        NodoSublista* sublista = temp->info.pagos;
        while(sublista != nullptr)
        {
            NodoSublista* tempSub = sublista;
            sublista = sublista->sgte;
            delete tempSub;
        }

        delete temp;
    }
}

int main()
{
    int d, p, i;
    int cantPagos = 0, acumImportes = 0;
    Nodo* personas = nullptr;

    cout << "Ingrese la terna (DNI, fecha, importe): " << endl;
    cin >> d >> p >> i;

    while(d != 0)
    {
        Pago pago = {d, p, i};
        procesarPago(personas, pago);

        cout << "Ingrese la terna (DNI, fecha, importe): " << endl;
        cin >> d >> p >> i;
    }

    emitirResultadosPorPersona(personas);
    emitirResultadosGenerales(personas);

    liberarMemoria(personas);

    return 0;
}







/*
    1.2.2.1.
   
   int sueldo;
   int denominaciones[] = {100, 50, 20, 10, 5, 2, 1};
   int cantidades[sizeof(denominaciones)/sizeof(denominaciones[0])];  
   cout << "Ingrese el sueldo: " << endl;
   cin >> sueldo;

   for(int i = 0; i < sizeof(denominaciones) / sizeof(denominaciones[0]); i++)
   {
    cantidades[i] = sueldo / denominaciones[i];
    sueldo = sueldo % denominaciones[i];
   } 

   for(int i = 0; i < sizeof(cantidades) / sizeof(cantidades[0]); i++)
   {
    cout <<"Se necesitan: " << cantidades[i] << " billetes de: " << denominaciones[i] << endl;
   }
    */

   /*
   1.2.2.2.
   
  int sueldo;
  int denominaciones[] = {100, 50, 20, 10, 5, 2, 1};
  int cantidades[sizeof(denominaciones)/sizeof(denominaciones[0])] = {0};  
  

  cout << "Ingrese el conjunto de sueldos finalizando con un 0: " << endl;
  cin >> sueldo;

  while(sueldo != 0)
  {
    for(int i = 0; i < sizeof(denominaciones) / sizeof(denominaciones[0]); i++)
   {
    cantidades[i] += sueldo / denominaciones[i];
    sueldo = sueldo % denominaciones[i];
   }

   cin >> sueldo;
  }

  for(int i = 0; i < sizeof(cantidades) / sizeof(cantidades[0]); i++)
   {
    cout <<"Se necesitan: " << cantidades[i] << " billetes de: " << denominaciones[i] << endl;
   }
  */

  /*
  1.2.2.3.
    
 int idCont, peso, idPuerto, mayorPeso = 0, idMayorPeso, pesoTotal = 0, puerto1 = 0, puerto2 = 0, puerto3 = 0;


 for(int i = 0; i < 100; i++)
 {
    cout <<"Indique Id. del contenedor, peso en kilos y puerto de destino" << endl;
    cin >> idCont >> peso >> idPuerto;

    pesoTotal += peso;

    idMayorPeso = peso > mayorPeso? idCont : idMayorPeso;
    mayorPeso = peso > mayorPeso? peso : mayorPeso;
    puerto1 = idPuerto == 1? ++puerto1 : puerto1;
    puerto2 = idPuerto == 2? ++puerto2 : puerto2;
    puerto3 = idPuerto == 3? ++puerto3 : puerto3;
 }

cout << "Peso total: " << pesoTotal << endl;
cout << "Mayor peso: " << idMayorPeso << endl;
cout << "A puerto 1: " << puerto1 << endl;
cout << "A puerto 2: " << puerto2 << endl;
cout << "A puerto 3: " << puerto3 << endl;
*/


/*
1.2.2.4.

int tInfr, valor, menorValor, gravedadInt, clausura;
//tipo = 1, 2, 3; gravedad = l, m, g
string motivo, motivoDeMenorValor;
char gravedad;
int infraccionesCantidad[4][3] = {0}; //tipo y gravedad
int infraccionesValor[3] = {0};

cout <<"Ingrese tipo de infracción, motivo, valor y gravedad, finalizando el lote con un tipo de infracción = 0" << endl;
cin >> tInfr >> motivo >> valor >> gravedad; 
menorValor = valor;
motivoDeMenorValor = motivo;
while(tInfr != 0)
{
    if(valor < menorValor)
    {
        menorValor = valor;
        motivoDeMenorValor = motivo;
    }

    gravedadInt = (gravedad == 'l')? 0 : (gravedad == 'm')? 1 : 2;
    infraccionesCantidad[tInfr - 1][gravedadInt]++;
    infraccionesValor[gravedadInt] += valor;

    cin >> tInfr >> motivo >> valor >> gravedad;
}

for(int i = 0; i < 3; i++)
{
    gravedad = (i == 0)? 'l' : (i == 1)? 'm' :'g'; 
    cout << "Total a pagar por infracciones de gravedad " << gravedad << ": $" << infraccionesValor[i] << endl;
}

clausura = infraccionesCantidad[2][2] + infraccionesCantidad[3][2];

if(clausura > 3)
{
    cout << "Clausurar fábrica" << endl;
}

cout <<"Motivo por el que se aplicó la infracción de menor valor: " << motivoDeMenorValor << endl;
*/

/*
1.2.2.5.


struct Familia
{
    int domicilio;
    int cantidadIntegrantes = 0;
    char vivienda;
    NodoSubLista* integrantes;
};

struct Integrante
{
    string nombre;
    int edad;
    char sexo;
    char nivelDeEstudios;
    char indicadorNivelDeEstudios;
};

struct Nodo
{
    Familia info;
    Nodo* sgte;
};

struct NodoSubLista
{
    Integrante info;
    NodoSubLista* sgte;
};

void agregarListaPrincipal(Nodo*& familias, Familia familia)
{
    Nodo* nuevo = new Nodo();
    nuevo ->info = familia;
    nuevo -> sgte = NULL;
    if(familias == NULL)
    {
        familias = nuevo;
    }else
    {
        Nodo* temp = familias;
        while(temp ->sgte != NULL)
        {
            temp = temp -> sgte;
        }
        temp -> sgte = nuevo;
    }

}

void agregarSubLista(NodoSubLista*& integrantes, Integrante integrante)
{
    
    NodoSubLista* nuevo = new NodoSubLista();
    nuevo ->info = integrante;
    nuevo -> sgte = NULL;
    if(integrantes == NULL)
    {
        integrantes = nuevo;
    }else
    {
        NodoSubLista* temp = integrantes;
        while(temp -> sgte != NULL)
        {
            temp = temp -> sgte;
        }
        temp ->sgte = nuevo;
    }
}

void emitirDatosDeIntegrantesConNivelPrimarioCompleto(Nodo* familias)
{
    cout << "Encuestados con nivel primario completo: " << endl;
    while(familias != NULL)
    {
        Familia familia = familias -> info;
        NodoSubLista* integrantes = familia.integrantes;
        while(integrantes != NULL)
        {
            Integrante integrante = integrantes ->info;
            if(((integrante.nivelDeEstudios == 'P' && integrante.indicadorNivelDeEstudios == 'C') || integrante.nivelDeEstudios == 'S' || integrante.nivelDeEstudios == 'T' || integrante.nivelDeEstudios == 'U'))
            {
                cout <<"Nombre: " << integrante.nombre << endl;
                cout <<"Edad: " << integrante.edad << endl;
                cout <<"Sexo: " << integrante.sexo << endl;
                cout <<"Nivel de estudios: " << integrante.nivelDeEstudios << endl;
                cout <<"Completitud de nivel de estudios: " << integrante.indicadorNivelDeEstudios << endl;
            } 
            integrantes = integrantes ->sgte;
        }
        familias = familias ->sgte;
    }
}

int calcularPorcentajeAnalfabetismo(Nodo* familias)
{
   int total = 0;
   double analfabetos = 0; 
   while(familias != NULL)
    {
        Familia familia = familias -> info;
        total += familia.cantidadIntegrantes;
        NodoSubLista* integrantes = familia.integrantes;
        while(integrantes != NULL)
        {
            Integrante integrante = integrantes ->info;
            if(integrante.edad >= 10 && integrante.nivelDeEstudios == 'N')
            {
                analfabetos++;
            } 
            integrantes = integrantes -> sgte;
        }
        familias = familias ->sgte;
    } 

    return  analfabetos / total * 100;
}

int descubrirDomicilioMayorCantidadIntegrantes(Nodo* familias)
{
    int mayor = 0;
    int domicilio;
    while(familias != NULL)
    {
        Familia familia = familias->info;
        if (familia.cantidadIntegrantes > mayor && familia.vivienda == 'D')
        {
            mayor = familia.cantidadIntegrantes;
            domicilio = familia.domicilio;
        }
        familias = familias -> sgte;
    }

    return domicilio;
}

void emitirEdadPromedioFamiliaYCiudad(Nodo* familias)
{
    int total = 0;
    double sumEdadCiudad = 0;

    while(familias != NULL)
    {
        Familia familia = familias ->info;
        total += familia.cantidadIntegrantes;
        double sumEdadFamilia = 0;
        while(familia.integrantes != NULL)
        {
            Integrante integrante = familia.integrantes ->info;

            sumEdadFamilia += integrante.edad;
            sumEdadCiudad += integrante.edad;
            familia.integrantes = familia.integrantes ->sgte;
        }
        cout << "La edad promedio de la familia es: " << sumEdadFamilia / familia.cantidadIntegrantes << endl;
        familias = familias -> sgte;
    }
    cout << "La edad promedio en la ciudad es de: " << sumEdadCiudad / total << endl;
}

void contarNivelesDeEstudioIncompletos(Nodo* familias, int nivelesDeEstudio[4])
{
    while(familias != NULL)
    {
        Familia familia = familias -> info;
        while(familia.integrantes != NULL)
        {
            Integrante integrante = familia.integrantes -> info;
            if(integrante.nivelDeEstudios == 'N')
            {
               for(int i = 0; i < 4; i++)
               {
                nivelesDeEstudio[i]++;
               }
            }else if(integrante.nivelDeEstudios == 'P')
            {
                if(integrante.indicadorNivelDeEstudios == 'I')
                {
                    nivelesDeEstudio[0]++;
                }
                for(int i = 1; i < 4; i++)
                {
                    nivelesDeEstudio[i]++;
                }
            }else if (integrante.nivelDeEstudios == 'S')
            {
                if(integrante.indicadorNivelDeEstudios == 'I')
                {
                    nivelesDeEstudio[1]++;
                }
                for(int i = 2; i < 4; i++)
                {
                    nivelesDeEstudio[i]++;
                }
            }else if(integrante.nivelDeEstudios == 'T')
            {
                if(integrante.indicadorNivelDeEstudios == 'I')
                {
                    nivelesDeEstudio[2]++;
                }
                nivelesDeEstudio[3]++;
            }else if(integrante.nivelDeEstudios == 'U' && integrante.indicadorNivelDeEstudios == 'I')
            {
                nivelesDeEstudio[3]++;
            }
            familia.integrantes = familia.integrantes ->sgte;
        }
        familias = familias ->sgte;
    } 
}

void emitirPorcentajeEncuestadosFemeninosYMasculinos(Nodo* familias)
{
    int total = 0;
    double  femeninos = 0, masculinos = 0;
    while(familias != NULL)
    {
        Familia familia = familias -> info;
        total += familia.cantidadIntegrantes;
        while(familia.integrantes != NULL)
        {
           familia.integrantes ->info.sexo == 'F' ? femeninos++ : masculinos++;
           familia.integrantes = familia.integrantes -> sgte; 
        }
        familias = familias -> sgte;
    }

    cout << "El porcentaje de encuestados masculinos es de: " << masculinos / total * 100 << "%. " << endl;
    cout << "El porcentaje de encuestados femeninos es de: " << femeninos / total * 100 << "%. " << endl;
}

int main()
{
    Nodo* familias = new Nodo();
    int domicilio, cantidadIntegrantes = 0;
    char vivienda;
    string nombre;
    int edad;
    char sexo, nivelDeEstudios, indicadorNivelDeEstudios;
    int nivelesEstudioIncompletos[4] = {0};

    cout << "Ingrese datos de la familia: " << endl;
    cin >>  domicilio >> cantidadIntegrantes >> vivienda;

    while(cantidadIntegrantes != 0)
    {
        NodoSubLista* integrantes = new NodoSubLista();
        Familia familia = {domicilio, cantidadIntegrantes, vivienda, integrantes};
        for(int i = 0; i < cantidadIntegrantes;i++)
        {
            cout << "Ingrese datos de integrante" << endl;
            cin >> nombre >> edad >> sexo >> nivelDeEstudios >> indicadorNivelDeEstudios;
            Integrante integrante  = {nombre, edad, sexo, nivelDeEstudios, indicadorNivelDeEstudios};
            agregarSubLista(integrantes, integrante);
        }

        agregarListaPrincipal(familias, familia);

        cin >> domicilio >> cantidadIntegrantes >> vivienda;
    }

    emitirDatosDeIntegrantesConNivelPrimarioCompleto(familias);
    int porcentajeAnalfabetismo = calcularPorcentajeAnalfabetismo(familias);
    cout << "El porcentaje de analfabetismo es de: " << porcentajeAnalfabetismo << endl;
    int domicilioMayorCantidadIntegrantes = descubrirDomicilioMayorCantidadIntegrantes(familias); 
    cout << "El domicilio de la familia que, teniendo la mayor cantidad de integrantes, vive en un departamento, es: " << domicilioMayorCantidadIntegrantes << endl;
    emitirEdadPromedioFamiliaYCiudad(familias);
    contarNivelesDeEstudioIncompletos(familias, nivelesEstudioIncompletos);
    for(int i = 0; i < 4; i++)
    {
        char nivelDeEstudio = i = 0? 'P' : i = 1? 'S' : i = 2? 'T' : 'U';
        cout <<"Cantidad de personas sin nivel de estudios: " << nivelDeEstudio << ": " << nivelesEstudioIncompletos[i];
    }
    emitirPorcentajeEncuestadosFemeninosYMasculinos(familias);   
}
*/


/*
1.2.2.6.

#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;

struct Vuelo
{
    int numero;
    char destino[20];
    int cantAsientos;
    NodoSubLista* pasajeros;
};

struct Pasajero
{
    int pasaporte;
    int importeAbonado;
};

struct Nodo
{
    Vuelo info;
    Nodo* sgte;
};

struct NodoSubLista
{
    Pasajero info;
    NodoSubLista* sgte;
};

void agregarListaPrincipal(Nodo*& vuelos, Vuelo vuelo)
{
    Nodo* nuevo = new Nodo();
    nuevo->info = vuelo;
    nuevo->sgte = nullptr;

    Nodo* aux = vuelos;

    if(aux == nullptr)
    {
        vuelos = nuevo;
    }
    else
    {
        while(aux->sgte != nullptr)
        {
            aux = aux->sgte;
        }
        aux->sgte = nuevo;
    }
}

void agregarSubLista(NodoSubLista*& pasajeros, Pasajero pasajero)
{
    NodoSubLista* nuevo = new NodoSubLista();
    nuevo->info = pasajero;
    nuevo->sgte = nullptr;

    NodoSubLista* aux = pasajeros;

    if(aux == nullptr)
    {
        pasajeros = nuevo;
    }
    else
    {
        while(aux->sgte != nullptr)
        {
            aux = aux->sgte;
        }
        aux->sgte = nuevo;
    }
}

void actualizarMayorCantVuelosLlenosSeguidos(int asientosOcupados, int cantAsientos, bool& vueloAnteriorLleno, int& cantVuelosLlenosSeguidos, int& mayorCantVuelosLlenosSeguidos)
{
    if (asientosOcupados == cantAsientos )
        {
            if(vueloAnteriorLleno)
            {
                cantVuelosLlenosSeguidos++;
            } else
            {
                vueloAnteriorLleno = true;
                cantVuelosLlenosSeguidos = 1;
            }   
        } else{
            vueloAnteriorLleno = false;
            mayorCantVuelosLlenosSeguidos =max(mayorCantVuelosLlenosSeguidos, cantVuelosLlenosSeguidos);
        }
}

void emitirListado(Nodo* vuelos)
{
    int totalRecaudacionMensual = 0, cantVuelosLlenosSeguidos = 0, mayorCantVuelosLlenosSeguidos = 0, mayorRecaudacion = 0, vueloMayorRecaudacion;
    bool vueloAnteriorLleno = false;


    Nodo* aux = vuelos;
    while(aux != nullptr)
    {
        int totalRecaudacion = 0;
        double asientosOcupados = 0;
        Vuelo vuelo = aux ->info;
        cout << "Nro. de vuelo: " << vuelo.numero << ", Destino: " << vuelo.destino << endl;
        cout << "Nro. de pasaporte          Importe" << endl;
        NodoSubLista* pasajeros = vuelo.pasajeros;
        while(pasajeros != nullptr)
        {
            Pasajero pasajero = pasajeros ->info;
            totalRecaudacion += pasajero.importeAbonado;
            asientosOcupados++;
            cout << pasajero.pasaporte << "         " << pasajero.importeAbonado << endl;  
            pasajeros = pasajeros->sgte;
        }
        aux = aux->sgte;

        cout << "Total recaudación vuelo: $" << totalRecaudacion << endl;
        cout << "Porcentaje de asientos libres: " << (double)(vuelo.cantAsientos - asientosOcupados) / vuelo.cantAsientos * 100 << " %" << endl;
        cout << "Porcentaje de asientos ocupados: " << (double)asientosOcupados / vuelo.cantAsientos * 100 << "%" << endl;

        totalRecaudacionMensual += totalRecaudacion;
        

        if(totalRecaudacion > mayorRecaudacion)
        {
            mayorRecaudacion = totalRecaudacion;
            vueloMayorRecaudacion = vuelo.numero;
        }

        actualizarMayorCantVuelosLlenosSeguidos(asientosOcupados, vuelo.cantAsientos, vueloAnteriorLleno, cantVuelosLlenosSeguidos, mayorCantVuelosLlenosSeguidos);
        
        cout << endl;
    }

    cout << "Total recaudación mensual: $" << totalRecaudacionMensual << endl;
    cout << "Mayor cantidad de veces seguidas que se dieron vuelos completos: " << mayorCantVuelosLlenosSeguidos << endl;
    cout << "Número de vuelo que más recaudó: " << vueloMayorRecaudacion << endl;
}

int main()
{
    int numero, cantAsientos;
    char destino[20];
    int pasaporte, importeAbonado;
    Nodo* vuelos = nullptr;

    int m; //Cantidad de vuelos
    cin >> m;

    for(int i = 0; i < m; i++)
    {
        cout << "Ingrese datos del vuelo: " << endl;
        cin >> numero >> destino >> cantAsientos;

        Vuelo vuelo;
        vuelo.numero = numero;
        strcpy(vuelo.destino, destino);
        vuelo.cantAsientos = cantAsientos;
        vuelo.pasajeros = nullptr;

        cout << "Ingrese los datos de los pasajeros (termina con pasaporte 0): " << endl;
        cin >> pasaporte >> importeAbonado;
        while(pasaporte != 0)
        {
            Pasajero pasajero;
            pasajero.pasaporte = pasaporte;
            pasajero.importeAbonado = importeAbonado;

            agregarSubLista(vuelo.pasajeros, pasajero);
            cout << "Siguiente: " << endl;
            cin >> pasaporte >> importeAbonado;
        }
        agregarListaPrincipal(vuelos, vuelo);
    }

     emitirListado(vuelos);
}
*/

