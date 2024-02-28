#include "shell.h"


void configEnv(char **command, int *status)
{
	int j;

	for (j = 0; environ[j]; j++)
	{
		write(STDOUT_FILENO, environ[j], _strlen(environ[j]));
		write(STDOUT_FILENO, "\n", 1);
	}
	(*status) = 0;
	cleanUp2DArray(command);
}
