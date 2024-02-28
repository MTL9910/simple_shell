#include "shell.h"

char *loadEnvSettings(char *variable)
{
	int j;
	char *code, *env_data, *temp;


	for (j = 0; environ[j]; j++)
	{
		temp = _strdup(environ[j]);
		code = strtok(temp, "=");
		if (_strcmp(code, variable) == 0)
		{
			env_data = _strdup(strtok(NULL, "\n"));
			free(temp);
			return (env_data);
		}
		free(temp);
	}
	return (NULL);
}

void cleanUp2DArray(char **array)
{
	int j;

	if (!array)
		return;

	for (j = 0; array[j]; j++)
	{
		free(array[j]);
		array[j] = NULL;
	}

	free(array), array = NULL;
}

void displayError(char *name, int idx, char *cmd)
{
	char *index, mssg[] = ": not found\n";

	index = _itoa(idx);

	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, _strlen(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, mssg, _strlen(mssg));
	free(index);
}
