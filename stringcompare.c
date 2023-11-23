/*CONSIGNA: 
1.Realizar una función que compare dos strings 
(de la misma longitud) 
y devuelva 0 si son iguales o 1 si son distintos */
#include <stdio.h>
#include <string.h>
#define cant 10

void ingresartextos(char[],char[]);
int comparartextos(char[],char[]);
void resultados(int);


int main (){
    char txt1[cant];
    char txt2[cant];
    ingresartextos(txt1,txt2);
    int result = comparartextos(txt1,txt2);
    resultados(result);
}

void ingresartextos(char txt1[], char txt2[]){
    printf("Ingrese el texto numero 1, recuerde que puede tener hasta 10 caracteres \n");
    gets(txt1);
    printf("Ingrese el texto numero 2, recuerde que puede tener hasta 10 caracteres \n");
    gets(txt2);        
}

int comparartextos(char txt1[], char txt2[]){
    int result=0;
    for(int i=0; txt1[i]!=0 || txt2[i]!=0; i++){
        if(txt1[i]!=txt2[i]){
            result=1;
        }
    }
    return (result);
}

void resultados(int result){
    if(result==1){
        printf("Los textos son distintos");
    }else{
        printf("Los textos son iguales");
    }
}