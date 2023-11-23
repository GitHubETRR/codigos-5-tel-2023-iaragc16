#include <stdio.h>
#include <stdint.h>

int main(){
   uint32_t dia;
   uint32_t mes;
   uint32_t anio;
   printf("Introduzca dia: ");
   scanf("%d", &dia);
   printf("\nIntroduzca mes: ");
   scanf("%d", &mes);
   printf("\nIntroduzca anio: ");
   scanf("%d", &anio);
   printf("\n");
   if(mes<=12 && mes>=1){
      if(mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12){
         if(dia>=1 && dia<=31){
            printf("FECHA CORRECTA");
         }else{
            printf("FECHA INCORRECTAa");
         }
      }
      if(mes==4 || mes==6 || mes==9 || mes==11){
         if(dia>=1 && dia<=30){
            printf("FECHA CORRECTA");
         }else{
            printf("FECHA INCORRECTAb");
         }
      }
      if(mes==2){
         if(anio%4==0){
            if(dia>=1 && dia<=29){
               printf("FECHA CORRECTA");
            }else {
               printf("FECHA INCORRECTAc");
            }
         }else{
            if(dia>=1 && dia<=28){
               printf("FECHA CORRECTA");
            }else {
               printf("FECHA INCORRECTAd");
            }
         }
      }
   }else{
      printf("FECHA INCORRECTAe");
   }
}