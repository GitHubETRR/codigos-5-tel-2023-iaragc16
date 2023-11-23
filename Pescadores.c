#include <stdio.h>
#include <stdint.h>

int main(){
    float pez1=0;
    float pez2=0;
    float pez3=0;
    uint16_t cant1=0;
    uint16_t cant2=0;
    uint16_t cant3=0;
    float promedio=0;
    uint16_t canttotal;
    float promediofinal;
    uint8_t pescador;
    float p1;
    float p2;
    float p3;

    printf("Bienvenido/a al programa. Con este programa podras definir que pescador gana el concurso y cual obtuvo la pieza mas grande.\nRecuerde que los peces deben medir al menos 12 cm.\n");
    
    do{
        printf("Ingrese que pescador extrajo el pez con su numero de identificaci0n (1,2 o 3) o 0 para finalizar el concurso.\n");
        scanf("%d", &pescador);
        while(pescador!=1 && pescador!=2 && pescador!=3 && pescador!=0){
            printf("El numero ingresado no corresponde a ningun pescador, ingrese el numero de algun pescador (1,2 o 3) o 0 para finalizar\n");
            scanf("%d", &pescador);
        }
        switch (pescador){
        case 1:
            printf("¿Cual es la longitud del pez? (en cm)\n");
            scanf("%f", &p1);
            if(p1>=12){
                promedio=promedio+p1;
                if(pez1<=p1){
                    pez1=p1;
                }
                cant1++;
            }else{
                printf("La pieza mide menos de 12cm por lo que no cuenta para el concurso\n");
            }
            break;
        case 2:
            printf("¿Cual es la longitud del pez? (en cm)\n");
            scanf("%f", &p2);
             if(p2>=12){
                promedio=promedio+p2;
                if(pez2<=p2){
                    pez2=p2;
                }
                cant2++;
            }else{
                printf("La pieza mide menos de 12cm por lo que no cuenta para el concurso\n");
            }
            break;
        case 3:
            printf("¿Cual es la longitud del pez? (en cm)\n");
            scanf("%f", &p3);
             if(p3>=12){
                promedio=promedio+p3;
                if(pez3<=p3){
                    pez3=p3;
                }
                cant3++;
            }else{
                printf("La pieza mide menos de 12cm por lo que no cuenta para el concurso\n");
            }
            break;
        }
    }while(pescador!=0);

    if(cant1==cant2 && cant1==cant3){
        printf("Empataron todos los pescadores habiendo pescado %d piezas.\n", cant1);
    }else{
        if(cant1==cant2 || cant1==cant3){
            if(cant1==cant2){
                if(cant1>cant3){
                    printf("Empataron los pescadores 1 y 2 habiendo pescado %d piezas.\n", cant1);
                }else{
                    printf("Gano el pescador 3 habiendo pescado %d piezas.\n", cant3);
                }
            }else{
                if(cant1>cant2){
                    printf("Empataron los pescadores 1 y 3 habiendo pescado %d piezas.\n", cant1);
                }else{
                    printf("Gano el pescador 2 habiendo pescado %d piezas.\n", cant2);
                }
            }
        }else{
            if(cant3==cant2){
                if(cant3<cant1){
                    printf("Gano el pescador 1 habiendo pescado %d piezas.\n", cant1);
                }else{
                    printf("Empataron los pescadores 2 y 3 habiendo pescado %d piezas.\n", cant2);
                }
            }else{
                if(cant1>cant2 && cant1>cant3){
                    printf("Gano el pescador 1 habiendo pescado %d piezas.\n", cant1);
                }else{
                    if(cant2>cant1 && cant2>cant3){
                        printf("Gano el pescador 2 habiendo pescado %d piezas.\n", cant2);
                    }else{
                        printf("Gano el pescador 3 habiendo pescado %d piezas.\n", cant3);
                    }
                }
            }
        }
    }

    if(pez1==pez2 && pez1==pez3){
        printf("Todos los pescadores han pescado una pieza con la mayor longitud, esta distancia es de %fcm.\n", pez1);
    }else{
        if(pez1==pez2 || pez1==pez3){
            if(pez1==pez2){
                if(pez1>pez3){
                    printf("Los pescadores 1 y 2 han obtenido cada uno la pieza de mayor tamaño, con una longitud de %fcm.\n", pez1);
                }else{
                    printf("El pescador que obtuvo la pieza de mayor tamaño es el 3, con una longitud de %fcm.\n", pez3);
                }
            }else{
                if(pez1>pez2){
                    printf("Los pescadores 1 y 3 han obtenido cada uno la pieza de mayor tamaño, con una longitud de %fcm.\n", pez1);
                }else{
                    printf("El pescador que obtuvo la pieza de mayor longitud es el 2, con una distancia de %fcm.\n", pez2);
                }
            }
        }else{
            if(pez3==pez2){
                if(pez3<pez1){
                    printf("El pescador que obtuvo la pieza de mayor tamaño es el 1, con una longitud de %fcm.\n", pez1);
                }else{
                    printf("Los pescadores 2 y 3 han obtenido cada uno la pieza de mayor tamaño, con una longitud de %fcm.\n", pez2);
                }
            }else{
                if(pez1>pez2 && pez1>pez3){
                    printf("El pescador que obtuvo la pieza de mayor tamaño es el 1, con una longitud de %fcm.\n", pez1);
                }else{
                    if(pez2>pez1 && pez2>pez3){
                        printf("El pescador que obtuvo la pieza de mayor tamaño es el 2, con una longitud de %fcm.\n", pez2);
                    }else{
                        printf("El pescador que obtuvo la pieza de mayor tamaño es el 3, con una longitud de %fcm.\n", pez3);
                    }
                }
            }
        }
    }

    canttotal=cant1+cant2+cant3;
    printf("Se han extraido %d piezas del agua.\n", canttotal);
    if(promedio==0){
        printf("La longitud promedio de los peces extraidos es de %fcm.\n", promedio);
    }else{
        promediofinal=promedio/canttotal;
        printf("La longitud promedio de los peces extraidos es de %fcm.\n", promediofinal);
    }
}