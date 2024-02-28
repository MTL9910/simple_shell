#ifndef SHELL_H
#define SHELL_H

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>

extern char **environ;

/* getUserInput.c */
char *getUserInput(void);

/* separateLine.c */
char **separateLine(char *line);

/* runTask.c */
int runTask(char **command, char **argv, int idx);

/* tools.c */
char *loadEnvSettings(char *variable);
void cleanUp2DArray(char **array);
void displayError(char *name, int idx, char *cmd);

/* getFilePath.c */
char *getFilePath(char *command);

/* bultins */
void configEnv(char **command, int *status);

/* string.c */
int _strlen(char *s);
char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);

/* more_tools.c */
char *_itoa(int n);
void invertString(char *str, int len);

#endif
