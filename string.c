#include <stdio.h>
#define CANT_MAX 5
// #include <string.h> -> Te permite usar strcpy o strcmp o strncmp

/*
int main (void){
    char txt1[]="Hola";
    char txt2[5];
    int i=0;
    strcpy(txt2,txt1);
    while(txt2[i])printf("%c",txt2[i++]);    
    return 0;
}
*/

/*int main(void){
    char txt[]={'H','o','l','a'};

    for (int i=0; i<4, i++){
        printf("%c", txt[i]);
    }
    return 0;
}*/

int main(void){
    char txt[]={'H','o','l','a',0}; /*string -> vector del tipo char con caracteres ascci que tenmina en null (osea '/0'). 
    El %s sirve para imprimir un string. 
    En vez de separar cada caracter por comillas simples, 
    se pueden escribir todos los caracteres juntos con dobles comillas 
    y automaticamente me lo toma como un string. 
    Ej: char txt[]={'h','o','l','a', 0} es lo mismo que char txt[]="hola".
*/
    for (int i=0; txt[i]!=0; i++){
        printf("%c", txt[i]);
    }
    return 0;
}