#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main(){
     int p = fork();
     if(p == 0){
         printf("Hola soy el proceso hijo \n");
     } else if(p >= 0){
         printf("Hola soy el proceso padre \n");
     }

}