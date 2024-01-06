#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>


#define BUFFER_SZIE 10

int main()
{
#if 1
    /* 使用lseek来计算文件大小 */
    int fd = open("./hello.txt", O_RDWR);
    if (fd == -1)
    {
        perror("open error");
    }
    
    char buf[BUFFER_SZIE];
    memset(buf, 0, sizeof(buf));
    read(fd, buf, sizeof(buf) - 1);
    printf("buf:%s\n", buf);


    off_t offset = lseek(fd, 0, SEEK_CUR);
    printf("offset:%ld\n", offset);

    #if 0
    /* 缓冲区 */
    char array[] = "hello world";
    write(fd, array, sizeof(array));
    #endif

    #if 0
    read(fd, buf, sizeof(buf) - 1);
    printf("buf:%s\n", buf);
    #endif


    #if 0
    lseek(fd, 30, SEEK_SET);
    char *ptr = "123";
    write(fd, ptr, strlen(ptr));
    #endif

    #if 1
    off_t offset = lseek(fd, 0, SEEK_END);
    printf("offset:%ld\n", offset);
    
    #endif

    close(fd);

#endif

    return 0;
}