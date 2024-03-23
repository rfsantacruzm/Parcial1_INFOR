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
    bool kvalid = false;
    while (kvalid == false) {
        for(int i = 0; i < k; ++i){
            cout <<"Ingrese el digito en la pos "<< i+1<< ": ";
            cin>>n;
            clave[i] = n;
        }
        for(int j=2; j<k; ++j){
            if(clave[j]< -1 || clave[j]>1){
                cout<<"Clave no valida, intente nuevamente"<<endl;
                kvalid = false;
                break;
            }
            else{
                kvalid = true;
            }
        }
    }
    int tamano = definirtamano(clave);
    int cantm = k-1;

    return 0;
}
