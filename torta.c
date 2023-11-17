#include <stdio.h>
#include <windows.h>

/* Ingredientes (gr) */

#define PITUFI_OREO 260
#define PITUFI_MANTECA 90
#define PITUFI_QUESO 600
#define PITUFI_NATA 330
#define PITUFI_AZUCAR 220
#define PITUFI_OREO_CREMA 180
#define PITUFI_VAINILLA 26

/* Materiales (cant.) */

#define PITUFI_CUCHARA 1
#define PITUFI_BATIDOR 1
#define PITUFI_BOUL 1
#define PITUFI_MOLDE 1
#define PITUFI_BOLSA 1

/* Tiempos */

#define PITUFI_MICRO_TIEMPO 30
#define PITUFI_HELADERA_TIEMPO 30
#define PITUFI_MS 1000
//#define PITUFI_MN 60000 es el tiempo real pero es demasiado largo para testear el código
#define PITUFI_MN 1
#define PITUFI_DELAY 2

void pitufi_paso_final();


void pitufi_tiempo(){
    Sleep(PITUFI_DELAY*PITUFI_MS);
}


int pitufi_maximo_comun_divisor(int a, int b) { /* Se encarga de buscar el divisor común mayor */
    int temporal; /* Variable para almacenar el valor de b antes de que cambie  */
    while (b != 0) {
        temporal = b; /* Almacena el valor de b */
        b = a % b; /* Divide y comprueba el resto */
        a = temporal; /* Prueba con el valor anterior hasta que b sea 0 */
    }
    return a; /* Devuelve el mcd */
}


int pitufi_mezclar(int pitufi_ingrediente1, int pitufi_ingrediente2) {
    int pitufi_final = 0;
    int pitufi_mcd = pitufi_maximo_comun_divisor(pitufi_ingrediente1, pitufi_ingrediente2);
    int pitufi_dis_ingrediente1 = pitufi_ingrediente1 / pitufi_mcd; /* Decremento para que disminuyan hasta 0 al mismo tiempo */
    int pitufi_dis_ingrediente2 = pitufi_ingrediente2 / pitufi_mcd;

    while (pitufi_ingrediente1 != 0) {
        pitufi_ingrediente1 -= pitufi_dis_ingrediente1; 
        pitufi_ingrediente2 -= pitufi_dis_ingrediente2;
        pitufi_final += pitufi_dis_ingrediente1 + pitufi_dis_ingrediente2; /* Aumento de la mezcla */
    }

    pitufi_tiempo();
    return pitufi_final;
}


int pitufi_micro(int pitufi_manteca) { /* Microondas */
    Sleep(PITUFI_MICRO_TIEMPO * PITUFI_MS); /* Tiempo que está la manteca en el microondas */

    return pitufi_manteca;
}


int pitufi_heladera(int pitufi_base[2][2]){ /* Heladera */
    Sleep(PITUFI_HELADERA_TIEMPO * PITUFI_MN); /* Tiempo que está la base en la heladera */
    
    return pitufi_base[2][2];
}


int pitufi_triturar(int pitufi_oreo){ /* Se encarga de hacer polvo las Oreos */
    int pitufi_polvo = 0;
    
    while (pitufi_oreo != 0){ /* Representación de como las Oreos pasan a ser polvo */
        pitufi_oreo--;
        pitufi_polvo++;
    }
    pitufi_tiempo();
    return pitufi_polvo;
}


int pitufi_based(int pitufi_mezcla) {
    int pitufi_base[2][2] = {0}; //Se hace un array bidimensional para indicar la base cuadrada de la torta
    for (int i=0; i<4; i++){
        pitufi_base[i/2][i%2] = pitufi_mezcla/4; /* Se separa la base en 4 secciones representadas con cada dimensión del array */
    }
    
    printf("    La base est%c lista\n\n\
    Dejar la base en la heladera\n", 160);
    pitufi_base[2][2] = pitufi_heladera(pitufi_base); /* Guarda la base en la heladera */
    return pitufi_base[2][2];
}

int pitufi_natar() { /* Se encarga de montar la crema */
    int pitufi_nata_montada = 0;
    int pitufi_nata = PITUFI_NATA;

    while (pitufi_nata != 0) {
        pitufi_nata--;
        pitufi_nata_montada++;
    }
    pitufi_tiempo();
    return pitufi_nata_montada;
}

 
int pitufi_cremar_oreos(int pitufi_crema){
    int pitufi_oreo_crema = PITUFI_OREO_CREMA;
    int pitufi_trituradas = pitufi_triturar(pitufi_oreo_crema); /* Tritura las Mini Oreos */

    printf("    Las Oreos est%cn listos\n\n\
    A%cadir las galletitas a la crema para finalizar el relleno\n\n\
    Esperando el relleno...\n", 160, 164);

    pitufi_tiempo();
    return  pitufi_mezclar(pitufi_trituradas, pitufi_crema); /* Junta las Oreos con la crema */
}


int pitufi_armar(int pitufi_base[2][2], int pitufi_relleno){ /* Une la base de la torta con el relleno */
    int pitufi_torta[2][2][2] = {0}; /* Torta entera representada en un array de 3 dimensiones */
    pitufi_torta[1][2][2] = pitufi_relleno;
    for (int i=0; i<4; i++){
        pitufi_torta[2][i/2][i%2] = pitufi_relleno/4;
    }
    pitufi_tiempo();
    return pitufi_torta[2][2][2];
}

int main() {
    printf("Este programa muestra la receta para armar una torta de Oreo\n");
    printf("    Ingredientes:\n\
        -- BASE --\n\
    -   Oreos: %dg\n\
    -   Manteca: %dg\n\n\
        -- CREMA --\n\
    -   Queso Crema: %dg\n\
    -   Crema (35%% de materia grasa): %dg\n\
    -   Az%ccar Blanca: %dg\n\
    -   Oreos (crema): %dg\n\
    -   Vainilla: 2 cucharadas (%dg apr%cx.)\n\n", \
    PITUFI_OREO, PITUFI_MANTECA, PITUFI_QUESO, PITUFI_NATA, 163, PITUFI_AZUCAR, PITUFI_OREO_CREMA, PITUFI_VAINILLA, 162);
    printf("    Materiales (cant):\n\
    -   Cuchara: %d\n\n\
    -   Batidor: %d\n\
    -   Boul: %d\n\
    -   Molde: %d\n\
    -   Bolsa: %d\n\n", \
    PITUFI_CUCHARA, PITUFI_BATIDOR, PITUFI_BOUL, PITUFI_MOLDE, PITUFI_BOLSA);

    int pitufi_oreo = PITUFI_OREO;

    /* Paso 1 */

    printf("    -- PASO 1 (ENCARGADO: Juani) --\n\
    Trasladar los ingredientes hasta la mesa\n\n\
    Poner las Oreos en la bolsa y triturarlas por completo\n\n\
    Triturando las Oreos...\n");
    int pitufi_polvo = pitufi_triturar(pitufi_oreo); /* Hacer polvo las Oreos */
    printf("    Paso Finalizado\n\n\n");

    /* Paso 2 */

    printf("    -- PASO 2 (ENCARGADO: Iara) --\n\
    Derretir la manteca en el microondas\n\n\
    Esperando la manteca (%d seg como tiempo estimado)...\n", PITUFI_MICRO_TIEMPO);
    int pitufi_manteca_derretida = pitufi_micro(PITUFI_MANTECA); /* Derretir la manteca */
    printf("    La manteca esta lista\n\n\
    Mezclar las Oreos con la manteca derretida\n\n\
    Esperando la mezcla...\n");
    int pitufi_mezcla = pitufi_mezclar(pitufi_polvo, pitufi_manteca_derretida); /* Unir el polvo con la manteca */
    printf("    Paso Finalizado\n\n\n");

    /* Paso 3 */

    printf("    -- PASO 3 (ENCARGADO: Mechi) --\n\
    Extender la mezcla realizada sobre el molde y darle forma con la cuchara\n\n\
    Esperando la base...\n");
    int pitufi_base[2][2] = {0};
    pitufi_base[2][2] = pitufi_based(pitufi_mezcla); /* Extender la mezcla por la base */
    printf("LUZ: Llevar la base hasta el freezer");
    printf("    Paso Finalizado\n\n\n");

    /* Paso 4 */

    printf("    -- PASO 4 (ENCARGADO: Felipe) --\n\
    Batir el queso crema con el azucar utilizando el batidor\n\n\
    Esperando la mezcla...\n");
    int pitufi_quesucar = pitufi_mezclar(PITUFI_QUESO, PITUFI_AZUCAR); /* Paso 4: Mezclar el queso crema con el azúcar */
    printf("    La primera mezcla está lista\n\n\
    Agregar la vainilla a la mezcla\n\n\
    Esperando la mezcla...\n");
    int pitufi_queso_batido = pitufi_mezclar(pitufi_quesucar, PITUFI_VAINILLA); /* Hacer el queso batido juntado la mezcla anterior con vainilla */
    printf("    Paso Finalizado\n\n\n");

    /* Paso 5 */

    printf("    -- PASO 5 (ENCARGADO: Mechi) --\n\
    Montar la crema hasta que est%c firme\n\n\
    Esperando la crema...\n", 130);
    int pitufi_nata_montada = pitufi_natar(PITUFI_NATA); /* Montar la nata */
    printf("    Paso Finalizado\n\n\n");

    /* Paso 6 */

    printf("    -- PASO 6 (ENCARGADO: Luz) --\n\
    Juntar la mezcla realizada con la crema con cuidado para que no se baje esta %cltima\n\n\
    Esperando la mezcla...\n", 163);
    int pitufi_crema = pitufi_mezclar(pitufi_queso_batido, pitufi_nata_montada); /* Juntar el queso batido con la nata montada */
    printf("    Paso Finalizado\n\n\n");

    /* Paso 7 */

    printf("    -- PASO 7 (ENCARGADO: Valen) --\n\
    Partir las Oreos restantes en trocitos usando la mano y unirlas al relleno\n\n\
    Esperando las Oreos...\n");
    int pitufi_relleno = pitufi_cremar_oreos(pitufi_crema); /* Hacer el relleno al unir la crema con las Mini Oreos */
    printf("    Paso Finalizado\n\n\n");

    /* Paso 8 */

    printf("    -- PASO 8 (ENCARGADO: Iara) --\n\
    Sacar la base de la heladera y verterle el relleno. Luego, alisarla bien y meterla en la heladera\n\n\
    Esperando la torta...\n");
    int pitufi_torta = pitufi_armar(pitufi_base, pitufi_relleno); /* Unir el relleno a la base de la torta luego de sacarla de la heladera */
    printf("    Paso Finalizado\n\n\n");

    /* Paso 9 */

    printf("    -- PASO 9 (ENCARGADO: Luz) --\n\
    Hacer una capa de Dulce de Leche para la decoración");
    pitufi_paso_final(); /* Paso 9: El pitufipaso más importante, disfrutar la pitufitorta*/
}
