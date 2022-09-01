#include "iostream"
using namespace std;

struct contrato
{
    int Dia;
    int Mes;
    int Year;
    int Contrato;
};

void intercambio(contrato &a, contrato &b);
void mostrar(contrato array[], int n);
void ordenar(contrato array[], int n);

int main()
{
    contrato contrato1;
    contrato1.Contrato = 1;
    contrato1.Dia = 2;
    contrato1.Mes = 4;
    contrato1.Year = 2022;

    contrato contrato2;
    contrato2.Contrato = 2;
    contrato2.Dia = 3;
    contrato2.Mes = 7;
    contrato2.Year = 2012;

    contrato contrato3;
    contrato3.Contrato = 3;
    contrato3.Dia = 6;
    contrato3.Mes = 3;
    contrato3.Year = 2005;

    contrato contrato4;
    contrato4.Contrato = 4;
    contrato4.Dia = 23;
    contrato4.Mes = 7;
    contrato4.Year = 2021;

    contrato contratos[50] = {contrato4, contrato2, contrato1, contrato3};

    cout<< "Lista original:"<<endl;
    mostrar(contratos, 50);
    ordenar(contratos,50);
    cout<< "\nLista Ordenada: "<< endl;
    mostrar(contratos,50);
    return 0;
}
void ordenar(contrato array[], int n)
{
    int i = 0, j = 0;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            int valor1 = array[i].Year;
            int valor2 = array[j].Year;
            if (valor1 > valor2)
            {
                intercambio(array[i], array[j]);
            }
        }
    }
}
void intercambio(contrato &a, contrato &b)
{
    contrato auxiliar = a;
    a = b;
    b = auxiliar;
}
void mostrar(contrato array[], int n)
{
    int contador = 0;
    for (int i = 0; i < n; i++)
    {
        if (array[i].Contrato > 0)
        {
            cout << "fecha:" << array[i].Dia << "/" << array[i].Mes << "/" << array[i].Year << " Contrato: " << array[i].Contrato << endl;
        }
    }
}