#include <stdio.h>

/**
 * main - Entry point
 * @ac: The number of command line arguments
 * @av: An array of pointers to the arguments
 *
 * Description: This program loops through and prints every command line
 * arguments, including the name of the program. Each program is followed by a
 * new line
 *
 * Return: Always 0 (success)
 */
int main(int ac, char **av)
{
	int i;

	for (i = 0; i < ac; i++)
	{
		printf("%s\n", av[i]);
	}
	return (0);
}
