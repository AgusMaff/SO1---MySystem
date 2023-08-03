//
// Created by agustin on 8/3/23.
//

#ifndef SO1_MYSYSTEM_MYSYSTEM_H
#define SO1_MYSYSTEM_MYSYSTEM_H
#define SIZE 64

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>

int mysystem(char*, char**);

#endif //SO1_MYSYSTEM_MYSYSTEM_H
