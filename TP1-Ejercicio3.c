#include <stdio.h>
#include <stdint.h>
#include <math.h>
#define PI 3.1416

/* CONSIGNA: Escribir un programa que sume dos números complejos en formato rectangular y 
pregunte al final como desea ver el resultado si en polar o rectangular y lo muestre en 
el formato que el usuario quiera. */

void bienvenida();
float ingresar_real();
float ingresar_imaginario();
float suma(float,float);
uint8_t elegir_resultado();
void resultado_binomica(float,float);
float calcular_modulo(float,float);
float calcular_angulo(float,float);
void resultado_polar(float,float);


int main(){
    bienvenida();
    printf("Ingresa los valores del primer numero\n");
    float real1 = ingresar_real();
    float imaginario1= ingresar_imaginario();
    printf("\nIngresa los valores del segundo numero\n");
    float real2 = ingresar_real();
    float imaginario2 = ingresar_imaginario();
    float real = suma(real1, real2);
    float imaginario = suma(imaginario1, imaginario2);
    uint8_t resultado = elegir_resultado();
    if (resultado == 2){
        resultado_binomica(real, imaginario);
    }else{
        float modulo = calcular_modulo(real, imaginario);
        float angulo = calcular_angulo(real, imaginario);
        resultado_polar(modulo, angulo);
    }
}

void bienvenida(){
    printf("Bienvenido al programa. Con este programa podes sumar dos numeros complejos en su forma binomica y obtener el resultado de forma binomica o polar\n");
}

float ingresar_real(){
    printf("Ingresa la parte real del numero ");
    float real;
    scanf("%f", &real);
    return (real);
}

float ingresar_imaginario(){
    printf("Ingresa la parte imaginaria del numero ");
    float imaginario;
    scanf("%f", &imaginario);
    return (imaginario);
}

float suma(float num1, float num2){
    float resultado;
    resultado = num1 + num2;
    return (resultado);
}

uint8_t elegir_resultado(){
    uint8_t resultado;
    printf("\nDecidi si queres el resultado de la suma en formato binomico o polar. Para obtener el resultado en polar ingresa 1 y para obtenerlo en binomica ingresa 2 ");
    scanf("%d", &resultado);
    if (!(resultado == 1 || resultado == 2)){
       do{
         printf("\nEl valor ingresado no es 1 ni 2. Escribi 1 si queres ver el resultado en su forma polar o 2 si queres ver el resultado en su forma binomica ");
         scanf("%d", &resultado);
    }while(!(resultado == 1 || resultado == 2));
}
    return (resultado);
}

void resultado_binomica(float real, float imaginario){
    printf("\nEl resultado aparecera en su forma binomica. \n La parte real del complejo resultante es %f, la parte imaginaria es %f\n Obtenemos el numero %f + j*%f \n", real, imaginario, real, imaginario);
}

float calcular_modulo(float real,float imaginario){
    float modulo;
    modulo = sqrt(pow(real, 2)+ pow(imaginario, 2));
    return (modulo); 
}

float calcular_angulo(float real, float imaginario){  
    float angulo;
    angulo = atan2(imaginario, real) * (180/PI);
    return (angulo);
}

void resultado_polar(float modulo, float angulo){
    printf("\nEl resultado aparecera en su forma polar \nEl modulo del complejo resultante es %f el angulo del complejo resultante es %f \nObtenemos el numero |%f|*e^j%f", modulo, angulo, modulo, angulo);
}

