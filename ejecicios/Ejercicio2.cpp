#include "iostream"
using namespace std;
void intercambio(string &a, string &b);
void mostrar(string array[], int n);
void Seleccion(string array[], int count);
int main()
{
    string nombres[10] = {"Mario", "Jorge", "Ernesto", "Karen", "Beatriz", "Carmen", "Leticia", "Jose", "Diego", "Alicia"};
    cout<<"Lista Original:"<<endl;
    mostrar(nombres,10);
    Seleccion(nombres, 10);
    cout<<"\nLista Ordenada:"<<endl;
    mostrar(nombres, 10);
}
void Seleccion(string array[], int count)
{
    int i, j, indiceMin;
    for (int i = 0; i < count; i++)
    {
        indiceMin = i;
        for (int j = i + 1; j < count; j++)
        {
            char letter1 = array[indiceMin][0];
            char letter2 = array[j][0];
            if (letter1 > letter2)
            {
                indiceMin = j;
            }
        }
        intercambio(array[i], array[indiceMin]);
    }
}

void intercambio(string &a, string &b)
{
    string auxiliar = a;
    a = b;
    b = auxiliar;
}
void mostrar(string array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << ", ";
    }
}
