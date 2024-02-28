#include "shell.h"

int runTask(char **command, char **argv, int idx)
{
	int Mode;
	pid_t chd;
	char *pathCommand = NULL;
	

	pathCommand = getFilePath(command[0]);
	if (!pathCommand)
	{
		displayError(argv[0], idx, command[0]);
		cleanUp2DArray(command);
		return (127);
	}

	chd = fork();
	if (chd == 0)
	{
		if (execve(pathCommand, command, environ) == -1)
		{
			free(pathCommand);
			cleanUp2DArray(command);
		}
	}
	else
	{
		waitpid(chd, &Mode, 0);
		free(pathCommand);
		cleanUp2DArray(command);
	}

	return (WEXITSTATUS(Mode));
}
