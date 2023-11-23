#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#define PI (3.14)

/* 
CONSIGNA: Escribir un programa que calcule el modulo de un numero
complejo y su angulo (fase) ingresando du parte real y su parte imaginaria
*/
void bienvenida(); /* prototipo de la funcion, es necesario cuando defino la funcion mas tarde que 
cuando la llamo. Escribo void ya que no necesito que la funcion devuelva ningun valor*/
float ingreso_parte_real(); /* porque me devuelve un float*/
float ingreso_parte_imaginar();
float modulo (float,float);
float fase (float,float); 
void mostrar_resultados(float,float); /* void porque no devuelve nada; 
float,float porque usa info de dos variables que son float*/

int main(){  // es la funcion principal, siempre debe estar en un codigo en c
    float real, img, mod, fas;

    bienvenida();
    real = ingreso_parte_real();
    img = ingreso_parte_imaginar();
    mod = modulo(real, img);
    fas = fase (real, img);
    mostrar_resultados(mod, fas);
    return 0;
}

void bienvenida (void){
    printf("bienvenidos al programa que ...\n");
}

float ingreso_parte_real(void){
    float real;
    printf("por favor rodri quiere ingresar la parte real\n");
    scanf("%f", &real);
    return (real);
}

float ingreso_parte_imaginar(void){
    float img;
    printf("por favor rodri quiere ingresar la parte imaginaria\n");
    scanf("%f", &img);
    return (img);    
}

float modulo(float real, float img){
    float mod;
    mod = sqrt(pow(real,2)+(img*img));
    return (mod);
}

float fase (float real, float img){
    float fas;
    fas = atan2(img,real);
    fas = fas*180/PI;
    return (fas);
}

void mostrar_resultados(float mod, float fas){
    printf("el modulo dio = %f \n", mod);
    printf("la fase dio %f \n", fas);
}