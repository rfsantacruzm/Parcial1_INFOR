#include <iostream>

using namespace std;

int definirtamano(int* c){
    int tamano;
    if(c[0]>= c[1]){
        if(c[0]%2 ==0){
            tamano = c[0]+1;
        }
        else {
            tamano = c[0];
        }
    }
    else {
        if(c[1]%2 ==0){
            tamano = c[1]+1;
        }
        else {
            tamano = c[1];
        }
    }
    return tamano;
}
void imprimirmatriz(int** p, int n){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << '\t' << p[i][j];
        }
        cout << '\n';
    }
}
int** crearMatriz(int n){
    int contador=1;
    int temp=(n/2);
    int **p= new int*[n];
    for (int i = 0; i < n; ++i) {
        p[i]=new int[n];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(i==temp && j==temp){
                p[i][j]=0;
            }
            else{
                p[i][j]=contador;
                contador++;
            }
        }
    }
    return p;
}
int** rotarmatriz1(int** p, int n){
    int contador, con=2;
    int temp=(n/2);
    contador=n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; ++j) {
            if(i==temp && j==temp){
                p[j][i]=0;
            }
            else{
                p[j][i]=contador;
                contador--;
            }
        }
        if (i<temp-1)
        {
            contador=con*n;
            con++;
        }
        else{
            contador=(con*n)-1;
            con++;
        }
    }
    return p;
}
int** rotarmatriz2(int** p, int n){
    int contador, matriz=n*n;
    int temp=(n/2);
    contador=matriz-1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(i==temp && j==temp){
                p[i][j]=0;
            }
            else{
                p[i][j]=contador;
                contador--;
            }
        }
    }
    return p;
}
int** rotarmatriz3(int** p, int n){
    int contador, con=n-2, matriz=n*n;
    int temp=(n/2);
    contador=matriz-n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; ++j) {
            if(i==temp && j==temp){
                p[j][i]=0;
            }
            else{
                p[j][i]=contador;
                contador++;
            }
        }
        if (i<temp-1)
        {
            contador=con*n;
            con--;
        }else{
            contador=(con*n)+1;
            con--;
        }
    }
    return p;
}
int **matrizfondomenor (int tamano, int v, int fila, int columna){
    int **p = crearMatriz(tamano);
    int num = p[fila][columna];
    if(num >= v){
        p = rotarmatriz1(p, tamano);
        num = p[fila][columna];
        if(num >= v){
            p = rotarmatriz2(p, tamano);
            num = p[fila][columna];
            if(num >= v){
                p = rotarmatriz3(p, tamano);
                cout<<"Rotacion: 3\n"<<"Dimencion: "<<tamano<<endl;
            }
            else{
                cout<<"Rotacion: 2\n"<<"Dimencion: "<<tamano<<endl;
            }
        }
        else{
            cout<<"Rotacion: 1\n"<<"Dimencion: "<<tamano<<endl;
        }
    }
    else{
        cout<<"Rotacion: Neutra\n"<<"Dimencion: "<<tamano<<endl;
    }
    return p;
}
int **matrizfondomayor (int tamano, int v, int fila, int columna){
    int **p = crearMatriz(tamano);
    int num = p[fila][columna];
    if(num <= v){
        p = rotarmatriz1(p, tamano);
        num = p[fila][columna];
        if(num <= v){
            p = rotarmatriz2(p, tamano);
            num = p[fila][columna];
            if(num <= v){
                p = rotarmatriz3(p, tamano);
                cout<<"Rotacion: 3\n"<<"Dimencion: "<<tamano<<endl;
            }
            else{
                cout<<"Rotacion: 2\n"<<"Dimencion: "<<tamano<<endl;
            }
        }
        else{
            cout<<"Rotacion: 1\n"<<"Dimencion: "<<tamano<<endl;
        }
    }
    else{
        cout<<"Rotacion: Neutra\n"<<"Dimencion: "<<tamano<<endl;
    }
    return p;
}
int *buscar_posicion(const int *clave, int siguiente_matriz){
    int *ptr=new int[2];
    int fila=clave[0], columna=clave[1];
    if (siguiente_matriz==1){
        fila+=1;
        columna+=1;
    }else if(siguiente_matriz==-1){
        fila-=1;
        columna-=1;
    }
    ptr[0]=fila;
    ptr[1]=columna;
    return ptr;
}
int main()
{
    int k, n;
    cout << "Ingrese el tamano de la clave k: " <<endl;
    cin>> k;
    int* clave = new int[k];
    bool kvalid = false;
    while (kvalid == false) {
        for(int i=0;i<k;++i){
            cout <<"Ingrese el digito en la pos "<< i+1<< ": ";
            cin>>n;
            clave[i] = n;
        }
        for(int j=2;j<k;++j){
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
    int cantm = k-2;
    int **m = crearMatriz(tamano);
    cout<<"Matriz original\n"<<"Dimencion: "<<tamano<<endl;
    imprimirmatriz(m, tamano);
    int v = m[clave[0]][clave[1]];
    for(int i=0;i<=cantm;++i){
        for(int j=2; j<k;++j){
            int cond = clave[j];
            int *posicion = buscar_posicion(clave, cond);
            int fila = posicion[0];
            int columna = posicion[1];
            int nuevotam = definirtamano(posicion);
            if(cond == -1){
                int **p = matrizfondomenor(nuevotam, v, fila, columna);
                imprimirmatriz(p, nuevotam);
                v = p[fila][columna];;
                for(int i=0; i<nuevotam; i++){
                    delete[]  p[i];
                }
                delete[] p;
            }
            else if(cond== 1){
                int **p = matrizfondomayor(nuevotam, v, fila, columna);
                imprimirmatriz(p, nuevotam);
                v = p[fila][columna];
                for(int i=0; i<nuevotam; i++){
                    delete[]  p[i];
                }
                delete[] p;
            }
            else{
                int **p = crearMatriz(tamano);
                imprimirmatriz(p, tamano);
                cout<<"Rotacion: Neutra\n"<<"Dimencion: "<<nuevotam<<endl;
                v = p[fila][columna];
                for(int i=0; i<tamano; i++){
                    delete[]  p[i];
                }
                delete[] p;
            }
            delete[] posicion;
        }
    }
    for(int i=0; i<tamano; i++){
        delete[]  m[i];
    }
    delete[] m;
    delete[] clave;
    return 0;
}
