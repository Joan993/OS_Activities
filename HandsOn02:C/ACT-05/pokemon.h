#ifndef _POKEMON_H_
#define _POKEMON_H_
    typedef struct pokemon{
        int pokemon_id;
        char *name;
        double height;
        double weight;    
            
    }Pokemon;
Pokemon new_pokemon(int pokemon_id, char *name, double height, double weight);
int Get_pokemon_id(Pokemon pokemon);
char *Get_pokemon_name(Pokemon pokemon);
double Get_pokemon_height(Pokemon pokemon);
double Get_pokemon_weight(Pokemon pokemon);    
#endif
