#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {

    pid_t pid;

    printf("Nonno : creo il figlio. \n");

    pid = fork();

    if (pid < 0) {
        perror("Errore fork");
        exit(-1);
    }
    if (pid == 0) {
        printf("Padre : creo il nipote");
        pid = fork();
        if (pid < 0) {
            perror("Errore fork");
        }
        if ( pid == 0) {
            printf("Nipote Terminato");
            exit(0);
        }
        wait(NULL);
        printf("Padre: il nipote è terminato");
        exit(0);

    }
    wait(NULL);
    printd("Nonno : il figlio è terminato");


    return 0;
}
