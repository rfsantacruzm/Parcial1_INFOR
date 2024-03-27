#include <iostream>

using namespace std;

void imprimirmatriz(int n){
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
                cout<<'\t'<<p[i][j];

            }else{
                p[i][j]=contador;
                cout<<'\t'<<p[i][j];
                contador++;
            }
        }
        cout<<'\n';

    }

    for(int i=0; i<n; i++){
        delete[]  p[i];
    }
    delete[] p;

}

void rotarmatriz1(int n){
    int contador, con=2;
    int temp=(n/2);
    int **p= new int*[n];
    for (int i = 0; i < n; ++i) {
        p[i]=new int[n];
    }
    contador=n;
    for (int i = 0; i < n; i++) {
        //contador=n*i+1;
        for (int j = 0; j < n; ++j) {
            if(i==temp && j==temp){
                p[j][i]=0;


            }else{
                p[j][i]=contador;

                contador--;
            }
        }
        cout<<'\n';

        if (i<temp-1)
        {
            contador=con*n;
            con++;
        }else{
            contador=(con*n)-1;
            con++;
        }

    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << p[i][j] << '\t';
        }
        cout << '\n';

    }
    for(int i=0; i<n; i++){
        delete[]  p[i];
    }
    delete[] p;
}
void rotarmatriz2(int n){
    int contador, matriz=n*n;
    int temp=(n/2);
    int **p= new int*[n];
    for (int i = 0; i < n; ++i) {
        p[i]=new int[n];
    }
    contador=matriz-1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(i==temp && j==temp){
                p[i][j]=0;
                cout<<'\t'<<p[i][j];

            }else{
                p[i][j]=contador;
                cout<<'\t'<<p[i][j];
                contador--;
            }
        }
        cout<<'\n';

    }

    for(int i=0; i<n; i++){
        delete[]  p[i];
    }
    delete[] p;


}


void rotarmatriz3(int n){
    int contador, con=n-2, matriz=n*n;
    int temp=(n/2);
    int **p= new int*[n];
    for (int i = 0; i < n; ++i) {
        p[i]=new int[n];
    }
    contador=matriz-n;
    for (int i = 0; i < n; i++) {
        //contador=n*i+1;
        for (int j = 0; j < n; ++j) {
            if(i==temp && j==temp){
                p[j][i]=0;


            }else{
                p[j][i]=contador;

                contador++;

            }
        }
        cout<<'\n';

        if (i<temp-1)
        {
            contador=con*n;
            con--;
        }else{
            contador=(con*n)+1;
            con--;
        }

    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << p[i][j] << '\t';
        }
        cout << '\n';

    }
    for(int i=0; i<n; i++){
        delete[]  p[i];
    }
    delete[] p;
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











