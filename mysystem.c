//
// Created by agustin on 8/3/23.
//

#include "mysystem.h"

int mysystem(char* program, char** opt){
    int status;
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
            signal(SIGQUIT,SIG_IGN);

            waitpid(pid, &status, 0);

            signal(SIGINT,SIG_DFL);
            signal(SIGQUIT,SIG_DFL);
    }
    return 0;
}
