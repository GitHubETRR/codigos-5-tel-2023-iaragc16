#include <stdio.h>
#include <stdint.h>
#include <math.h>
#define PI 3.14159265

/*CONSIGNA: Escribir un programa que ingresada una tensión y una corriente (con su modulo y 
ángulo) y la frecuencia de trabajo, informe el valor de la impedancia (parte real y parte 
imaginaria, y luego el valor de los componentes asociados, resistor y capacitor o 
inductor según corresponda. Para este programa deberá utilizar lo realizado en el punto 
anterior como subprograma.*/

void bienvenida();
float ingresar_tension_modulo();
float ingresar_tension_angulo();
float ingresar_corriente_modulo();
float ingresar_corriente_angulo();
float ingresar_frecuencia();
float calcular_impedancia_modulo(float, float);
float calcular_impedancia_angulo(float, float);
float calcular_impedancia_real(float, float);
float calcular_impedancia_imaginario(float, float);
void mostrar_impedancia(float, float);
void respuesta_solo_resistiva(float);
void respuesta_inductor_resistencia(float, float, float);
void respuesta_capacitor_resistencia(float, float, float);


int main(){
    bienvenida();
    float vol = ingresar_tension_modulo();
    float volang = ingresar_tension_angulo();
    float amp = ingresar_corriente_modulo();
    float ampang = ingresar_corriente_angulo();
    float frec = ingresar_frecuencia();
    float impmod = calcular_impedancia_modulo(vol,amp);
    float impang = calcular_impedancia_angulo(volang, ampang);
    float real = calcular_impedancia_real(impmod, impang);
    float imag = calcular_impedancia_imaginario(impmod, impang);
    mostrar_impedancia(real, imag);
    if(frec == 0 ){
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
    printf("\nBienvenido, este programa te permitira calcular la impedancia de un circuito segun los valores de su tension y corriente de forma polar");
}

float ingresar_tension_modulo(){
    float vol;
    printf("\nIngrese el valor del modulo de la tension en volts: ");
    scanf("%f", &vol);
    vol = vol*sqrt(2);
    return (vol);
}

float ingresar_tension_angulo(){
    float volang;
    printf("\nIngrese el valor del angulo de la tension en volts: ");
    scanf("%f", &volang);
    return (volang);
}

float ingresar_corriente_modulo(){
    float amp;
    printf("\nIngrese el valor del modulo de la corriente en amperes: ");
    scanf("%f", &amp);
    amp = amp*sqrt(2);
    return (amp);    
}

float ingresar_corriente_angulo(){
    float ampang;
    printf("\nIngrese el valor del angulo de la corriente en amperes: ");
    scanf("%f", &ampang);
    return (ampang);
}

float ingresar_frecuencia(){
    float frec;
    printf("\nIndique el valor de la frecuencia de trabajo (Hz): ");
    scanf("%f", &frec);
    return (frec);
}

float calcular_impedancia_modulo(float vol, float amp){
    float impmod;
    impmod = vol/amp;
    return (impmod);
}

float calcular_impedancia_angulo(float volang, float ampang){
    float impang;
    impang = volang - ampang;
    return (impang); 
}

float calcular_impedancia_real(float impmod, float impang){
    float real;
    real = impmod*cos(impang*(PI/180));
    return (real);
}

float calcular_impedancia_imaginario(float impmod, float impang){
    float imag;
    imag = impmod*sin(impang*(PI/180));
    return (imag);
}

void mostrar_impedancia(float real, float imag){
    printf("\nEl valor real de la impedancia es de %f ohms. Su valor imaginario es de %f ohms", real, imag);
}

void respuesta_solo_resistiva(float real){
    printf("\nLa impedancia solo tiene característica resistiva. La resistencia es de %f ohms", real);
}

void respuesta_inductor_resistencia(float real, float imag, float frec){
    float ind = imag/(2*PI*frec);
    printf("\nEl circuito tiene una inductancia de %fH y una resistencia de %f ohms", ind, real);
}

void respuesta_capacitor_resistencia(float real, float imag, float frec){
    float cap = -1/(imag*2*PI*frec);
    printf("\nEl circuito tiene una capacitancia de %ff y una resistencia de %f ohms", cap, real);
}