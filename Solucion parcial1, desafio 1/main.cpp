#include <iostream>
using namespace std;


int saber_dimension_matriz( int *clave);
int *buscar_posicion( int *clave, int siguiente_matriz);
void imprimir_matriz( int** matriz, int dimension);
bool comparar_matrices0(int **ptr1,  int **ptr2, int *clave, int *clave2 );
bool comparar_matrices1(int **ptr1,  int **ptr2, int *clave, int *clave2 );
bool comparar_matrices_menos(int **ptr1,  int **ptr2, int *clave, int *clave2 );
void liberar_memoria(int **ptr, int n);
int **matrices(int n, int rotar);
int *candado(int dimension1, int *posicion1, int *posicion2, int &temp);
int *candado_menor(int dimension1, int *posicion1, int *posicion2, int &temp);
int *candado_igual(int dimension1, int *posicion1, int *posicion2, int &temp);
bool es_en_anillo_exterior(int dimension, int *posicion);




int main(){
    int n,k, con=1,temp1=0 ;
    //int* ptr1 = nullptr;
    cout << "Ingrese el tamano de la clave k: " <<endl;
    cin>> n;
    int* clave = new int[n];
    //bool verificar=false;
    for(int i=0;i<n;++i){
        if(i<2){
            cout <<"Ingrese el digito en la pos "<< i+1<< ": ";
            cin>>k;
            clave[i] = k;
        }
        else{
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
    int dimension=saber_dimension_matriz(clave);
    int clave2[2], temp[2];
    clave2[0]=clave[0]-1; clave2[1]=clave[1]-1; temp[0]=clave[0]-1; temp[1]=clave[1]-1;
    int *x=new int[n-1];
    x[0]=dimension;
    int *rotaciones=new int[n-1];
    rotaciones[0]=0;
    for (int i =2 ; i <n ; ++i) {
        if(clave[i]==1){
            int *pr= candado(dimension, clave2, temp, temp1 );
            x[con]=pr[0];
            rotaciones[con]=pr[1];
            clave2[0]=pr[2];
            clave2[1]=pr[3];
            temp[0]=clave2[0]; temp[1]=clave2[1];
            dimension=x[con];
            con++;
            delete[] pr;
        } else if(clave[i]==-1){
            int *pr= candado_menor(dimension, clave2, temp, temp1);
            if (pr==nullptr)
            {
                break;
            }else{
                x[con]=pr[0];
                rotaciones[con]=pr[1];
                clave2[0]=pr[2];
                clave2[1]=pr[3];
                temp[0]=clave2[0]; temp[1]=clave2[1];
                dimension=x[con];
                con++;
                delete[] pr;
            }
        }else if (clave[i]==0)
        {
            int *pr= candado_igual(dimension, clave2, temp, temp1);
            x[con]=pr[0];
            rotaciones[con]=pr[1];
            clave2[0]=pr[2];
            clave2[1]=pr[3];
            temp[0]=clave2[0]; temp[1]=clave2[1];
            dimension=x[con];
            con++;
            delete[] pr;
        }

    }

    cout<<"La cerradura correspondiente que satisface la regla k con sus debidos tamanos: "<< endl;
    cout<<"X(";
    for (int i = 0; i < n-1; i++)
    {
        cout<<x[i]<<", ";
    }
    cout<<")";
    cout<<endl;
    cout<<"Y las debidas rotaciones de cada posicion son: "<<endl;
    cout<<" (";
    for (int i = 0; i < n-1; i++)
    {
        cout<<rotaciones[i]<<" ";
    }
    cout<<")";
    cout<<endl;

    delete[] clave;
    delete[] rotaciones;
    delete[] x;

    return 0;
}




int saber_dimension_matriz( int *clave){
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


void imprimir_matriz( int** matriz, int dimension){
    for (int i = 0; i < dimension; ++i) {
        for (int j = 0; j < dimension; ++j) {
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
    //fila-=1; fila2-=1;
    //cout<<fila<<" "<<fila2<<endl;
    int columna=clave[1], columna2=clave2[1];
    //columna-=1; columna2-=1;
    //cout<<ptr1[fila][columna]<<" < "<<ptr2[fila2][columna2]<<endl;
    if(ptr1[fila][columna]<ptr2[fila2][columna2]){
        return true;

    }else{
        return false;
    }

}


bool comparar_matrices_menos(int **ptr1,  int **ptr2, int *clave, int *clave2 ){
    int  fila=clave[0], fila2=clave2[0];
    //fila-=1; fila2-=1;
    int columna=clave[1], columna2=clave2[1];
    //columna-=1; columna2-=1;
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


bool es_en_anillo_exterior(int dimension, int *posicion) {
    int fila = posicion[0];
    int columna = posicion[1];
    if (fila == 0 || fila == dimension - 1 || columna == 0 || columna == dimension - 1) {
        return true;
    }
    return false;
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


int *candado(int dimension1, int *posicion1, int *posicion2, int &temp){
    int dimension2=dimension1;  bool verificar, interno=false;
    while(interno==false){
        for (int i = 0; i < 4; i++)
        {
            int **anterior=matrices(dimension1, temp);
            int **siguiente=matrices(dimension2, i);
            verificar= comparar_matrices1(anterior, siguiente, posicion1, posicion2);
            imprimir_matriz(anterior, dimension1);
            cout<<endl;
            imprimir_matriz(siguiente, dimension2);
            cout<<endl;
            liberar_memoria(anterior, dimension1);
            liberar_memoria(siguiente, dimension2);
            if (verificar)
            {
                dimension1=dimension2;
                temp=i;
                interno=true;
                break;
            }

        }

        if(interno==false){
            posicion2=buscar_posicion(posicion2, 1);

            dimension2+=2;
        }
    }
    int *pr=new int[4];
    pr[0]=dimension2; pr[1]=temp; pr[2]=posicion2[0]; pr[3]=posicion2[1];
    return pr;
}



int *candado_igual(int dimension1, int *posicion1, int *posicion2,int &temp ){
    int dimension2=dimension1;  bool verificar, interno=false;
    while(interno==false){
        for (int i = 0; i < 4; i++)
        {
            int **anterior=matrices(dimension1, temp);
            int **siguiente=matrices(dimension2, i);
            verificar= comparar_matrices0(anterior, siguiente, posicion1, posicion2);
            imprimir_matriz(anterior, dimension1);
            cout<<endl;
            imprimir_matriz(siguiente, dimension2);
            cout<<endl;
            liberar_memoria(anterior, dimension1);
            liberar_memoria(siguiente, dimension2);
            if (verificar)
            {
                dimension1=dimension2;
                temp=i;
                interno=true;
                break;
            }
        }
    }
    int *pr=new int[4];
    pr[0]=dimension2; pr[1]=temp; pr[2]=posicion2[0]; pr[3]=posicion2[1];
    return pr;
}


int *candado_menor(int dimension1, int *posicion1, int *posicion2, int &temp){
    int  dimension2=dimension1;  bool verificar, interno=false;
    while(interno==false){
        for (int i = 0; i < 4; i++)
        {
            int **anterior=matrices(dimension1, temp);
            int **siguiente=matrices(dimension2, i);
            verificar= comparar_matrices_menos(anterior, siguiente, posicion1, posicion2);
            imprimir_matriz(anterior, dimension1);
            cout<<endl;
            imprimir_matriz(siguiente, dimension2);
            cout<<endl;
            liberar_memoria(anterior, dimension1);
            liberar_memoria(siguiente, dimension2);
            if (verificar)
            {
                dimension1=dimension2;
                temp=i;
                interno=true;
                break;
            }
            else if (es_en_anillo_exterior(dimension1, posicion2) && i == 3) {
                cout << "No es posible crear una matriz con un valor menor "<< endl;
                return nullptr;
            }
        }
        if(interno==false){
            posicion2=buscar_posicion(posicion2, -1);
            dimension2=2;
        }
    }
    int *pr=new int[4];
    pr[0]=dimension2; pr[1]=temp; pr[2]=posicion2[0]; pr[3]=posicion2[1];
    return pr;
}
