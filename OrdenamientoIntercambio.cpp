#include "iostream"
using namespace std;

void intercambiar(int &x, int &y){
    int aux= x;
    x=y;
    y= aux;
}

void ordenar(int a[], int n){
    int i, j;
    for(i=0;n-1;i++){
        for(i=i+1;j<n;j++){
            if(a[i]>a[j]){
                intercambiar(a[i],a[j]);
            }
        }
    }
}
void mostrar(int a[], int n){
    for(int i= 0; i < n;i++){
        cout << a[i] << " ";
    }    
}

int main(){
    int lista[20] = {30,35,38,58,14,15,50,27,10,20,12,85,49,65,86,60,25,90,5,16};
    int i;
    cout << "Lista Original \n";
    mostrar(lista,20);
    ordenar(lista,20);
    cout << endl << "Lista ordenada " << endl;
    mostrar(lista,20);
}