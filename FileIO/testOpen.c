#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int main()
{
    /* 打开文件 */
    int fd = open("./hello.txt", O_RDWR, 0644);
    if (fd == -1)
    {
        perror("open error");
    }


    return 0;
}