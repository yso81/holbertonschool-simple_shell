#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	pid_t pid;
	int status;

	while (1)
	{
		printf("$ ");
		read = getline(&line, &len, stdin);

		if (read == -1)
		{
			printf("\n");
			break;
		}
		while (read > 0 && (line[read - 1] == '\n' || line[read - 1] == '\r'))
		line[--read] = '\0';

		if (read == 0)
			continue;
		pid = fork();
		if (pid == -1)
		{
			perror("Error");
			return (1);
		}
		if (pid == 0)
		{
			char *argv[] = {line, NULL};

			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error:");
			}
		}
		else
		{
			wait(&status);
		}
		free(line);
		return (0);
	}
}
