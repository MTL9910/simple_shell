#include "shell.h"


void my_env(char **command, int *status)
{
	int j;

	for (j = 0; environ[j]; j++)
	{
		write(STDOUT_FILENO, environ[j], _strlen(environ[j]));
		write(STDOUT_FILENO, "\n", 1);
	}
	(*status) = 0;
	free_2(command);
}
