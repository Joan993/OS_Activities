#include <stdio.h>
#include <string.h>
#include "pokemon.h"



Pokemon new_pokemon(int pokemon_id, char *name, double height, double weight){
    char * name2 = strdup(name);
    Pokemon newP = {pokemon_id,name2,height,weight};
    printf("%d %s %lf %lf \n", pokemon_id,name2,height,weight);
    return newP;
};

int Get_pokemon_id(Pokemon pokemon){
    return pokemon.pokemon_id;
};
char *Get_pokemon_name(Pokemon pokemon){
    return pokemon.name;
};
double Get_pokemon_height(Pokemon pokemon){
    return pokemon.height;
};
double Get_pokemon_weight(Pokemon pokemon){
    return pokemon.weight;
};





