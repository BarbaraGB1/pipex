#include <stdio.h>
#include <unistd.h> 
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

int main(void)
{
	int p1[2];
	int p2[2];

	if (pipe(p1) == -1)
		return (1);
	if (pipe(p2) == -1)
		return (1);
	int pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		close(p2[1]);
		close(p1[0]);
		char *x;
		x = calloc(sizeof(char), 10);
		int i = 0;
		int j = 0;
		int new_fd2;
		int nbytes2;
		if((nbytes2 = read(p2[0], x, sizeof(x))) == -1)
			return (1);
		x[nbytes2] = '\0';
		printf("recibo del padre: %s\n", x);
		char *a = "Axel";
		char *str;
		str = malloc(sizeof(char) * (strlen(x) + strlen(a) + 2));
		if (!str)
			return (0);
		while (x[i] != '\0')
		{
			str[i] = x[i];
			i++;
		}
		str[i++] = ' ';
		while (a[j] != '\0')
		{
			str[i] = a[j];
			i++;
			j++;
		}
		str[i] = '\0';
		new_fd2 = open("archivo", O_WRONLY);
		dup2(new_fd2, p1[1]);
		if(write(p1[1], str, strlen(str)) == -1)
			return (1);
		printf("escribo al padre: %s\n", str);
		close(p2[0]);
		close(p1[1]);
	}
	else 
	{
		close(p2[0]);
		close(p1[1]);
		int new_fd1;
		char *rd_txt;
		int nbytes;


		//char *y = "Hola";
		rd_txt = malloc(sizeof(char) * 5);
		new_fd1 = open("txt", O_RDWR);
		nbytes = read(new_fd1, rd_txt, 5);
		rd_txt[nbytes] = '\0';
		printf("Que tiene el texto %s\n", rd_txt);
		if(write(p2[1], rd_txt, sizeof(char) * strlen(rd_txt)) == -1)
			return (1);
		printf("Mando al hijo: %s\n", rd_txt);
/*		char *b;
		b = calloc(sizeof(char), 11);
		if(read(p1[0], b, sizeof(strlen(b))) == -1)
		{
			perror("patata");
			return (1);
		}
		printf("resultado: %s\n", b);*/
		close(p2[1]);
		close(p1[0]);


	
	}
}
