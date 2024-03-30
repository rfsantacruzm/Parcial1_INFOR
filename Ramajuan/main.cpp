#include <iostream>

using namespace std;


int** matrizneutra(int n);
int saber_dimencion_matriz( int *clave);
int** rotarmatriz1(int n);
int** rotarmatriz2(int n);
int** rotarmatriz3(int n);
int *buscar_posicion(const int *clave, int siguiente_matriz);
void imprimir_matriz(const int** matriz, int dimencion);
bool comparar_matrices0(int **ptr1,  int **ptr2, int *clave, int *clave2 );
bool comparar_matrices1(int **ptr1,  int **ptr2, int *clave, int *clave2 );
bool comparar_matrices_menos(int **ptr1,  int **ptr2, int *clave, int *clave2 );
void liberar_memoria(int **ptr, int n);
int **matrices(int n, int rotar);

int main(){
    int n,k, con=0, valor1=0, valor2=0;
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
    int clave2[2];
    clave2[0]=clave[0]; clave2[1]=clave[1];
    //liberar memoria de clave
    for (int i =1 ; i <n ; ++i) {
        //cout<<clave[i]<<endl;
        con++;
        if(clave[con]==1){

                int** anterior= matrices(dimencion, valor1);
                int** siguiente=matrices(dimencion2, valor2);
                int clave_temp[2]; clave_temp[0]=clave2[0]; clave_temp[1]=clave2[1];
                bool duda=comparar_matrices1(anterior, siguiente, clave2, clave_temp );
                liberar_memoria(anterior, dimencion);
                liberar_memoria(siguiente, dimencion);
                if(duda){
                cout<<endl<<"Es mayor"<<endl;
                //verificar=true;
                }else{

                    while (verificar==false) {
                        for (int i = 0; i < 4; ++i) {
                            for (int j = 0; j < 4; ++j) {
                                int **anterior=matrices(dimencion, valor1);
                            }
                        }
                    }
                }

        }/*else if(i==0){

        }else if(i==-1){

        }*/
    }

    delete[] clave;
    return 0;
}



//recordar liberar memoria cuando se termine de usar la funcion
int** matrizneutra(int n){
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
                //cout<<'\t'<<p[i][j];

            }else{
                p[i][j]=contador;
                //cout<<'\t'<<p[i][j];
                contador++;
            }
        }
        //cout<<'\n';

    }
    return p;

    /*for(int i=0; i<n; i++){
        delete[]  p[i];
    }
    delete[] p;*/

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
    }
}

//recordar liberar la memoria cuando se termine de usar la funcion
int** rotarmatriz1(int n){
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
    return p;
}

//recordar liberar la memoria cuando se termine de usar la funcion
int** rotarmatriz2(int n){
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


}

//recordar liberar la memoria cuando se termine de usar la funcion
int** rotarmatriz3(int n){
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
    return p;
}

//recordar liberar la memoria cuando se termine de usar la funcion
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


void imprimir_matriz(const int** matriz, int dimencion){
    for (int i = 0; i < dimencion; ++i) {
        for (int j = 0; j < dimencion; ++j) {
            cout<<matriz[i][j]<<'\t';
        }
        cout<<'\n';
    }
}

bool comparar_matrices0(int **ptr1,  int **ptr2, int *clave, int *clave2 ){
   int  fila=clave[0], fila2=clave2[0];
   int columna=clave[1], columna2=clave2[1];
   if(ptr1[fila][columna]==ptr2[fila2][columna2]){
       return true;

   }else{
       return false;
   }

}

bool comparar_matrices1(int **ptr1,  int **ptr2, int *clave, int *clave2 ){
    int  fila=clave[0], fila2=clave2[0];
    int columna=clave[1], columna2=clave2[1];
    if(ptr1[fila][columna]<ptr2[fila2][columna2]){
        return true;

    }else{
        return false;
    }

}


bool comparar_matrices_menos(int **ptr1,  int **ptr2, int *clave, int *clave2 ){
    int  fila=clave[0], fila2=clave2[0];
    int columna=clave[1], columna2=clave2[1];
    if(ptr1[fila][columna]>ptr2[fila2][columna2]){
        return true;

    }else{
        return false;
    }

}

void liberar_memoria(int **ptr, int n){
    for (int i = 0; i < n; ++i) {
        delete ptr[i];
    }
    delete[] ptr;
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
                    //cout<<'\t'<<p[i][j];

                }else{
                    p[i][j]=contador;
                    //cout<<'\t'<<p[i][j];
                    contador++;
                }
            }
            //cout<<'\n';

        }
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
        return p;

    }




}



