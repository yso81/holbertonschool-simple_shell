#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - program that executes the command ls -l /tmp in five child processes
 *
 * Return - Always 0.
 */

int main (void)
{
	char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};
	pid_t pid;
	int i, status;

	for (i = 0; i < 5; i++)
	{
		pid = fork();

		if (pid == -1)
		{
			perror("Error");
			return (1);
		}
		if (pid == 0)
		{
			printf("Child %d is executing\n", i + 1);
				if (execve(argv[0], argv, NULL) == -1)
				{
					perror("Error:");
				}
		}
		else
			wait(&status);
			sleep(3);
	}
	return (0);
}
