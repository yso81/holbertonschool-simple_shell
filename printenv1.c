#include <stdio.h>

extern char **environ;

int main()
{
	for (char **env = environ; *env != NULL; env++)
	{
		printf("%s\n", *env);
	}
	return (0);
}
