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
void imprimir_matriz(int** p, int n){
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
bool es_en_anillo_exterior(int dimencion, int *posicion) {
    int fila = posicion[0];
    int columna = posicion[1];
    if (fila == 0 || fila == dimencion - 1 || columna == 0 || columna == dimencion - 1) {
        return true;
    }
    return false;
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
            verificar= comparar_matrices1(anterior, siguiente, posicion1, posicion2);
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
int *candado_igual(int dimencion1, int *posicion1, int *posicion2){
    int temp=0, dimencion2=dimencion1;  bool verificar, interno=false;
    while(interno==false){
        for (int i = 0; i < 4; i++)
        {
            int **anterior=matrices(dimencion1, temp);
            int **siguiente=matrices(dimencion2, i);
            verificar= comparar_matrices0(anterior, siguiente, posicion1, posicion2);
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
    }
    int *pr=new int[4];
    pr[0]=dimencion2; pr[1]=temp; pr[2]=posicion2[0]; pr[3]=posicion2[1];
    return pr;
}
int *candado_menor(int dimencion1, int *posicion1, int *posicion2){
    int temp=0, dimencion2=dimencion1;  bool verificar, interno=false;
    while(interno==false){
        for (int i = 0; i < 4; i++)
        {
            int **anterior=matrices(dimencion1, temp);
            int **siguiente=matrices(dimencion2, i);
            verificar= comparar_matrices_menos(anterior, siguiente, posicion1, posicion2);
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
            else if (es_en_anillo_exterior(dimencion1, posicion2) && i == 3) {
                cout << "No es posible crear una matriz con un valor menor a " << anterior[posicion2[0]][posicion2[1]] << " en la posicion (" << posicion2[0] << ", " << posicion2[1] << ")." << endl;
                return nullptr;
            }
        }
        if(interno==false){
            posicion2=buscar_posicion(posicion2, -1);
            dimencion2=2;
        }
    }
    int *pr=new int[4];
    pr[0]=dimencion2; pr[1]=temp; pr[2]=posicion2[0]; pr[3]=posicion2[1];
    return pr;
}
/*int main()
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
}*/
int main(){
    int n,k, con=1, valor1=0, valor2=0;
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
    int dimencion=definirtamano(clave);
    int clave2[2], temp[2];
    clave2[0]=clave[0]-1; clave2[1]=clave[1]-1; temp[0]=clave[0]-1; temp[1]=clave[1]-1;
    int *x=new int[n-1];
    x[0]=dimencion;
    int *rotaciones=new int[n-1];
    rotaciones[0]=0;
    for (int i =2 ; i <n ; ++i) {
        if(clave[i]==1){
            int *pr= candado(dimencion, clave2, temp);
            x[con]=pr[0];
            rotaciones[con]=pr[1];
            clave2[0]=pr[2];
            clave2[1]=pr[3];
            temp[0]=clave2[0]; temp[1]=clave2[1];
            dimencion=x[con];
            con++;
        } else if(clave[i]==-1){
            int *pr= candado_menor(dimencion, clave2, temp);
            x[con]=pr[0];
            rotaciones[con]=pr[1];
            clave2[0]=pr[2];
            clave2[1]=pr[3];
            temp[0]=clave2[0]; temp[1]=clave2[1];
            dimencion=x[con];
            con++;
        }else if (clave[i]==0)
        {
            int *pr= candado_igual(dimencion, clave2, temp);
            x[con]=pr[0];
            rotaciones[con]=pr[1];
            clave2[0]=pr[2];
            clave2[1]=pr[3];
            temp[0]=clave2[0]; temp[1]=clave2[1];
            dimencion=x[con];
            con++;
        }
        cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<" "<<x[3]<<" "<<endl;
        cout<<rotaciones[0]<<" "<<rotaciones[1]<<" "<<rotaciones[2]<<" "<<rotaciones[3]<<" "<<endl;
    }
    delete[] clave;
    return 0;
}
