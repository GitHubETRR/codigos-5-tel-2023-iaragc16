#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>
#define PI (3.1416)
/* CONSIGNA:  Escribir un programa que calcule el módulo de un número complejo y su ángulo (fase) 
ingresando su parte real y su parte imaginaria. */

void bienvenida ();
float ingresar_real();
float ingresar_imaginaria();
float calculo_modulo(float,float);
float calculo_fase(float,float);
void resultados(float,float);

int main(){
    float real, imaginaria, modulo, fase;

    bienvenida();
    real = ingresar_real();
    imaginaria = ingresar_imaginaria();
    modulo = calculo_modulo(real,imaginaria);
    fase = calculo_fase(real,imaginaria);
    resultados(modulo,fase);    
}

void bienvenida (void){
    printf ("Bienvenido al programa. Con este programa podes pasar un numero complejo de su forma binomica a polar\n");
}

float ingresar_real (void){
    float real;
    printf ("Ingresa la parte real de tu numero complejo\n");
    scanf("%f", &real);
    return (real);
}

float ingresar_imaginaria (void){
    float imaginaria;
    printf ("Ingresa la parte imaginaria de tu numero complejo\n");
    scanf("%f", &imaginaria);
    return (imaginaria);    
}

float calculo_modulo (float real, float imaginaria){
    float modulo;
    modulo = sqrt(pow(real,2) + pow(imaginaria,2));
    return (modulo);
}

float calculo_fase (float real, float imaginaria){
    float fase;
    fase = atan2(imaginaria, real) * (180/PI);
    return (fase);
}

void resultados (float modulo, float fase){
    printf("El modulo del numero es modulo %f.\n El angulo del numero es %f. \n El numero final es |%f|*e^j %f", modulo, fase, modulo, fase);
}
