#include "iostream"

using namespace std;
bool esDigito(std::string integer);

int main(){

    return 0;
}
bool esDigito(std::string integer){
    bool result = true;
    char Numeros[10] = {'0','1','2','3','4','5','6','7','8','9'};
    for (int i = 0; i < integer.length(); i++)
    {
        char numero = integer[i];
        for (int i = 0; i < 10; i++)
        {
            if(Numeros[i]!=numero){
                result = false;
            }
        }
    }
    return result;
}