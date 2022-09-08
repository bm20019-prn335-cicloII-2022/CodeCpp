#include "iostream"
#include "time.h"
using namespace std;

void intercambio(int &a, int &b);
void ordenar(int a[], int n);
void mostrar(int array[], int n);
bool esPrimo(int numero);
int mediana(int vector[], int length);
int moda(int vector[], int length);
void MostrarGrupos(int array[], int n);

int main()
{
    int length = 1000;
    int milNumeros[length] = {};
    srand(time(NULL)); // Para que rand() genere numeros "aleatorios" y no "Pseudo Aleatorios"
    for (int i = 0; i < length; i++)
    {
        milNumeros[i] = rand() % 100;
    }
    ordenar(milNumeros, length);
    cout << "Orden creciente:" << endl;
    mostrar(milNumeros, length);
    cout << endl
         << endl
         << "La mediana es: " << mediana(milNumeros, length);
    cout << endl
         << "La moda es: " << moda(milNumeros, length) << endl;
    MostrarGrupos(milNumeros, length);
    return 0;
}
int moda(int vector[], int length) // Calculamos la moda
{
    int contador1 = 0, contador2 = 0, moda = 0;
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if (vector[i] == vector[j] && i != j)
                contador1++;
        }
        if (contador1 > contador2)
        {
            contador2 = contador1;
            moda = vector[i];
        }
        contador1 = 0;
    }
    return moda;
}
int mediana(int vector[], int length) // Calcular la mediana
{
    if (esPrimo(length))
    {
        int posicion = (length + 1) / 2;
        return vector[posicion - 1];
    }
    else
    {
        int x1 = length / 2;
        int x2 = x1 + 1;
        return (vector[x1] + vector[x2]) / 2;
    }
}
bool esPrimo(int numero) // Comprobar si el numero es primo o es par; si en primo True, si es para es False
{
    if (numero == 0 || numero == 1 || numero == 4)
        return false;
    for (int x = 2; x < numero / 2; x++)
    {
        if (numero % x == 0)
            return false;
    }
    return true;
}
void intercambio(int &a, int &b)
{
    int auxiliar = a;
    a = b;
    b = auxiliar;
}
void ordenar(int a[], int n)
{
    int i = 0, j = 0;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                intercambio(a[i], a[j]);
            }
        }
    }
}
void mostrar(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (n - i == 1)
            cout << array[i];
        else
            cout << array[i] << ", ";
    }
}
void MostrarGrupos(int array[], int n)
{
    cout << endl
         << endl
         << "\"Menores a 30:\"" << endl;
    for (int i = 0; i < n; i++)
    {
        if (array[i] < 30)
            cout << array[i] << ", ";
    }
    cout << endl
         << endl
         << "\"Mayores a 70:\"" << endl;
    for (int i = 0; i < n; i++)
    {
        if (array[i] > 70)
            cout << array[i] << ", ";
    }
    cout << endl
         << endl
         << "\"Entre 30 y 70:\"" << endl;
    for (int i = 0; i < n; i++)
    {
        if (array[i] <= 70 && array[i] >= 30)
            cout << array[i] << ", ";
    }
    cout << endl;
}