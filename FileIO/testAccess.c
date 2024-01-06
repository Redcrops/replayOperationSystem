#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>



int main()
{
    /* F_OK 判断文件是否存在*/
    int ret = access("./heiheihei.c", F_OK);
    if (ret != 0)
    {
        perror("access error");
    }

    return 0;
}