#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;


int main()
{
    /*
    1.2.1.1.:

    int a, b;
    cout << "Ingrese dos números enteros" << endl;
    cin >> a >> b;


    cout << "La suma es: " << a + b << endl;
    cout << "La diferencia es: " << a - b << endl;
    cout << "El producto es: " << a * b << endl;
    if(b != 0)
    {
      cout << "La división entre el primero y el segundo es: " << a + b << endl;
    }
    */

   /*
    1.2.1.2.:

   int a, b;

   cout << "Ingrese dos números enteros";
   cin >> a >> b;

   if (b != 0)
   {
    cout <<"El cociente entre: " << a << " y " << b << " es: " << a/b << endl;
   }  

   */

  /*
  1.2.1.3.: 
      
  int valor;
  double quintaParte, septimaDeQuintaParte;

  cout << "Ingrese un valor: ";
  cin >> valor;

//a)
  quintaParte = valor / 5;  
  cout << "La quinta parte del valor es: " << quintaParte << endl;
//b)
  cout << "El resto de la división de: " << valor << " por 5 es: " << valor % 5 << endl;  
//c)
  septimaDeQuintaParte = quintaParte / 7;  
  cout << "La séptima parte de la quinta parte de: " << valor << " es: " << septimaDeQuintaParte << endl;

  */

  /*
  1.2.1.4.:
   int a, b;

   cout << "Ingrese dos números enteros distintos entre sí: ";
   cin >> a >> b;  

   if (a > b)
   {
    cout << a << " es mayor que " << b << endl;
   } 
   else
   {
    cout << b << " es mayor que " << a << endl;
   }  */

  /*
  1.2.1.5.:
  
   int a, b;

   cout << "Ingrese dos números enteros: ";
   cin >> a >> b;  

   if(a == b)
   {
    cout << "Los valores ingresados son iguales" << endl;
   }
   else
   {
    if(a > b)
    {
        cout << "El mayor número es: " << a << endl;
        cout << "El menor número es: " << b << endl;
    }
    else
    {
        cout << "El mayor número es: " << b << endl;
        cout << "El menor número es: " << a << endl;
    }
   }
  */

 /*
  1.2.1.6.:
 
  int a, b, c;
  int mayor, medio, menor;
  cout <<"Ingrese tres números enteros diferentes entre sí: ";
  cin >> a >> b >> c;  

  if (a > b && a > c)
  {
    mayor = a;
    if(b > c)
    {
      medio = b;
      menor = c;
    }
    else
    {
      medio = c;
      menor = b;
    }
  }
  else if(b > a && b > c)
  {
    mayor = b;
    if(a > c)
    {
      medio = a;
      menor = c;
    }
    else
    {
      medio = c;
      menor = a;
    }
  }
  else if(c > a && c > b)
  {
    mayor = c;
    if(a > b)
    {
      medio = a;
      menor = b;
    }
    else
    {
      medio = b;
      menor = a;
    }
  }

  cout << "El mayor valor es: " << mayor << endl;
  cout << "El menor valor es: " << menor << endl;
  cout << "El valor medio es: " << mayor << endl;
 */

/*
1.2.1.7.:

int lado1, lado2, lado3;

cout << "Ingrese los lados del triángulo: ";
cin >> lado1 >> lado2 >> lado3;

if (lado1 == lado2 && lado1 == lado3)
{
  cout << "El triángulo es equilátero." << endl;
}
else if((lado1 == lado2 && lado1 != lado3) || (lado1 == lado3 && lado1 != lado2) || (lado2 == lado3 && lado2 != lado1))
{
  cout << "El triángulo es isósceles." << endl;
}
else if(lado1 != lado2 && lado1 != lado3 && lado2 != lado3)
{
  cout << "El triángulo es escaleno." << endl;
}
return 0;
}
*/

/*
1.2.1.8.

int fecha, dia, mes, anio;

cout <<"Ingrese una fecha: ";
cin >> fecha;
//AAAAMMDD
anio = fecha / 10000;
mes = (fecha % 10000) /100;
dia = fecha % 100;

cout << "Día: " << dia << endl;
cout << "Mes: " << mes << endl;
cout << "Año: " << anio << endl;
*/

/*
1.2.1.9.

int fecha, dia, mes, anio;
//fecha: AAAAMMDD

cout <<"Ingrese los datos correspondientes a la fecha: ";
cin >> dia >> mes >> anio;

fecha = dia + mes * 100 + anio * 10000;
cout <<"La fecha correspindiente es: " << fecha << endl;  
*/

/*
1.2.1.10.

int fecha1, fecha2, fechaActual;


cout <<"Ingrese dos fechas distintas:";
cin >> fecha1 >> fecha2;
//AAAAMMDD

if(abs(fecha1 - fechaActual) < abs(fecha2 - fechaActual))
{
  cout << "La primera fecha es la más próxima a la fecha actual." << endl;
}
else
{
  cout << "La segunda fecha es la más próxima a la fecha actual." << endl;
}
*/

/*
1.2.1.11.
int mes, anio;

cout << "Ingrese mes y año";
cin >> mes >> anio;

if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
{
  cout << "El mes tiene 31 días." << endl;
}else if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
{
  cout << "El mes tiene 30 días." << endl;
}else if (mes == 2)
{
  if((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0))
  {
    cout << "El mes tiene 29 días" << endl;
  }
  else
  {
    cout << "El mes tiene 28 días" << endl;
  }
}
*/

/*
1.2.1.12.1.

int a, b, producto = 0;

cout << "Ingrese dos números enteros positivos o cero: ";
cin >> a >> b;


for(int i = 0; i < b; i++)
{
  producto += a;
}

cout << "El producto entre ambos es: " << producto << endl;
*/

/*
1.2.1.12.2.

int a, b, signo = 1, producto = 0;

cout <<"Ingrese dos números enteros o cero: ";
cin >> a >> b;


if((a < 0 && b > 0) || (b < 0 && a > 0))
{
  signo = -1;
}

a = abs(a);
b = abs(b);

for(int i = 0; i < b; i++)
{
  producto += a;
}

producto *= signo;

cout << "El producto entre ambos números es: " << producto << endl;

return 0;
*/

/*
1.2.1.13.

int numero, factorial = 1;

cout << "Ingrese un número: ";
cin >> numero;

for(int i = 0; i < numero; i++)
{
  factorial *= i;
}

cout << "El factorial de " << numero << " es " << factorial << endl;
*/
/*
1.2.1.14.

int numero, n = 2;
bool tieneMultiplos = false;

cout << "Ingrese un número: ";
cin >> numero;

while(!tieneMultiplos && n < numero)
{
  if(numero % n == 0)
  {
    tieneMultiplos = true;
  }
  n++;
}

if(tieneMultiplos)
{
  cout << numero << " no es un número primo." << endl;
}
else
{
  cout << numero << " es un número primo. " << endl;
}
*/

/*
1.2.1.15.

int n, contador = 0, i = 1;
bool tieneMultiplos = false;

cout << "Ingrese el número de números primos deseados:";
cin >> n;

while(contador < n)
{
  tieneMultiplos = false;
  int j = 2;
  while(!tieneMultiplos && j < i)
  {
    if(i % j == 0)
    {
      tieneMultiplos = true;
    }
    j++;
  }
  if(!tieneMultiplos)
  {
    cout << i << ", ";
    contador++;
  }
  i++;
}

cout << endl;
*/

/*
1.2.1.16.

int n, fibonacci = 1, fibonacciAnterior = 0;

cout << "Indique cuántos números de la serie de Fibonacci desea: ";
cin >> n;

cout << 1 << ", ";
for(int i = 0; i < n; i++)
{
  int temp = fibonacci;
  fibonacci += fibonacciAnterior;
  fibonacciAnterior = temp;
  cout << fibonacci << ", ";
}

cout << endl;
/*

/*
1.2.1.17.

int n, contador = 0,i = 0;

cout <<"Ingrese un número: ";
cin >> n;

while(contador < n)
{
  i++;
  if(i % 5 == 0 && i % 3 != 0)
  {
    if (contador == 0)
    {
      cout << i;
    }
    else
    {
      cout << ", " << i;
     
    }
    contador++;
  }
}
cout << endl;
*/

/*
1.2.1.18.

int n, factorial;

cout << "Ingrese un número positivo y entero: ";
cin >> n;

for(int i = 1; i <= n; i++)
{
  factorial = 1;
  for(int j = 1; j <= i; j++)
  {
    factorial *= j;
  }
  cout << "Factorial de " << i << ": " << factorial << endl;
}
*/

/*
1.2.1.19.

int n, menorIgual12 = 0, mayor12MenorIgual24 = 0, mayor24MenorIgual36 = 0, cero = 0;  

cout <<"Ingrese una tanda de números finalizando con un valor negativo: " << endl;
cin >> n; 

while(n >= 0)
{
  if(n <= 12)
  {
    menorIgual12++;
  }else if (n > 12 && n <= 24)
  {
    mayor12MenorIgual24++;
  }else if(n > 24 && n <= 36)
  {
    mayor24MenorIgual36++;
  }else if (n == 0)
  {
    cero++;
  }

  cin >> n;
}

cout << menorIgual12 << " números menores o iguales a 12" << endl;
cout << mayor12MenorIgual24 << " números mayores a 12 y menores o iguales a 24" << endl;
cout << mayor24MenorIgual36 << " números mayores a 24 y menores o iguales a 36" << endl;
cout << cero << " números iguales a 0" << endl;
*/

/*
1.2.1.20.

int n, positivos = 0, negativos = 0, pares = 0, total = 0, acumPositivos = 0;
double porcentajePares, promedioPositivos, porcentajeNegativos;

cout << "Ingrese una tanda de números finalizando con un cero:";
cin >> n;

while (n != 0)
{
  total++;
  if (n > 0)
  {
    positivos++;
    acumPositivos += n;
  }else if (n < 0)
  {
    negativos++;
  }
  
  if (n % 2 == 0)
  {
    pares++;
  }

  cin >> n;
}

porcentajePares = (static_cast<double>(pares) / total) * 100;
promedioPositivos = (positivos > 0)? static_cast<double>(acumPositivos) / positivos : 0;
porcentajeNegativos = (static_cast<double>(negativos) / total) * 100;

cout << "Cantidad de positivos: " << positivos << endl;
cout << "Cantidad de negativos: " << negativos << endl;
cout << "Porcentaje de pares: " << porcentajePares << "%"<< endl;
cout << "Promedio de positivos: " << promedioPositivos << endl;
cout << "Porcentaje de negativos: " << porcentajeNegativos << "%"<< endl;
*/

/*
1.2.1.21.

int n, mayoresA100 = 0, acumMenoresAMenos10 = 0, acumMayoresA100 = 0;
double promedioMayoresA100;

cout << "Ingrese los 50 números:" << endl;
for(int i = 0; i < 50; i++)
{
  cin >> n;
  if (n > 100)
  {
    mayoresA100++;
    acumMayoresA100 += n;
  }else if (n < -10)
  {
    acumMenoresAMenos10 += n;
  }
}

promedioMayoresA100 = static_cast<double>(acumMayoresA100)/mayoresA100; 

cout << "El promedio de los números mayores a 100 es: " << promedioMayoresA100 << endl; 
cout << "La sumatoria de los números menores a -10 es: " << acumMenoresAMenos10 << endl;
return 0;
*/

/*
1.2.1.22.

int n, a, b, multiplo, i, contador = 0;

cout <<"Ingrese n, a y b: ";
cin >> n >> a >> b;

i = a;

while(contador < n)
{
  if(i % a == 0 && i % b != 0)
  {
    contador++; 
  }
  i++;
}

multiplo = i - 1; 

cout << "El enésimo múltiplo de " << a << " que no es múltiplo de " << b << " es: " << multiplo << endl;
*/

/*
1.2.1.23.

int n, mayor;

cout << "Ingrese una tanda de 100 números enteros positivos:" << endl;
cin >> n;
mayor = n;
for(int i = 0; i < 99; i++)
{
  cin >> n;
  if (n > mayor)
  {
    mayor = n;
  }
}

cout << "El mayor número de la tanda es: " << mayor << endl;
*/

/*
1.2.1.24.


int n, menor;

cout << "Ingrese una tanda de 100 números:" << endl;

cin >> n;
menor = n;

for (int i = 0; i < 99; i++)
{
  cin >> n;
  if (n < menor)
  {
    menor = n;
  }
}

cout << "El menor número de la tanda es: " << menor << endl;
*/

/*
1.2.1.25.

int n, mayorDeNegativos, menorDePositivos;
bool primerPositivo = false, primerNegativo = false;
cout << "Ingrese una tanda de números finalizando con un 0:" << endl;
cin >> n;

while(n != 0)
{
  if(n < 0 && !primerNegativo)
  {
    mayorDeNegativos = n;
    primerNegativo = true; 
  }else if(n > 0 && !primerPositivo)
  {
    menorDePositivos = n;
    primerPositivo = true;
  }else if(n < 0)
  {
    if(n > mayorDeNegativos)
    {
      mayorDeNegativos = n;
    }
  }else
  {
    if(n < menorDePositivos)
    {
      menorDePositivos = n;
    }  }
  
  cin >> n;
}

cout << "El mayor número negativo es: " << mayorDeNegativos << endl;
cout << "El menor número positivo es: " << menorDePositivos << endl;
*/

/*
1.2.1.26.

int n, menor;
bool primero = false;
cout << "Ingrese una tanda de números finalizando con un 0:" << endl;
cin >> n;

while(n != 0)
{
  if(n >= -16 && n <= 27 && !primero)
  {
    menor = n;
  }else if(n >= -16 && n <= 27 && n < menor)
  {
    menor = n;
  }
  cin >> n;  
}

cout << "El menor número en el intervalo [-16, 27] ingresado es: " << menor << endl;
*/

/*
1.2.1.27.

int fecha, fechaMasReciente, fechaMasAntigua;
string nombre, masJoven, masVieja;
bool primero = false;

cout <<"Ingrese un conjunto de nombres de personas con sus respectivas fechas de nacimiento: " << endl;
cin >> nombre >> fecha;

while(nombre != "fin")
{
  if(!primero)
  {
    masJoven = nombre;
    fechaMasReciente = fecha;

    masVieja = nombre;
    fechaMasAntigua = fecha;

    primero = true;
  }else if(fecha > fechaMasReciente)
  {
    masJoven = nombre;
    fechaMasReciente = fecha;
  }else if(fecha < fechaMasAntigua)
  {
    masVieja = nombre;
    fechaMasAntigua = fecha;
  }

  cin >> nombre >> fecha;
}
cout <<"La persona más joven es: " << masJoven << endl;
cout <<"La persona más vieja es: " << masVieja << endl;
*/

/*
1.2.1.28.

int n, m, numero, sumConjunto, contConjunto,
  positivosConjunto, sumTotal = 0, contTotal = 0, negativosTotal = 0, minimoTotal;
double promedioConjunto, promedioTotal, porcentajePositivosConjunto, porcentajeNegativosTotal;        
bool primeroConjunto, primeroTotal;

cout <<"Indique cuántos conjuntos, de cuántos números serán ingresados: " << endl;
cin >> n >> m;

primeroTotal = false; 
for(int i = 0; i < n; i++)
{
  cout << "Conjunto: " << i + 1 << endl;

  primeroConjunto = false;
  int maximoConjunto;
  sumConjunto = 0;
  contConjunto = 0;
  positivosConjunto = 0;

  for(int j = 0; j < m; j++)
  {
    cin >> numero;
    sumConjunto += numero;
    contConjunto++;
    sumTotal += numero;
    contTotal++;

    if(numero > 0)
    {
      positivosConjunto++;
    }else if (numero < 0)
    {
      negativosTotal++;
    }
    

    if(!primeroConjunto)
    {
      maximoConjunto = numero;
      primeroConjunto = true;
    }else if (numero > maximoConjunto)
    {
      maximoConjunto = numero;
    }
    
    if(!primeroTotal)
    {
      minimoTotal = numero;
      primeroTotal = true;
    }else if (numero < minimoTotal)
    {
      minimoTotal = numero;
    }
  }

  promedioConjunto = static_cast<double>(sumConjunto)/contConjunto;
  porcentajePositivosConjunto = static_cast<double>(positivosConjunto) / contConjunto * 100;

  cout << "El promedio del conjunto es: " << promedioConjunto << endl;
  cout << "El porcentaje de positivos del conjunto es: " << porcentajePositivosConjunto << "%" << endl;
  cout << "El máximo valor del conjunto es: " << maximoConjunto << endl;
}

  promedioTotal = static_cast<double>(sumTotal)/contTotal;
  porcentajeNegativosTotal = static_cast<double>(negativosTotal)/ contTotal * 100;

  cout << "El promedio de todo el lote de datos es: " << promedioTotal << endl;
  cout << "El porcentaje de negativos de todo el lote de datos es: " << porcentajeNegativosTotal << "%" << endl;
  cout << "El mínimo valor de todo el lote de datos es: " << minimoTotal << endl;
  
  return 0;
  */

 /*
 1.2.1.29.
 
int n, sumSubconjunto, contSubconjunto, minimoSubconjunto, subConjuntos = 0, sumTotal = 0, mayordeConjunto, subconjuntodeMayor, posicionDeMayor;
double promedioSubconjunto;   
bool primeroDeSubconjunto, primeroDeConjunto = false;

cout << "Ingrese un conjunto de valores enteros positivos, finalizando con un número negativo, y separando los subconjuntos con  un 0: "<< endl;
cin >> n;


while(n >= 0)
{
  subConjuntos++;
  int i = 0;
  primeroDeSubconjunto = false;
  sumSubconjunto = 0;
  contSubconjunto = 0;

  while(n != 0)
  {
    i++;
    sumSubconjunto += n;
    contSubconjunto++;
    sumTotal += n;

    if(!primeroDeSubconjunto)
    {
      minimoSubconjunto = n;
      primeroDeSubconjunto = true;
    }else if (n < minimoSubconjunto)
    {
      minimoSubconjunto = n;
    }
    
    if(!primeroDeConjunto)
    {
      mayordeConjunto = n;
      subconjuntodeMayor = subConjuntos;
      posicionDeMayor = i;
      primeroDeConjunto = true;
    }else if (n > mayordeConjunto)
    {
      mayordeConjunto = n;
      subconjuntodeMayor = subConjuntos;
      posicionDeMayor = i;
    }

    cin >> n;
  }
  promedioSubconjunto = static_cast<double>(sumSubconjunto) / contSubconjunto;
    
  cout <<"El promedio del subconjunto es: " << promedioSubconjunto << endl;
  cout <<"El mínimo valor del subconjunto es: " << minimoSubconjunto << endl;


  cin >> n;
}

cout << "La cantidad de subconjuntos es: " << subConjuntos << endl;
cout << "La sumatoria de los números ingresados es: " << sumTotal << endl;
cout << "El número del subconjunto en el que se ingresó el mayor valor es: " << subconjuntodeMayor << "; el número ingresado fue: " << mayordeConjunto << ", en la posición: " << posicionDeMayor << endl;
*/

/*
1.2.1.30.

int n, anterior, seguidilla = 0, contSeguidillas = 0, seguidillaMasLarga = 0;
bool seguidillaIniciada = false;
cout <<"Ingrese un conjunto de valores numéricos enteros que finaliza con un 0: " << endl;
cin >> n;

anterior = n;

while(n != 0)
{
  if(n > anterior && !seguidillaIniciada)
  {
    seguidilla = 2;
    contSeguidillas++;
    seguidillaIniciada = true;
  }else if(n > anterior)
  {
    seguidilla++;
  }else if(seguidillaIniciada)
  {
    cout << "Última seguidilla: "<< seguidilla << " elementos" << endl;
    if(seguidilla > seguidillaMasLarga)
    {
      seguidillaMasLarga = contSeguidillas;
    }
    seguidilla = 1;
    seguidillaIniciada = false;
  }
  cin >> n;
  anterior = n;
}

if(seguidillaIniciada && seguidilla > seguidillaMasLarga)
{
  seguidillaMasLarga = seguidilla
}

cout << "Cantidad de seguidillas: " << contSeguidillas << endl;
cout << "Seguidilla más larga se ingresó en la posición relativa: " << seguidillaMasLarga << endl;
return 0;
*/

/*
1.2.1.31.
*/
int contA = 0, contE = 0, contI = 0, contO = 0, contU = 0, contPalabras = 0, palabraMasLarga = 0, palabra = 0, palabraAnterior = 0;
bool longitudCreciente = true, palabraIniciada = false;
char caracter;

cout << "Ingrese uno a uno la serie de caracteres: " << endl;
cin >> caracter;


while(caracter != '.')
{
  if(caracter != ' ')
  {
    if(caracter == 'a' || caracter == 'A')
    {
      contA++;
    }else if(caracter == 'e' || caracter == 'E')
    {
      contE++;
    }else if(caracter == 'i' || caracter == 'I')
    {
      contI++;
    }else if(caracter == 'o' || caracter == 'O')
    {
      contO++;
    }else if (caracter == 'u' || caracter == 'U')
    {
      contU++;
    }

    if(!palabraIniciada)
    {
      contPalabras++;
      palabra = 1; 
      palabraIniciada = true;
    }else
    {
      palabra++;
    } 
  }else if(palabraIniciada)
  {
    if(palabra > palabraMasLarga)
    {
      palabraMasLarga = palabra;
    }
    if(palabra < palabraAnterior)
    {
      longitudCreciente = false;
    }
    palabraIniciada = false;
    palabraAnterior = palabra;
  }
  cin >> caracter; 
}

if(palabraIniciada)
{
  if(palabra > palabraMasLarga)
  {
    palabraMasLarga = palabra;
  }
  if(palabra < palabraAnterior)
  {
    longitudCreciente = false;
  }
}


cout << "La cantidad de a's es: " << contA << endl;
cout << "La cantidad de e's es: " << contE << endl;
cout << "La cantidad de i's es: " << contI << endl;
cout << "La cantidad de o's es: " << contO << endl;
cout << "La cantidad de u's es: " << contU << endl;
cout << "La cantidad de palabras en la oración es: " << contPalabras << endl;
cout << "La cantidad de letras de la palabra más larga es: " << palabraMasLarga << endl;
if(longitudCreciente)
{
  cout << "La longitud de las palabras que componen la oración es creciente. " << endl;
}

}