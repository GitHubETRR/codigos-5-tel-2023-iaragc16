#include <stdio.h>
#include <stdint.h>

int main(){
   int num;
   uint8_t again;
   do{
      printf("Escribe un numero para saber los valores de su tabla de multiplicar del 0 al 10\n");
      scanf("%d", &num); //%d porque es un entero, num es mi variable
      printf("\n");      //\n saltea un renglon, propósitos estéticos
      for(uint8_t i = 0; i < 11; i++){ //defino i en la inicializacion del for
         printf("%d x %d = %d\n", num, i, i * num);
      }
      printf("Si quieres otra tabla de multiplicar ingresa un 1, si quieres finalizar ingresa cualquier otro valor\n");
      scanf("%d", &again);
   }while (again == 1);
}
