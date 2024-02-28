#include "shell.h"

int exec_cmd(char **command, char **argv, int idx)
{
	int Mode;
	pid_t chd;
	char *pathCommand = NULL;
	

	pathCommand = getpath(command[0]);
	if (!pathCommand)
	{
		print_error(argv[0], idx, command[0]);
		free_2(command);
		return (127);
	}

	chd = fork();
	if (chd == 0)
	{
		if (execve(pathCommand, command, environ) == -1)
		{
			free(pathCommand);
			free_2(command);
		}
	}
	else
	{
		waitpid(chd, &Mode, 0);
		free(pathCommand);
		free_2(command);
	}

	return (WEXITSTATUS(Mode));
}
