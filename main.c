//
// Created by agustin on 7/19/23.
//

#include "mysystem.h"

int main(int argc, char* argv[]){
    char* prog;
    char cmd[SIZE];

    while(1){
        memset(cmd, 0, SIZE);
        memset(argv, 0,SIZE);

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
    }

}


