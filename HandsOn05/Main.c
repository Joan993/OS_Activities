#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
#include <errno.h>
#include <string.h>
#include "pokemon.h"

#define KNRM "\x1B[0m"
#define KRED "\x1B[31m"
#define KGRN "\x1B[32m"
#define KYEL "\x1B[33m"
#define KBLU "\x1B[34m"
#define KMAG "\x1B[35m"
#define KCYN "\x1B[36m"
#define KWHT "\x1B[37m"
#define MAX_POKEMONS 153

static void throwPokeball();
static void childProcessExit();
static void throwBerry();


Pokemon list_pokemons[MAX_POKEMONS];

int randomNum;
int options[] = {2,4,6,8};
int chance = 1;
int status;

char *args[] = {"pokemon", "pokemon", NULL};

void childProcessExit(){
    exit(11);
}
void throwPokeball(){
    randomNum = (rand() % (10-1+1)) + 1;
    printf("%d \n", randomNum);
    fflush(stdout);
    if(randomNum == 7){
        exit(7);
    } else {
        for ( int i = 0; i < chance; i++){
            if(options[i] == chance){
                exit(2);
            }
        }
        
    }
}
void throwBerry(){
    if(chance < 4){
        chance = chance + 1;
    }
    printf("%d \n", chance);
    fflush(stdout);
}

void pokemons_to_array(){
    FILE* fs = fopen("pokemon.csv", "r");
    char line[1024];
    int count = 0;
    while(fgets(line,sizeof(line), fs)){
        int id = -1;
        char *name = "";
        char **type = malloc(2*sizeof(char*));
        type[0] = "";
        type[1] = "";
        int total = -1;
        int hp = -1;
        int attack = -1;
        int defense = -1;
        int spAttack = -1;
        int spDefense = -1;
        int speed = -1;
        int generation = -1;
        int legendary = -1;
        int seen = 0;
        int captured = 0;
        char* token;
        token = strtok(line,",");
        while(token!=NULL){
            if(id ==-1){
                id = atoi(token);
            } else if(strcmp(name,"")==0){
                name = token;
            } else if(strcmp(type[0],"")==0){
                type[0] = token;
            } else if(strcmp(type[1],"")==0){
                type[1] = token;
            } else if(total == -1){
                total = atoi(token);
            } else if(hp == -1){
                hp = atoi(token);
            } else if(attack == -1){
                attack = atoi(token);
            } else if(defense == -1){
                defense = atoi(token);
            } else if (spAttack == -1){
                spAttack = atoi(token);
            } else if(spDefense == -1){
                spDefense = atoi(token);
            } else if(speed == -1){
                speed = atoi(token);
            } else if(generation == -1){
                generation = atoi(token);
            } else if(legendary == -1){
                legendary = atoi(token);
            }
            token = strtok(NULL, ",");
        }


        Pokemon pok = new_pokemon(id,name,type,total,hp,attack,defense,spAttack,spDefense,speed,generation,legendary,seen,captured);
        list_pokemons[count] = pok;
        count++;
    }
    fclose(fs);
}
Pokemon get_pokemon_list(int numPok){
    Pokemon pok;
    Get_Info_Pokemon(list_pokemons[47]);

    for(int i = 0; i < 151; i++ ){
        if((numPok-1) == i){
            pok = list_pokemons[i];
        }
    }
    Get_Info_Pokemon(list_pokemons[47]);
    return pok;
}

void set_pokemon_position(Pokemon pok, int position){
    list_pokemons[position] = pok;
}


int main(int arc, char *arv[]){
    pokemons_to_array();
    
    int endFlag = 1;
    pid_t ash;
    int value = 0;
    int posibilities[] = {2,4,6,8};
    int chance = 1;
    int num2 = 0;
    
    while(endFlag == 1){

        char s[100];
        char choice;
        int num = 48;
        int numToReturn = 1;
        int value; 
        sprintf(s, "################\n# E. Explore \n# Q. Quit\n################\n");
        if(write(1, s, strlen(s)) < 0){
            perror("Error writting the menu");
        }
        scanf(" %c", &choice);

        switch(choice){
            case 'Q':
                endFlag = 0;
                break;
            case 'E':
                chance = 1;
                signal(SIGUSR1, childProcessExit);
                signal(SIGUSR2, throwPokeball);
                signal(SIGHUP, throwBerry);
                ash = fork();
                if(ash == 0){//Child                  
                    while(1){}  
                } else {//Father
                    int ifExit = 1;
                    num = (rand() % (151-1+1)) + 1;
                    num = num - 1;
                    Pokemon pok = list_pokemons[num];
                    Get_Info_Pokemon(list_pokemons[num]);
                    if(pok.seen == 0){
                        pok.seen = 1;
                        list_pokemons[num] = pok;
                    }
                    while(ifExit == 1){
                        sprintf(s, "################\n# P. Throw Pokeball \n# B. Throw Berry \n# R. Run\n################\n");
                        if (write(1, s, strlen(s)) < 0) perror("Error writting the menu");
                        scanf(" %c", &choice);
                        switch(choice){
                            case 'P':
                                kill(ash, SIGUSR2);
                                break;
                            case 'B':
                                kill(ash, SIGHUP);
                                break;
                            case 'R':
                                kill(ash, SIGUSR1);                                
                                break;
                            default:
                                sprintf(s, "%s!!!!Invalid option. Try again. %s\n", KRED, KNRM);
                                if (write(1, s, strlen(s)) < 0) perror("Error writting invalid option");
                        }
                        if( WIFEXITED(status)){
                            waitpid(ash, &status, WNOHANG); 
                            int es = WEXITSTATUS(status);
                            printf("%d \n", es);
                            fflush(stdout);
                            if(es == 7){
                                ifExit = 0;
                                printf("The pokemon escaped \n");
                                fflush(stdout);
                            } else if( es == 2){
                                ifExit = 0;
                                if(pok.captured == 0){
                                    pok.captured = 1;
                                    list_pokemons[num] = pok;
                                }
                                printf("The pokemon has been captured \n");
                                fflush(stdout);
                            } else {
                                ifExit = 0;                    
                                printf("You escaped succesfully");
                                fflush(stdout);
                            }
                        }
                    }                    
                }
                break;
            default:
                sprintf(s, "%s!!!!Invalid option. Try again. %s\n", KRED, KNRM);
                if (write(1, s, strlen(s)) < 0) perror("Error writting invalid option");
            
        }
    }
    char s[100];
    sprintf(s, "%s!!!!I'm tired from all the fun... %s\n", KMAG, KNRM);
    if(write(1, s, strlen(s)) < 0){
        perror("Error writting the ending msg");
    } 

    exit(0);
}