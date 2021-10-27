#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <time.h>
#include <string.h>

int main(){
    int pid, r_net,r_fill;  
    char estat_net[20];
    char estat_fill[20];  
    int value;
    pid = fork();
    if ( pid == 0 ) {
        // child
        pid = fork();
        if ( pid == 0 ) {
            srand(getpid());
            printf("Hola soc en Robb Stark amb pid = %d, soc un fill del matrimoni de la Catelyn Stark i Nedd Stark\n",pid);
            fflush(stdout);
            r_net = (rand() % (1 - 0 + 1)) + 0;
            if( r_net == 0){
                strcpy(estat_net,"apunyalat");
            } else {
                strcpy(estat_net,"decapitat");
            }
            printf("Soc en Robb amb pid = %d i he estat %s \n", pid,estat_net);
            fflush(stdout);
            return r_net;
            // grandchild (of top-level parent)
        } else {
            srand(getpid());
            printf("Hola soc en Nedd fill del matrimoni del Richard i la Lyarra amb pid = %d \n", getpid());
            fflush(stdout);
            wait(&value);
            value = WEXITSTATUS(value);
            r_fill = (rand() % (1 - 0 + 1)) + 0;
            if( r_fill == 0){
                strcpy(estat_fill,"apunyalat");
            } else {
                strcpy(estat_fill,"decapitat");
                value = value + 10;
            }
            printf("Soc en Nedd amb pid = %d i he estat %s \n", getpid(),estat_fill);
            fflush(stdout);
            return value;
            //kill(getpid(), SIGCONT)
            // parent of the grandchild
        }
    } else {
        printf("Hola soc Rickard Stark casat amb Lyarra Stark amb pid = %d \n", getppid());
        fflush(stdout);
        wait(&value);
        int return_value = WEXITSTATUS(value);
        if(return_value == 11){
            printf("En resum el meu fill Robb ha estat decapitat, en Ned decapitat i jo en Rickard amb pid = %d i m’han executat. \n",getppid());
        } else if(return_value == 10){
            printf("En resum el meu fill Robb ha estat apunyalat, en Ned decapitat i jo en Rickard amb pid = %d i m’han executat. \n",getppid());
        } else if(return_value == 1){
            printf("En resum el meu fill Robb ha estat decapitat, en Ned apunyalat i jo en Rickard amb pid = %d i m’han executat. \n",getppid());
        } else if(return_value == 0){
            printf("En resum el meu fill Robb ha estat apunyalat, en Ned apunyalat i jo en Rickard amb pid = %d i m’han executat. \n",getppid());
        }
     // parent
    }

}