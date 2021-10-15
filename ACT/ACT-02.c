#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>



long add(long* n1, long* n2){
    long result = *n1 + *n2;

    
    return result;
}

long * add_addr(long*n1, long*n2){
    long *ptr_begin = n1;
    long *ptr_end = n2;
    long *ptr_mid = ptr_begin + (ptr_end - ptr_begin)/2;
    long * result = n1 + *n2;
    return result;
}


int main(int argc, char * argv[]){
    char msg[250];
    long n,m;

    sprintf(msg,"Introdueix un num(n): \n");
    write(1,msg,strlen(msg));
    scanf("%ld", &n);

    sprintf(msg,"Introdueix un num(n): \n");
    write(1,msg,strlen(msg));
    scanf("%ld", &m);

    long res = add(&n,&m);
    
    sprintf(msg,"El resultat de la suma de n=%ld i m=%ld es -> %ld. \n",n,m,res);
    write(1,msg,strlen(msg));

    sprintf(msg,"El resultat de la suma d'@ de &n=%p i &m=%p = %p. \n", &n,&m,add_addr(&n,&m));
    write(1,msg,strlen(msg));

    exit(0);
}
