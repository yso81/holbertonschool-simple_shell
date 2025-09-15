#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[] = "Hello world!";
	char *token = strtok(str, " /t/n");

	while (token != NULL)
	{
		printf(" %s\n", token);
		token = strtok(NULL, " /t/n");
	}
	return (0);
}
