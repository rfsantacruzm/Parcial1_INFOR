#include <iostream>
using namespace std;


int saber_dimencion_matriz( int *clave);
int *buscar_posicion( int *clave, int siguiente_matriz);
void imprimir_matriz( int** matriz, int dimencion);
bool comparar_matrices0(int **ptr1,  int **ptr2, int *clave, int *clave2 );
bool comparar_matrices1(int **ptr1,  int **ptr2, int *clave, int *clave2 );
bool comparar_matrices_menos(int **ptr1,  int **ptr2, int *clave, int *clave2 );
void liberar_memoria(int **ptr, int n);
int **matrices(int n, int rotar);
int *candado(int dimencion1, int *posicion1, int *posicion2);

int main(){
    int n,k, con=0, valor1=0, valor2=0;
    int* ptr1 = nullptr;
    cout << "Ingrese el tamano de la clave k: " <<endl;
    cin>> n;
    int* clave = new int[n];
    bool verificar=false;
    for(int i=0;i<n;++i){
        if(i<2){
            cout <<"Ingrese el digito en la pos "<< i+1<< ": ";
            cin>>k;
            clave[i] = k;
        }else{
            cout <<"Ingrese el digito en la pos "<< i+1<< ": ";
            cin>>k;
            clave[i]=k;
            while(k<-1 || k>1 ){
                cout <<"Ingresante un valor invalido para la posicion  "<< i+1<< " Ingresalo nuevamente. ";
                cin>>k;
                clave[i] = k;
            }


        }
    }
    int dimencion=saber_dimencion_matriz(clave);
    //dimencion2 es la dimencion de la matriz siguiente
    int dimencion2=dimencion;
    //dimencion2+=2;
    int clave2[2];
    clave2[0]=clave[0]; clave2[1]=clave[1];
    //liberar memoria de clave
    for (int i =2 ; i <n ; ++i) {
        //cout<<clave[i]<<endl;
        //cout<<valor1;
        if(clave[i]==1){


        }else if(clave[con]==-1){

        }


    }

    delete[] clave;
    return 0;

}




int saber_dimencion_matriz( int *clave){
    int fila=clave[0];
    int columna=clave[1];
    if(fila>columna){
        if(fila%2==0){
            return fila+1;
        }else{
            return fila;
        }
    }else if(fila<columna){
        if(columna%2==0){
            return columna+1;
        }else{
            return columna;
        }
    }else if (fila==columna)
    {
        if(fila%2==0){
            return fila+1;
        }else{
            return fila;
        }
    }else
    {
        return -1;
    }



}



//recordar liberar la memoria cuando se termine de usar la funcion
int *buscar_posicion( int *clave, int siguiente_matriz){
    int *ptr=new int[2];
    int fila=clave[0], columna=clave[1];
    if (siguiente_matriz==1){
        fila+=1;
        columna+=1;
    }else if(siguiente_matriz==-1){
        fila-=1;
        columna-=1;
    }else{
        fila=fila;
        columna=columna;
    }
    ptr[0]=fila;
    ptr[1]=columna;
    return ptr;
}


void imprimir_matriz( int** matriz, int dimencion){
    for (int i = 0; i < dimencion; ++i) {
        for (int j = 0; j < dimencion; ++j) {
            cout<<matriz[i][j]<<'\t';
        }
        cout<<'\n';
    }
}

bool comparar_matrices0(int **ptr1,  int **ptr2, int *clave, int *clave2 ){
    int  fila=clave[0], fila2=clave2[0];
    fila-=1; fila2-=1;
    //cout<<fila<<" "<<fila2<<endl;
    int columna=clave[1], columna2=clave2[1];
    columna-=1; columna2-=1;
    //cout<<columna<<" "<<columna2<<endl;
    if(ptr1[fila][columna]==ptr2[fila2][columna2]){
        return true;

    }else{
        return false;
    }

}

bool comparar_matrices1(int **ptr1,  int **ptr2, int *clave, int *clave2 ){
    int  fila=clave[0], fila2=clave2[0];
    fila-=1; fila2-=1;
    //cout<<fila<<" "<<fila2<<endl;
    int columna=clave[1], columna2=clave2[1];
    columna-=1; columna2-=1;
    //cout<<columna<<" "<<columna2<<endl;
    if(ptr1[fila][columna]<ptr2[fila2][columna2]){
        return true;

    }else{
        return false;
    }

}


bool comparar_matrices_menos(int **ptr1,  int **ptr2, int *clave, int *clave2 ){
    int  fila=clave[0], fila2=clave2[0];
    fila-=1; fila2-=1;
    int columna=clave[1], columna2=clave2[1];
    columna-=1; columna2-=1;
    if(ptr1[fila][columna]>ptr2[fila2][columna2]){
        return true;

    }else{
        return false;
    }

}

void liberar_memoria(int **ptr, int n){
    for (int i = 0; i < n; ++i) {
        delete[] ptr[i];
    }
    delete[] ptr;
    ptr = nullptr;
}


int **matrices(int n, int rotar){

    if (rotar==0)
    {
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
                    // cout<<'\t'<<p[i][j];

                }else{
                    p[i][j]=contador;
                    //cout<<'\t'<<p[i][j];
                    contador++;
                }
            }
            //cout<<'\n';

        }
        //cout<<endl;
        return p;

        /*for(int i=0; i<n; i++){
        delete[]  p[i];
    }
    delete[] p;*/


    }else if (rotar==1)
    {
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

                    //cout<<'\t'<<p[i][j];
                }else{
                    p[j][i]=contador;

                    contador--;
                }
            }
            //cout<<'\n';

            if (i<temp-1)
            {
                contador=con*n;
                con++;
            }else{
                contador=(con*n)-1;
                con++;
            }

        }
        return p;


    }else if (rotar==2)
    {
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
                    //cout<<'\t'<<p[i][j];

                }else{
                    p[i][j]=contador;
                    //cout<<'\t'<<p[i][j];
                    contador--;
                }
            }
            //cout<<'\n';

        }

        return p;

    }else if (rotar==3)
    {
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
            //cout<<'\n';

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

    }else{
        return nullptr;
    }


}


int *candado(int dimencion1, int *posicion1, int *posicion2){
    int temp=0, dimencion2=dimencion1;  bool verificar, interno=false;
    while(interno==false){
        for (int i = 0; i < 4; i++)
        {
            int **anterior=matrices(dimencion1, temp);
            int **siguiente=matrices(dimencion2, i);
            bool verificar= comparar_matrices1(anterior, siguiente, posicion1, posicion2);
            imprimir_matriz(anterior, dimencion1);
            cout<<endl;
            imprimir_matriz(siguiente, dimencion2);
            cout<<endl;
            liberar_memoria(anterior, dimencion1);
            liberar_memoria(siguiente, dimencion2);
            if (verificar)
            {
                dimencion1=dimencion2;
                temp=i;
                interno=true;
                break;
            }

        }

        if(interno==false){
            posicion2=buscar_posicion(posicion2, 1);
            //dimencion2=saber_dimencion_matriz(posicion2);
            dimencion2+=2;
        }
    }
    int *pr=new int[4];
    pr[0]=dimencion2; pr[1]=temp; pr[2]=posicion2[0]; pr[3]=posicion2[1];
    return pr;
}
