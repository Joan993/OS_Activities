#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <stdint.h>
#include "pokemon.h"
#define INT2POINTER(a) ((char*)(intptr_t)(a))

Pokemon new_pokemon(int id, char *name, char **type, int total, int hp, int attack, int defense, int spAttack, int spDefense, int speed, int generation, int legendary, int seen, int captured){
    char * new_name = strdup(name);
    char **new_type = malloc(2*sizeof(char*));
    new_type[0] = strdup(type[0]);
    new_type[1] = strdup(type[1]);
    Pokemon newP = {id,new_name,new_type,total,hp,attack,defense,spAttack,spDefense,speed,generation,legendary,seen,captured};
    return newP;
}

void Get_Info_Pokemon(Pokemon pok){
    printf("Pokemon ID: %d  |  Name: %s  |  Tipo 1: %s  |  Tipo 2: %s  |  Total: %d  |  HP: %d  |  Attack: %d \nDefense: %d   |  spAttack: %d  |  spDefense: %d  |  Speed: %d  |  Generation: %d  |  Legendary: %d  |  Seen: %d  |  Captured: %d \n", pok.id,pok.name,pok.type[0],pok.type[1],pok.total,pok.hp,pok.attack,pok.defense,pok.spAttack,pok.spDefense,pok.speed,pok.generation,pok.legendary,pok.seen,pok.captured);
}

void set_seen(Pokemon pok){
    pok.seen = 1;
}
void set_captured(Pokemon pok){
    pok.seen = 1;
}