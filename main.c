//
// Created by agustin on 7/19/23.
//

#include <sys/wait.h>
#include "main.h"

int main(){
    printf("Ingrese el comando que desea ejecutar: ");
    fgets(cmd,sizeof(cmd),stdin);

    prog = strtok(cmd, " ");
    argv[0] = prog;

    int i = 1;
    char* token = strtok(NULL," ");
    while(token != NULL){
        argv[i] = token;
        token = strtok(NULL, " ");
        i++;
    }
    argv[i-1]= strtok(argv[i-1],"\n");
    argv[i] = NULL;

    mysystem(prog, argv);
    return 0;
}

int mysystem(char* program, char** opt){
    pid_t pid = fork();

    switch(pid){
        case 0:
            if(execvp(program, opt) == -1){
                fprintf(stderr,"No se pudo ejecutar el comando indicado. %d:%s\n", errno, strerror(errno));
            }
            break;
        case -1:
            fprintf(stderr,"Hubo un fallo durante la creacion del proceso hijo encargador de la ejecucion del comando. %d:%s\n", errno, strerror(errno));
            break;
        default:
            signal(SIGINT,SIG_IGN);
            waitpid(pid, &status, 0);
            signal(SIGINT,SIG_DFL);
    }

    return 0;
}
