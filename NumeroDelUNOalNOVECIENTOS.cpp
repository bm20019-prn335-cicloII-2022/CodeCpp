#include "iostream"

using namespace std;
std::string ConvertInttoLetter(int numero);
bool esdigito(string integer);

int main(int argc, char const* argv[])
{
    bool salir = true;
    while (salir)
    {
        string xStr;
        int x;
        cout << "Ingrese un numero (si desea salir escriba -1)" << endl;
        cin >> xStr;
        if (esdigito(xStr)) {//Comprueba si el dato ingesado es un digito entero
            x = stoi(xStr);//Convierte el string en un numero entero
            if (x == -1)//Si x es -1 entonces el programa se cerrara
                salir = false;
            else {
                if ((x < 1) || (x > 999))
                    cout << "Ingresa un numero del 1 al 999\n";
                else {
                    cout << ConvertInttoLetter(x) << endl;
                }
            }
        }
        else {
            cout << "El dato ingresado no parece ser un numero entero: \""<<xStr.c_str()<<"\""<<endl;
            return -1;
        }
    }
    return 0;
}

/*
*   comprueba si un string es un numero entero
*/
bool esdigito(string integer){
    for (int i = 0; i < integer.length(); i++)
    {
        if(!isdigit(integer[i])){
            return false;
        }
    }
    return true;
}

/*
*   retorna el nombre del numero ingresado
*/
std::string ConvertInttoLetter(int numero) {
    string charNumero = to_string(numero);//conviete en string el numero para manipularlo en char
    if (charNumero.length() == 2)//si se escribe una cantidad de decena se agrega un 0 para completar la centena
        charNumero = "0" + charNumero;
    else if (charNumero.length() == 1)//si se escribe una cantidad de unidad se agrega dos 0 para completar la centena y decena
        charNumero = "00" + charNumero;

    //a charNumero se le resta 48 para obtener el valor del numero. (de ASCII a Entero)
    int unidadNumero = (int)charNumero[2] - 48, decenaNumero = (int)charNumero[1] - 48, CentenaNumero = (int)charNumero[0] - 48;
    std::string unidadStr = "", decenaStr = "", centenaStr = "", resultado = "";

    if (unidadNumero > 0) {
        switch (unidadNumero) {//Nombra los numeros del 1 al 9
        case 1:
            unidadStr = "uno";
            break;
        case 2:
            unidadStr = "dos";
            break;
        case 3:
            unidadStr = "tres";
            break;
        case 4:
            unidadStr = "cuatro";
            break;
        case 5:
            unidadStr = "cinco";
            break;
        case 6:
            unidadStr = "seis";
            break;
        case 7:
            unidadStr = "siete";
            break;
        case 8:
            unidadStr = "ocho";
            break;
        case 9:
            unidadStr = "nueve";
            break;
        default:
            break;
        }
    }
    if (decenaNumero == 1 && unidadNumero > 0 && unidadNumero < 6) {//nombres de numeros que no se pueden concatenar
        switch (unidadNumero)//en este caso solo son 5: once, doce, trece, catorce, quince.
        {
        case 1:
            decenaStr = "once";
            break;
        case 2:
            decenaStr = "doce";
            break;
        case 3:
            decenaStr = "trece";
            break;
        case 4:
            decenaStr = "catorce";
            break;
        case 5:
            decenaStr = "quince";
            break;
        default:
            break;
        }
        unidadStr = "";//limpia la variable, para no mostrar ningun valor en pantalla
    }
    else {//Sino es un numero especial, osea que si se puede concatenar
        switch (decenaNumero) {
        case 1:
            decenaStr = "diez";
            break;
        case 2:
            decenaStr = "veinte";
            break;
        case 3:
            decenaStr = "treinta";
            break;
        case 4:
            decenaStr = "cuarenta";
            break;
        case 5:
            decenaStr = "cincuenta";
            break;
        case 6:
            decenaStr = "sesenta";
            break;
        case 7:
            decenaStr = "setenta";
            break;
        case 8:
            decenaStr = "ochenta";
            break;
        case 9:
            decenaStr = "noventa";
            break;
        default:
            break;
        }
        if (unidadNumero > 0 && decenaNumero > 0) {//si la unidad es mayor a 0 se le agrega el 'y' para mostrarlo en pantalla
            decenaStr = decenaStr + " y";
        }
    }
    if (CentenaNumero > 0) {//Nombrar las centenas de los numeros
        switch (CentenaNumero)
        {
        case 1:
            if (decenaNumero == 0 && unidadNumero == 0)//en este caso: cuando es 100 entonces se imprime 'cien', pero cuando >100 entonces se imprime 'ciento'
                centenaStr = "cien";
            else
                centenaStr = "ciento";
            break;
        case 2:
            centenaStr = "doscientos";
            break;
        case 3:
            centenaStr = "trecientos";
            break;
        case 4:
            centenaStr = "cuatrocientos";
            break;
        case 5:
            centenaStr = "quinientos";
            break;
        case 6:
            centenaStr = "seiscientos";
            break;
        case 7:
            centenaStr = "setecientos";
            break;
        case 8:
            centenaStr = "ochocientos";
            break;
        case 9:
            centenaStr = "novecientos";
            break;
        default:
            break;
        }
    }
    //agrega los espacios necesarios
    if (centenaStr.length() > 0)
        centenaStr = centenaStr + " ";
    if (decenaStr.length() > 0)
        decenaStr = decenaStr + " ";
    return centenaStr + decenaStr + unidadStr;  //concatena los resultados y los retorna
}