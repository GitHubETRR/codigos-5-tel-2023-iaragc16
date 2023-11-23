/*ESTRUCTURAS AVANZADAS DE DATOS
Almacenar variables de la misma categoria -> usamos un vector*/
#include <stdio.h>
#define CANT_MAX 10

void imprime_temps(int[]);
void ingreso_temps(int[]);
int calcula_prom(int[]);
void ordena_temps(int[]);


int main (void){
//  int temp1, temp2, temp3, temp4; es lo mismo que ...
/*  int temp[10]; comienza a contar desde el 0 y llega al 9. 
Ese '10' puede ser una variable, puedo escribir un numero o un simbolo que varie a lo largo del codigo.*/
    int temp[CANT_MAX]; /* tambien podria seleccionar yo el valor de cada variable asi 
    (siendo 1,2,3,4 y 5 valores para mis temperaturas): 
    int temp [CANT_MAX]={1,2,3,4,5}; y borrando la funcion de ingreso_temp*/
    int temp_prom;
    ingreso_temps(temp);
    ordena_temps(temp);
    temp_prom = calcula_prom(temp);
    imprime_temps(temp);
    printf("El promedio de las temperaturas fue de: %d\n", temp_prom);
    return 0; 
}

void ingreso_temps(int temp[]){
    for(int i=0;i<CANT_MAX;i++){
            printf("Ingresa la temperatura %d: ",i+1);
            scanf("%d",&temp[i]);
    }
}

void ordena_temps(int temp[]){
   for(int i=1; i<CANT_MAX; i++){
      for(int j=0; j<(CANT_MAX-1); j++){
        if(temp[j] > temp[j+1]){
            int caja = temp[j];
            temp[j] = temp[j+1];
            temp[j+1] = caja;
        }
      }
   }
}

void imprime_temps(int temp[]){
    for(int i=0;i<CANT_MAX;i++){
            printf("La temperatura %d fue de: %d \n",i+1,temp[i]);
    }
    printf("La temperatura minima fue de: %d \n", temp[0]);
    printf("La temperatura maxima fue de: %d \n", temp[9]);
}

int calcula_prom(int temp[]){
    int prom=0;
    for(int i=0;i<CANT_MAX;i++){
      //  prom=prom+temp[i];
        prom+=temp[i];
    }
    prom/=CANT_MAX;
    return prom;

}