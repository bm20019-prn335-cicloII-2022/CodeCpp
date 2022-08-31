#include "iostream"
using namespace std;
void mostrar(int array[], int n);
void intercambio(int &a, int &b);
template <class T>
bool contiene(T vector[], T search,int n);
void ordenar(int a[], int n);
void noDuplicar(int vector[], int n);

int main()
{
    int vector[10] = {4, 7, 11, 4, 9, 5, 11, 7, 3, 5};
    cout << "Lista original:" << endl;
    mostrar(vector, 10);
    ordenar(vector, 10);
    cout << "\nLista Ordenada:" << endl;
    mostrar(vector, 10);
    cout << "\nLista Simplificada:" << endl;
    noDuplicar(vector, 10);
    cout<<endl;
    return 0;
}

void intercambio(int &a, int &b)
{
    int auxiliar = a;
    a = b;
    b = auxiliar;
}
template <class T>
bool contiene(T vector[], T search,int n)//busca en un array, un valor especifico
{
    for (int i = 0; i < n; i++)
    {
        if (vector[i] == search)
        {
            return true;
        }
    }
    return false;
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

void noDuplicar(int vector[], int n)//metodo para mostrar los datos no duplicados
{
    int i = 0;
    int j = 1;
    int contador = 0;
    int vectorTmp[n] = {};
    for (int i = 0; i < n; i++)
    {
        int a = vector[i];
        if (contiene(vectorTmp, a, n) == false)
        {
            vectorTmp[contador] = a;
            contador++;
        }
    }
    int vectorNuevo[contador] = {};
    for (int i = 0; i < contador; i++)
    {
        vectorNuevo[i] = vectorTmp[i];
    }
    mostrar(vectorNuevo,contador);
}
void mostrar(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << ", ";
    }
}