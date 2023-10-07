#include <stdio.h>
#include <unistd.h> 
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

int main(void)
{
    int fd;

    fd = open("archivo", O_WRONLY);
    dup2(fd, 1);
    write(1, "hola", 4);
}