#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>



#define BUFFER_SIZE 10

int main()
{
    int fd = open("./testOpen.c", O_RDWR);
    if (fd == -1)
    {
        perror("open error");
    }
    int fdCopy = open("./testOpenCopy.c", O_RDWR | O_CREAT);
    if (fdCopy == -1)
    {
        perror("open error");
    }

    /* 缓冲区 */
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, sizeof(buffer));

    /* 文件打开，那么文件指针就已经在开头. */
    int readLen = 0;
    while(1)
    {
        readLen = read(fd, buffer, BUFFER_SIZE - 1);
        write(fdCopy, buffer, readLen);
        if (readLen < BUFFER_SIZE - 1 || readLen == 0)
        {
            break;
        }
    }

    /* 关闭文件 */
    close(fd);
    close(fdCopy);

    return 0;
}

