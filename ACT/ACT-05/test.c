#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pokemon.h"
#include "pokedex.h"


int main(){
    FILE *fs;

    fs = fopen("pokemon.csv", "a");
    if(fs == NULL){
        char *filename="pokemon.csv";
        
        fs=fopen(filename,"w+");
    }
    fclose(fs);
    /*Pokemon pok = new_pokemon(1,"ASD",3,4);
    Pokemon_print(&pok);

    double x = Get_pokemon_height(pok);

    printf("%f", x);*/


/*    char *line = "1 asd 4 5";
    add_pokemon(line);*/

//    init_pokedex();
    show_pokemon(0);    

    return 0;

}

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
    FILE *file = fopen("pokemon.csv", "r");
    int count = 0;
    if ( file != NULL )
    {
        char line[256]; 
        while (fgets(line, sizeof line, file) != NULL){
            if (count == position)
            {
                printf("%s", line);
                fclose(file);
            }
            else
            {
                count++;
            }
        }
        fclose(file);
    }
};

int init_pokedex(){
    FILE* fs = fopen("pokemon.csv", "r");
    char line[1024];
    
    while (fgets(line, sizeof(line), fs)){
        char* token;
        token = strtok(line,",");
        while(token!=NULL){
            printf("%s ", token);
            token = strtok(NULL, ",");
        }
    }
    fclose(fs);
    
};
