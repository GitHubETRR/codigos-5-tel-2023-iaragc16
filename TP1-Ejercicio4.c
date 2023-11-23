#include <stdio.h>
#include <stdint.h>
#include <math.h>
#define PI 3.1416

/* CONSIGNA: Escribir un programa que al recibir una impedancia (parte real y parte imaginaria) y la 
frecuencia de trabajo, indique el valor de la resistencia y el capacitor o inductor según 
corresponda. */

void bienvenida();
float ingresar_impedancia_real();
float ingresar_impedancia_imaginario();
float ingresar_frecuencia();
void respuesta_solo_resistiva(float);
void respuesta_inductor_resistencia(float, float, float);
void respuesta_capacitor_resistencia(float, float, float);

int main(){
    bienvenida();
    float real = ingresar_impedancia_real();
    float imag = ingresar_impedancia_imaginario();
    float frec = ingresar_frecuencia();
    if((frec) == 0 ){
        respuesta_solo_resistiva(real);
    }else{
        if(imag == 0){
            respuesta_solo_resistiva(real);
        }else{
            if(imag>0){
                respuesta_inductor_resistencia(real, imag, frec);
            }else{
                respuesta_capacitor_resistencia(real, imag, frec);
            }
        }
    }
}

void bienvenida(){
    printf("\nBienvenido al programa. Con este programa podes calcular la resistencia, capacitancia o inductancia utilizando el valor de la impedancia\n");
}

float ingresar_impedancia_real(){
    float real;
    printf("\nIndique el valor de la parte real de la impedancia (ohms): ");
    scanf("%f", &real);
    return (real);
}

float ingresar_impedancia_imaginario(){
    float imag;
    printf("\nIndique el valor de la parte imaginaria de la impedancia (ohms): ");
    scanf("%f", &imag);
    return (imag);
}

float ingresar_frecuencia(){
    float frec;
    printf("\nIndique el valor de la frecuencia de trabajo (Hz): ");
    scanf("%f", &frec);
    return (frec);
}

void respuesta_solo_resistiva(float real){
    printf("\nLa impedancia solo tiene característica resistiva. La resistencia es de %f ohms", real);
}

void respuesta_inductor_resistencia(float real, float imag, float frec){
    float ind = imag/(2*PI*frec);
    printf("\nEl circuito tiene una inductancia de %fH y una resistencia de %f ohms", ind, real);
}

void respuesta_capacitor_resistencia(float real, float imag, float frec){
    float im = imag*(-1);
    float cap = 1/(im*2*PI*frec);
    printf("\nEl circuito tiene una capacitancia de %ff y una resistencia de %f ohms", cap, real);
}
