#include "shell.h"

char *getpath(char *command)
{
	int j;
	char *path_env, *dir, *PATH_ENV;
	struct stat st;

	for (j = 0; command[j]; j++)
	{
		if (command[j] == '/')
		{
			if (stat(command, &st) == 0)
			{
				path_env = _strdup(command);
				return (path_env);
			}
			return (NULL);
		}
	}
	PATH_ENV = my_getenv("PATH");
	if (PATH_ENV == NULL)
		return (NULL);

	dir = strtok(PATH_ENV, ":");
	while (dir)
	{
		path_env = malloc(_strlen(dir) + _strlen(command) + 2);

		_strcpy(path_env, dir);
		_strcat(path_env, "/");
		_strcat(path_env, command);
		if (stat(path_env, &st) == 0)
		{
			free(PATH_ENV);
			return (path_env);
		}
		free(path_env);
		path_env = NULL;
		dir = strtok(NULL, ":");
	}
	free(PATH_ENV);
	return (NULL);
}
