#include <stdio.h>

int main (int argc, char **argv, char **env)
{
	int i;

	i = 0;
	if (argc != 1)
		printf("Hola y %s\n", argv[0]);
	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
}
