//
// Created by agustin on 7/19/23.
//

#ifndef SO1_MYSYSTEM_MAIN_H
#define SO1_MYSYSTEM_MAIN_H

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <signal.h>

#define SIZE 64

char* prog;
char* argv[10];
char cmd[SIZE];

int status;

int mysystem(char*, char**);
#endif //SO1_MYSYSTEM_MAIN_H
