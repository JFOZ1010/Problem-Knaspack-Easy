#include <iostream>
using namespace std; 

int main(){
    int w[] = {6,4,9};
    int b[] = {5,8,10};

    int n = 3; //numero de objetos.
    int m = 10; //cantidad de filas y peso maximo aceptado. 

    int BMAX[m+1][n]; 

    //columnas, representa el elemento, desde 0-1. 
    for(int j=0; j<n; j++){

        //desde cero hasta capacidad m.
        for(int i=0; i<=m; i++){

            int pesoElementoJ = w[j]; 
            int gananciaElementoJ = b[j]; 

            /*
            BMAX[i, 1] = b[j] if i >= pesoJ
                       = 0 en otro caso. 


            BMAX[i,j] = max(Bmax[i,j-1], 
                            Bmax[i-w[j], j-1]+b[j])
            */

           if(j == 0){
            
            //si el peso es mayor que la capacidad de la mochila. 
            if(i < w[j]){
                BMAX[i][j] = 0;  
            }
            else {
                BMAX[i][j] = b[j]; 
            }

           }
           else {

            //i es el peso de la capacidad mochila. 
            // w[j] peso objetos. 
            // j-1 es la fila de arriba, osea el sucesor. 
            // b[j] es el beneficio de los objs. 
            int max = 0; 
            int noLlevar = BMAX[i][j-1]; 
            int llevar = 0; 
            if(i-w[j] >= 0){
                llevar = BMAX[i-w[j]][j-1]+b[j];
            }

            if(noLlevar>llevar){
                BMAX[i][j] = noLlevar; 
            }
            else{

                BMAX[i][j] = llevar; //j-1 , i - w[j]

            }

           }

        }

    }

        //columnas, representa el elemento, desde 0-1. 
    for(int i=0; i<=m; i++){

        //desde cero hasta capacidad m.
        for(int j=0; j<n; j++){
            cout<<BMAX[i][j] << " , "; 
        }
        cout<< endl; 
    }

    bool X[n]; 
    int j = n-1; 
    int i = m; 

    while(true){

        int llevar = 0; 
        //si el peso menos el peso del objeto es mayor o igual a cero. 
        if(i-w[j] >= 0){
            llevar = BMAX[i-w[j]][j-1] + b[j]; 
            
        }
        int noLlevar = BMAX[i][j-1]; 
        
        if(llevar > noLlevar){
            i = i-w[j]; 
            X[j] = 1; //si se lleva es 1. 
        } 
        else {
            X[j] = 0; //si no se lleva es 0. 
        }
        j = j-1;


        if(j<0) 
        
        break; 
    }

    for(int i=0; i<n; i++){ 
        cout << X[i] << " , ";
    }
}