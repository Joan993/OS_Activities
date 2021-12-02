#ifndef _POKEMON_H_
#define _POKEMON_H_
    typedef struct pokemon{
        int id;
        char *name;
        char **type;
        int total;
        int hp;
        int attack;
        int defense;
        int spAttack;
        int spDefense;
        int speed;
        int generation;
        int legendary;
        int seen;
        int captured;
    }Pokemon;
    Pokemon new_pokemon(int id, char *name, char **type, int total, int hp, int attack, int defense, int spAttack, int spDefense, int speed, int generation, int legendary, int seen, int captured);
    void Get_Info_Pokemon(Pokemon pokemon);
    void set_seen(Pokemon pokemon);
    void set_captured(Pokemon pokemon);
#endif