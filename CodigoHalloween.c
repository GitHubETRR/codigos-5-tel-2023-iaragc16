#include <stdio.h>

#define LONG_NOMBRE 30
#define CANT_DANIOS 3
#define CANT_PODERES 3
#define CANT_MONSTRUOS 5

typedef struct {
    char nombre[LONG_NOMBRE];
    int puntos;
}atributos_t;

typedef struct {
    char nombre[LONG_NOMBRE];
    int vida;
    atributos_t danios[CANT_DANIOS];
    atributos_t poderes[CANT_PODERES];
}monster_t;

void mostrar_monstruos(monster_t[], int);
void mostrar_monstruo(monster_t);

int main (void){
    monster_t monsters[2]={"Pomberito",100,{"DESAPROBAR",100,"ELIMINAR",20,"TOMAR ASISTENCIA",80},
    {"APROBAR",100,"EXPLICAR",100,"PODER1",85}
    };
    int cantidad;
    mostrar_monstruos(monsters, cantidad);
}

void mostrar_monstruos(monster_t monsters[], int cantidad){
    scanf("%d", &cantidad); //otro grupo se encarga de la cantidad
    for (int i=0; i<cantidad; i++){
        mostrar_monstruo(monsters[i]);
    }
}
void mostrar_monstruo(monster_t monster){
    printf("Nombre: %s\n", monster.nombre);  
    printf("vida: %d\n", monster.vida);
    printf("--------------------------\n");
    for(int i=0;i<CANT_DANIOS;i++){
        printf("ataque: %s\nPuntos: %d \n",monster.danios[i].nombre, monster.danios[i].puntos);
    }
    printf("--------------------------\n");
    for (int j=0; j<CANT_PODERES; j++){
        printf("Poder: %s\nPuntos: %d\n", monster.poderes[j].nombre, monster.poderes[j].puntos);
    }
}