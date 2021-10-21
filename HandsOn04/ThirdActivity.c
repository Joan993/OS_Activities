#include <stdio.h>
#include <unistd.h> 



int main(void) {

    char *argv[3] = {"find", ".", NULL};
    char * arr[] = {"ls", /*"-l", "-R",*/ "-a", NULL};
    char cwd[50];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Current working dir: %s\n", cwd);
    } else {
        perror("getcwd() error");
        return 1;
    }    

    int pid = fork();

    if ( pid == 0 ) {

    //execvp( "find", argv );
    execv("/bin/ls",arr);

    }
    /* El pare dorm 2 segons (més endavant veure com amb wait podem sincronitzar millor pare i fill*/

    sleep(2);

    printf( "Final del proces pare\n"

    " - el fill no arribarà mai a aquest punt d'execució a causa del recobriment\n" );

    return 0;

}