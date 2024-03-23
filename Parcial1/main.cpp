#include <iostream>

using namespace std;

int definirtamano(int* clave){
    int tamano;
    if(clave[0]>= clave[1]){
        if(clave[0]%2 ==0){
            tamano = clave[0]+1;
        }
        else {
            tamano = clave[0];
        }
    }
    else {
        if(clave[1]%2 ==0){
            tamano = clave[1]+1;
        }
        else {
            tamano = clave[1];
        }
    }
    return tamano;
}
int main()
{
    int k, n;
    cout << "Ingrese el tamano de la clave k: " <<endl;
    cin>> k;
    int* clave = new int;
    for(int i = 0; i < k; ++i){
        cout <<"Ingrese el digito en la pos "<< i+1<< ": ";
        cin>>n;
        clave[i] = n;
    }
    int tamano = definirtamano(clave);
    return 0;
}
