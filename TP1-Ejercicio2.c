#include <stdio.h>
#include <stdint.h>
#include <math.h>
#define PI (3.1416)

/*CONSIGNA:  Escribir un programa que devuelva el número complejo en formato rectangular (su 
parte real + j su parte imaginaria), ingresando su módulo y ángulo (fase). */

void bienvenida();
float ingresar_modulo();
float ingresar_angulo();
float calculo_real(float,float);
float calculo_imaginario (float,float);
void resultados(float,float);

int main(){
    float modulo, angulo, real, imaginario;

    bienvenida();
    modulo = ingresar_modulo();
    angulo = ingresar_angulo();
    real = calculo_real(modulo, angulo);
    imaginario = calculo_imaginario(modulo, angulo);
    resultados(real, imaginario);
}

void bienvenida (void){
    printf("Bienvenido al programa. Con este programa podes pasar un numero complejo de su forma polar a binomica\n");
}

float ingresar_modulo (void){
    float modulo;
    printf("Ingresa el modulo de tu numero complejo\n");
    scanf("%f", &modulo);
    return (modulo);
}

float ingresar_angulo (void){
    float angulo;
    printf("Ingresa el angulo de tu numero complejo (en grados) \n");
    scanf("%f", &angulo);
    return (angulo);
}

float calculo_real (float modulo, float angulo){
    float real;
    real = modulo*cos(angulo*(PI/180));
    return (real);
}

float calculo_imaginario (float modulo, float angulo){
    float imaginario;
    imaginario = modulo*sin(angulo*(PI/180));
    return (imaginario);
}

void resultados (float real, float imaginario){
    printf ("La parte real del numero complejo es %f \n La parte imaginaria del numero complejo es %f \n El numero final es %f + j*%f", real, imaginario, real, imaginario);
}
