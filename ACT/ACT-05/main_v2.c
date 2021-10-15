#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <libgen.h> 
#include <errno.h>
#include <string.h>
#include <getopt.h>
#include <sys/types.h>
#include "pokedex.h"
#include "pokemon.h"


#define OPTSTR "a:s:r:h:l"
#define WELCOME_MSG (printf("===[ Pokemon Management Service ]===\n\
Welcome to the PMS! How can I help? \n\
=================================================================\n"))
#define USAGE_FMT "%s options: \n\
a [pokemon] [name] [height] [weight] [type1] [type2] \n\
Add a Pokemon to the Pokedex \n\
s [position] \n\
Display details of the Pokemon with position in the pokedex = position \n\
l \n\
Delete the Pokemon with position in the pokedex = position\n\
-help\n"
#define ERR_ADD_POKEMON "add pokemon blew up"
#define ERR_REMOVE_POKEMON "remove pokemon blew up"
#define ERR_SHOW_POKEMON "show pokemon blew up"
#define DEFAULT_PROGNAME "pokemon_management_service"

Pokemon list_pokemons[151];

extern int errno;
int add_pokemon(char *line){
    char *name;
    int pokemon_id;
    double height, weight;
    sscanf(line, "%d %s %lf %lf", &pokemon_id, &*name, &height, &weight);
    printf("%d %s %lf %lf\n", pokemon_id, name,height, weight);
    FILE *fs = fopen("pokemon.csv", "a");
    fprintf(fs, "%d,%s,%lf,%lf\n", pokemon_id, name, height, weight); 
    fclose(fs); 
};

int show_pokemon(int position){
    if(position < sizeof(list_pokemons)){
        if(list_pokemons[position].pokemon_id != NULL){
            printf("%s %s %s \n", Get_pokemon_name(list_pokemons[0]), Get_pokemon_name(list_pokemons[1]), Get_pokemon_name(list_pokemons[2]));
            printf("PokemonID: %d \n Name: %s \n Height: %lf \n Weight: %lf \n", list_pokemons[position].pokemon_id,list_pokemons[position].name,list_pokemons[position].height,list_pokemons[position].weight);            
        }
        return 0;
    } else {
        return -1;
    }
}

int init_pokedex(){
    for (int i = 0; i < sizeof(list_pokemons); i++)
    {
        show_pokemon(i);        
    }
    
}

void pokemons_to_array(){
    FILE* fs = fopen("pokemon.csv", "r");
    char line[1024];
    int count = 0;
    while (fgets(line, sizeof(line), fs)){
        char *name = NULL;
        int pokemon_id = NULL;
        double height = -1; 
        double weight = -1;
        char* token;
        token = strtok(line,",");
        while(token!=NULL){
            if(pokemon_id == NULL){
                pokemon_id = atoi(token);
            } else if (name == NULL){
                name = token;
            } else if (height == -1){
                height = atof(token);
            } else if (weight == -1){
                weight = atof(token);
            }
            token = strtok(NULL, ",");
        }
        Pokemon pok = new_pokemon(pokemon_id,name,height,weight);
        printf("%s --- Recien creado\n", Get_pokemon_name(pok));
        list_pokemons[count] = pok;
        printf("%s --- De la lista\n", Get_pokemon_name(list_pokemons[count]));
        count++;
    }
    fclose(fs);
}
void usage(char *progname, int opt);

int main(int argc, char *argv[]){
    pokemons_to_array();
    int opt;
    opterr = 0;

    WELCOME_MSG;

    while((opt = getopt(argc, argv, OPTSTR)) !=EOF)
        switch (opt){
        case 'a':
            if(add_pokemon(opt) != EXIT_SUCCESS){
                perror(ERR_ADD_POKEMON);
                exit(EXIT_FAILURE);
            }
            break;
        case 's':
            if(show_pokemon(atoi(argv[2])) != EXIT_SUCCESS){
                perror(ERR_SHOW_POKEMON);
                exit(EXIT_FAILURE);
            }
            break;
        case 'l':
            if(init_pokedex() != EXIT_SUCCESS){
                perror(ERR_REMOVE_POKEMON);     
                exit(EXIT_FAILURE);
            }
            break;
        case 'h':
        default:
            usage(basename(argv[0]), opt);
            break;
        }
        return EXIT_SUCCESS;    
}



void usage(char *progname, int opt){
    fprintf(stderr, USAGE_FMT, progname?progname:DEFAULT_PROGNAME);
    exit(EXIT_FAILURE);
}