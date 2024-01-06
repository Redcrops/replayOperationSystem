#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <errno.h>


int main()
{
    /* 重命名文件 类似于命令mv */
    int ret = rename("./heiheihei.c", "xixixi.c");
    if (ret == -1)
    {
        perror("rename error");
        return 0;
    }

    return 0;
}