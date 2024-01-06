#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SZIE 1024

int main()
{
    int fd = open("./hello.txt", O_RDWR);
    if (fd == -1)
    {
        perror("open error");
    }

    char buffer[BUFFER_SZIE];
    memset(buffer, 0, sizeof(buffer));

    read(fd, buffer, sizeof(buffer) - 1);
    printf("buffer:%s\n", buffer);
    close(fd);
    return 0;
}